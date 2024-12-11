/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:27:19 by zblume            #+#    #+#             */
/*   Updated: 2023/11/21 12:31:38 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*c;
	t_list	*n;

	if (lst && del)
	{
		c = *lst;
		while (c)
		{
			n = c->next;
			ft_lstdelone(c, del);
			c = n;
		}
		*lst = NULL;
	}
}
