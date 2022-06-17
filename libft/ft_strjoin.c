/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 08:29:07 by msosnova          #+#    #+#             */
/*   Updated: 2021/06/06 08:48:43 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new_chaine;
	unsigned int	i;
	unsigned int	j;
	size_t			len_1;
	size_t			len_2;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len_1 = ft_strlen (s1);
	len_2 = ft_strlen (s2);
	new_chaine = (char *)malloc((len_1 + len_2 + 1) * sizeof(char));
	if (!new_chaine)
		return (NULL);
	while (j < len_1)
		new_chaine[i++] = s1[j++];
	j = 0;
	while (j < len_2)
		new_chaine[i++] = s2[j++];
	new_chaine[i] = '\0';
	return (new_chaine);
}
