/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:50:40 by zblume            #+#    #+#             */
/*   Updated: 2024/12/10 12:50:40 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	catch(t_data *data, int i)
{
	if (i == 0 && first_pipe(data->input))
	{
		free(data->input);
		data->input = NULL;
		data->status = exit_on_error(data, "Syntax Error", 0, 2);
		return (1);
	}
	else if (unclosed(data->input))
	{
		free(data->input);
		data->input = NULL;
		printf("\033[31mInvalid input. Close quotes please!\n\033[0m");
		return (1);
	}
	return (0);
}

int	unclosed(char *str)
{
	int	pos;
	int	single;
	int	duble;

	pos = 0;
	single = 0;
	duble = 0;
	while (str[pos])
	{
		if (str[pos] == '\'')
		{
			if (duble % 2 == 0)
				single ++;
		}
		else if (str[pos] == '\"')
		{
			if (single % 2 == 0)
				duble ++;
		}
		pos ++;
	}
	if (single % 2 != 0 || duble % 2 != 0)
		return (1);
	return (0);
}

int	last_pipe(char *str)
{
	int	pos;

	if (!str)
		return (0);
	pos = ft_strlen(str) - 1;
	while (pos >= 0 && str[pos])
	{
		if (str[pos] == '|')
			return (1);
		else if (!is_whitespace(str[pos]))
			return (0);
		pos --;
	}
	return (0);
}

int	first_pipe(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos])
	{
		if (str[pos] == '|')
			return (1);
		else if (!is_whitespace(str[pos]))
			return (0);
		pos ++;
	}
	return (0);
}

void	pipe_loop(t_data *data, char *in)
{
	while (last_pipe(data->input))
	{
		set_signal_heredoc();
		in = readline(">");
		set_signals_noninteractive();
		if (g_signal == SIGINT)
		{
			if (in)
				free(in);
			if (data->input)
				free(data->input);
			data->input = NULL;
			return ;
		}
		if (in == NULL)
			exit_on_error(data, ENOF, 1, data->status);
		else if (first_pipe(in))
		{
			data->input = join(data->input, in);
			break ;
		}
		data->input = join(data->input, in);
	}
	catch(data, 1);
}
