/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 00:29:15 by msosnova          #+#    #+#             */
/*   Updated: 2021/11/24 10:34:50 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *a, int c, size_t len)
{
	size_t	i;
	char	ch;
	char	*a_transform;

	ch = (char)c;
	i = 0;
	a_transform = (char *)a;
	while (i < len)
	{
		a_transform[i] = ch;
		i++;
	}
	return (a);
}
