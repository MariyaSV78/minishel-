/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 09:00:20 by msosnova          #+#    #+#             */
/*   Updated: 2022/03/10 21:32:55 by tjudlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

/*allocation memory for a new table */
void	ft_alloc_memory(char const *s, char c, char ***new_tableau)
{
	size_t	i;
	size_t	n_chaines;

	i = 0;
	n_chaines = 0;
	while (s[i])
	{
		if (s[i] == c)
			n_chaines++;
		i++;
	}
	*new_tableau = (char **)ft_calloc(n_chaines + 2, sizeof(char *));
}

/*fill a table */
void	ft_filltab(char **new_tableau, char const *s, char c)
{
	size_t	i;
	size_t	k;
	char	*next_c;

	i = 0;
	if (s[0] == c)
		new_tableau [i++] = ft_calloc(1, 1);
	k = 0;
	while (s[k])
	{
		if (s[k] != c)
		{
			next_c = ft_strchr(&s[k], c);
			if (!next_c)
				next_c = ft_strchr(&s[k], '\0');
			new_tableau [i++] = ft_substr(s, k, next_c - s - k);
			k = next_c - s;
		}
		else
			k++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**new_tableau;

	if (!s)
		return (NULL);
	ft_alloc_memory (s, c, &new_tableau);
	if (!new_tableau)
		return (NULL);
	ft_filltab(new_tableau, s, c);
	return (new_tableau);
}
