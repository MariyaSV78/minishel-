/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjudlin <tjudlin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:21:02 by tjudlin           #+#    #+#             */
/*   Updated: 2022/02/09 13:25:52 by tjudlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_freetab2(char **tab)
{
	int	i;

	if (tab)
	{
		i = -1;
		while (tab[++i] != 0)
			free(tab[i]);
		free(tab);
	}
}

static int	ft_wordcnt(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != 0)
			i++;
		j++;
	}
	return (j);
}

char	**gettab(char const *s, char c)
{
	char	**tab;

	if (s == 0)
		exit(EXIT_FAILURE);
	tab = ((char **)malloc((ft_wordcnt(s, c) + 1) * sizeof(char *)));
	if (tab == 0)
		exit(EXIT_FAILURE);
	return (tab);
}

/*char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = -1;
	tab = gettab(s, c);
	while (s[i] != 0)
	{
		while (s[i] == c)
			i++;
		j = 0;
		while (s[i + j] != c && s[i + j] != 0)
			j++;
		if (j != 0)
		{
			(tab[++k] = ft_dup(s, i, j));
			if (tab[k] == 0)
				ft_freetab(tab, k);
		}
		i = i + j;
	}
	tab[k + 1] = 0;
	return (tab);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	j = -1;
	str = (char *)malloc(sizeof(str) * i);
	if (str == 0)
		return (0);
	i = -1;
	while (s1[++j] != 0)
		str[j] = s1[j];
	while (s2[++i] != 0)
		str[j + i] = s2[i];
	str[i + j] = 0;
	return (str);
}*/
