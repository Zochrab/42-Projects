/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgramsch <sgramsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:24:54 by sgramsch          #+#    #+#             */
/*   Updated: 2024/10/29 14:24:54 by sgramsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	get_full_input_line(t_data *data)
{
	if (g_signal == SIGINT || g_signal == SIGQUIT)
		data->status = 128 + g_signal;
	set_signals_interactive();
	data->input = readline(PROMPT);
	set_signals_noninteractive();
	if (data->input == NULL)
		exit_on_error(data, "", 1, data->status);
	if (catch(data, 0))
		return ;
	else if (last_pipe(data->input))
		pipe_loop(data, NULL);
}

void	tget_full_input_line(t_data *data)
{
	if (g_signal == SIGINT || g_signal == SIGQUIT)
		data->status = 128 + g_signal;
	data->input = read_new();
	if (data->input == NULL)
		return ;
	if (first_pipe(data->input))
	{
		free(data->input);
		data->input = NULL;
		data->status = exit_on_error(data, "Syntax Error", 1, 2);
	}
	else if (unclosed(data->input))
	{
		free(data->input);
		data->input = NULL;
		data->status = exit_on_error(data, "Unclosed quotes", 1, 2);
	}
}

void	non_interactive_shell(t_data *data)
{
	while (1)
	{
		data->parent = 0;
		tget_full_input_line(data);
		if (g_signal == SIGINT || g_signal == SIGQUIT)
			data->status = 128 + g_signal;
		if (is_blank(data->input))
		{
			small_cleanup(data);
			continue ;
		}
		if (data->input == NULL)
		{
			small_cleanup(data);
			return ;
		}
		add_history(data->input);
		data->command_count = cmd_count(data->input);
		if (input_setup(data) != 1 && data->dont == 0)
			create_subshell(data);
		else if (data->dont == 0)
			data->status = 2;
		small_cleanup(data);
	}
}

void	interactive_shell(t_data *data)
{
	while (1)
	{
		data->parent = 0;
		get_full_input_line(data);
		if (g_signal == SIGINT || g_signal == SIGQUIT)
			data->status = 128 + g_signal;
		if (data->input == NULL || is_blank(data->input))
		{
			small_cleanup(data);
			continue ;
		}
		add_history(data->input);
		data->command_count = cmd_count(data->input);
		if (input_setup(data) != 1 && data->dont == 0)
			create_subshell(data);
		else if (data->dont == 0)
			data->status = 2;
		small_cleanup(data);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;
	int		status;

	set_up_data(&data, envp, argc, argv);
	if (!isatty(STDIN_FILENO))
		non_interactive_shell(&data);
	else
		interactive_shell(&data);
	status = data.status;
	cleanup(&data);
	return (status);
}
