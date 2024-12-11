/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:51:19 by zblume            #+#    #+#             */
/*   Updated: 2024/12/10 12:51:19 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	to_print(t_env *tmp)
{
	while (tmp)
	{
		if (tmp->printed == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_env	*get_smal(t_env *env)
{
	t_env	*smal;

	smal = NULL;
	while (env)
	{
		if (!smal && !env->printed)
			smal = env;
		else if (!env->printed && ft_strncmp(smal->name,
				env->name, ft_strlen(smal->name)) > 0)
			smal = env;
		env = env->next;
	}
	if (smal)
		smal->printed = 1;
	return (smal);
}

void	reset_print(t_env *env)
{
	while (env)
	{
		env->printed = 0;
		env = env->next;
	}
}
