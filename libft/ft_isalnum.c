/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 01:52:34 by msosnova          #+#    #+#             */
/*   Updated: 2021/06/06 01:53:04 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int n)
{
	unsigned char	ch;

	ch = (unsigned char)n;
	if (ch >= '0' && ch <= '9')
		return (4);
	if (ch >= 'a' && ch <= 'z')
		return (2);
	if (ch >= 'A' && ch <= 'Z')
		return (1);
	return (0);
}
