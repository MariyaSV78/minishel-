/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 01:15:52 by msosnova          #+#    #+#             */
/*   Updated: 2021/11/24 10:38:04 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *a, size_t len)
{
	size_t	i;
	char	*a_transform;

	i = 0;
	a_transform = (char *)a;
	while (i < len)
	{
		a_transform[i] = '\0';
		i++;
	}
}
