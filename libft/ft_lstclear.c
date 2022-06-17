/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 06:48:47 by msosnova          #+#    #+#             */
/*   Updated: 2021/06/15 06:48:55 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nextlst;

	while (*lst)
	{
		nextlst = (*lst)->next;
		if (del)
		{
			del((*lst)->content);
			free(*lst);
		}
		*lst = nextlst;
	}
}
