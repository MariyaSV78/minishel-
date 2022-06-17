/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 02:21:01 by msosnova          #+#    #+#             */
/*   Updated: 2021/11/24 10:33:15 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *str_1, const char *str_2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)str_1[i] > (unsigned char)str_2[i])
			return (1);
		if ((unsigned char)str_1[i] < (unsigned char)str_2[i])
			return (-1);
		if (str_1[i] == 0)
			break ;
		i++;
	}
	return (0);
}
