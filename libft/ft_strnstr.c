/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 02:25:53 by msosnova          #+#    #+#             */
/*   Updated: 2021/11/24 10:32:51 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	l_find;
	size_t	i;

	if (!*find)
		return ((char *)str);
	l_find = ft_strlen(find);
	i = 0;
	while (str[i] && len >= l_find)
	{
		if (ft_strncmp(str + i, find, l_find) == 0)
			return ((char *)str + i);
		i++;
		len--;
	}
	return (NULL);
}
