/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 09:44:00 by msosnova          #+#    #+#             */
/*   Updated: 2021/06/06 14:26:50 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int i, char n))
{
	unsigned int	i;
	size_t			len;
	char			*new_chaine;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	new_chaine = (char *)malloc ((len + 1) * sizeof(char));
	if (!new_chaine)
		return (NULL);
	while (i < len)
	{
		new_chaine[i] = f(i, s[i]);
		i++;
	}
	new_chaine[i] = '\0';
	return (new_chaine);
}
