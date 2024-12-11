/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expanding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgramsch <sgramsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:15:49 by sgramsch          #+#    #+#             */
/*   Updated: 2024/12/05 12:15:49 by sgramsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	env_sub_expand(t_data *data, t_var *var, char *str)
{
	if (str[var->pos + 1] == '$')
		add_shell_pid(data, var);
	else if (str[var->pos + 1] == '?')
		add_exit_status(data, var);
	else if (str[var->pos + 1] == '-')
	{
		var->end = var->pos + 1;
		var->start = var->end + 1;
		var->pos ++;
		if (isatty(STDIN_FILENO))
			var->new = join(var->new, ft_strdup("ih"));
		else
			var->new = join(var->new, ft_strdup("h"));
	}
	else if (str[var->pos + 1] == '0')
	{
		var->end = var->pos + 1;
		var->start = var->end + 1;
		var->pos ++;
		var->new = join(var->new, ft_strdup("minishell"));
	}
	else
		switch_env(data, var, str);
}

void	env_expanding(t_data *data, t_var *var, char *str)
{
	if (str[var->pos + 1] == '\0'
		|| is_whitespace(str[var->pos + 1]) == 1 || var->sq)
	{
		var->end = var->pos;
		add_normal(data, str, var);
		return ;
	}
	else
	{
		var->end = var->pos -1;
		add_normal(data, str, var);
	}
	env_sub_expand(data, var, str);
	var->env = 1;
}
