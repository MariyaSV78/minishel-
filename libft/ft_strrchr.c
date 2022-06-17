/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 02:19:10 by msosnova          #+#    #+#             */
/*   Updated: 2021/06/07 13:10:20 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t	len;

	len = ft_strlen (str);
	if (ch == '\0')
		return ((char *)str + len);
	while (len)
	{
		if (str[len - 1] == (char)ch)
			return ((char *)(str + len - 1));
		len--;
	}
	return (NULL);
}
