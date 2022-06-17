/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 01:22:04 by msosnova          #+#    #+#             */
/*   Updated: 2021/11/24 10:35:15 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;

	if (n > 0 && (dst != src))
	{
		if (src > dst)
			ft_memcpy (dst, src, n);
		else
		{
			new_dst = (unsigned char *)dst;
			new_src = (unsigned char *)src;
			while (n-- > 0)
			{
				new_dst[n] = new_src[n];
			}
		}
	}
	return (dst);
}
