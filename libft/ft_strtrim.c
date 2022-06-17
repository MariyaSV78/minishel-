/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 08:50:50 by msosnova          #+#    #+#             */
/*   Updated: 2021/06/06 08:58:28 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

/*find the char in the set */
int	ft_char_in_set(char s, const char *set)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (s == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	char	*new_chaine;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s)
		return (NULL);
	end = ft_strlen(s);
	start = 0;
	while (s[start] && ft_char_in_set(s[start], set))
		start++;
	while (end > start && ft_char_in_set(s[end - 1], set))
		end--;
	new_chaine = (char *)malloc((end - start + 1) * sizeof(char));
	if (!new_chaine)
		return (NULL);
	i = 0;
	while (start + i < end)
	{
		new_chaine[i] = s[start + i];
		i++;
	}
	new_chaine[i] = '\0';
	return (new_chaine);
}
