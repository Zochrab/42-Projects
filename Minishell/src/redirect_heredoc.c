/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:04:48 by sgramsch          #+#    #+#             */
/*   Updated: 2024/12/10 12:55:39 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*edit_heredoc(t_data *data, char *in, t_token *delimiter)
{
	t_var	*var;

	var_init(data);
	var = data->var;
	while (in[var->pos])
	{
		if (in[var->pos] == '$' && !delimiter->quotes)
			env_expanding(data, var, in);
		var->pos ++;
	}
	if (var->start < var->pos)
	{
		var->end = var->pos - 1;
		add_normal(data, in, var);
	}
	free(in);
	in = var->new;
	var->new = NULL;
	var = free_var(data);
	return (in);
}

void	non_interactive_heredoc_loop(t_data *data, t_cmd_list *cmd, char *in)
{
	while (in && ft_strncmp(in, cmd->input_argument->str,
			ft_strlen(cmd->input_argument->str)) != 0)
	{
		if (cmd->input_argument->quotes == 0 && in != NULL)
			in = edit_heredoc(data, in, cmd->input_argument);
		if (in != NULL)
			write(cmd->heredoc_pipe[1], in, ft_strlen(in));
		if (in)
			free(in);
		in = NULL;
		in = get_next_line(STDIN_FILENO);
		if (in == NULL)
		{
			write(cmd->heredoc_pipe[1], "\n", 1);
			break ;
		}
		write(cmd->heredoc_pipe[1], "\n", 1);
		if (in[ft_strlen(in) - 1] == '\n')
			in[ft_strlen(in) - 1] = '\0';
	}
	if (ft_strncmp(in, cmd->input_argument->str,
			ft_strlen(cmd->input_argument->str)) != 0)
		cmd->eof = 1;
	if (in)
		free(in);
}

void	interactive_heredoc_loop(t_data *data, t_cmd_list *cmd)
{
	char	*in;

	set_signal_heredoc();
	in = readline("heredoc> ");
	if (heredoc_checker(data, in, cmd) == 1)
	{
		free(in);
		return ;
	}
	while (ft_strncmp(in, cmd->input_argument->str,
			ft_strlen(cmd->input_argument->str)) != 0)
	{
		if (cmd->input_argument->quotes == 0)
			in = edit_heredoc(data, in, cmd->input_argument);
		write(cmd->heredoc_pipe[1], in, ft_strlen(in));
		write(cmd->heredoc_pipe[1], "\n", 1);
		free(in);
		set_signal_heredoc();
		in = readline("heredoc> ");
		set_signals_noninteractive();
		if (heredoc_checker(data, in, cmd) == 1)
			break ;
	}
	free(in);
}

void	heredoc_loop(t_data *data, t_cmd_list *cmd)
{
	char	*in;

	if (!isatty(STDIN_FILENO))
	{
		in = NULL;
		in = get_next_line(STDIN_FILENO);
		if (in && in[ft_strlen(in) - 1] == '\n')
			in[ft_strlen(in) - 1] = '\0';
		non_interactive_heredoc_loop(data, cmd, in);
		return ;
	}
	else
		interactive_heredoc_loop(data, cmd);
}
