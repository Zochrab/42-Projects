/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_assign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgramsch <sgramsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:19:59 by sgramsch          #+#    #+#             */
/*   Updated: 2024/12/05 12:19:59 by sgramsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_token	*duplicate(t_data *data, t_token *token)
{
	t_token	*dup;

	dup = malloc(sizeof(t_token));
	if (!dup)
		exit_on_error(data, MEM, 1, 1);
	if (token->str)
		dup->str = ft_strdup(token->str);
	else
		dup->str = ft_strdup("");
	dup->original = ft_strdup(token->original);
	dup->quotes = token->quotes;
	dup->env = token->env;
	dup->delimiter = token->delimiter;
	return (dup);
}

void	add_token_to_cmd(t_data *data, t_cmd_list *cmd, t_token *token)
{
	t_token	*last;
	t_token	*dup;

	dup = duplicate(data, token);
	dup->next = NULL;
	if (cmd->name_token == NULL)
	{
		cmd->name_token = dup;
		dup->prev = NULL;
		return ;
	}
	last = lst_token_last(cmd->first_token);
	if (!last)
	{
		dup->prev = NULL;
		cmd->first_token = dup;
	}
	else
	{
		dup->prev = last;
		last->next = dup;
	}
}

int	is_empty(t_token *token)
{
	if (token->env)
	{
		if (!token->str || token->str[0] == '\0')
			return (1);
	}
	return (0);
}

static int	is_re_or_pipe(t_token *token)
{
	return (is_redirectional(token->next->str, token->next)
		|| is_pipe(token->next->str, token->next));
}

int	assign_tokens(t_data *data, t_token *token, t_cmd_list *cmd)
{
	while (token && cmd)
	{
		if (!cmd->name_token && is_empty(token))
		{
			token = token->next;
			continue ;
		}
		if (is_redirectional(token->str, token))
		{
			if (token->next && is_re_or_pipe(token))
				return (exit_on_error(data,
						"parsing error near Redirectional Argument", 0, 2));
		}
		if (is_pipe(token->str, token))
		{
			if (token->next && is_pipe(token->next->str, token->next))
				return (exit_on_error(data,
						"parsing error near unexpected token |", 0, 2));
			cmd = cmd->next;
		}
		else
			add_token_to_cmd(data, cmd, token);
		token = token->next;
	}
	return (0);
}
