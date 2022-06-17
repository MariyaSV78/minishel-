/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 09:26:02 by msosnova          #+#    #+#             */
/*   Updated: 2021/06/15 07:15:00 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

/*order of number */
long int	ft_order(size_t nb)
{
	long int	order;

	order = 1;
	while (nb > 9)
	{
		nb /= 10;
		order++;
	}
	return (order);
}

char	*ft_itoa(int nb)
{
	long int	long_nb;
	int			order;
	int			is_sign;
	char		*new_str;

	long_nb = nb;
	is_sign = 0;
	if (long_nb < 0)
	{
		is_sign = 1;
		long_nb = -long_nb;
	}
	order = ft_order(long_nb);
	new_str = malloc((is_sign + order + 1) * sizeof(char));
	if (!new_str)
		return (new_str);
	if (is_sign)
		new_str[0] = '-';
	new_str[is_sign + order] = '\0';
	while (order-- > 0)
	{
		new_str[is_sign + order] = (char)(long_nb % 10) + '0';
		long_nb /= 10;
	}
	return (new_str);
}
