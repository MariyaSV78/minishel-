/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:34:06 by msosnova          #+#    #+#             */
/*   Updated: 2022/03/07 14:21:11 by tjudlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char	**ft_add_arg(char **args, char *tmp_line)
{
	char	**arg_new;
	int		i;

	if (!tmp_line)
		return (args);
	i = 0;
	if (args)
		while (args[i])
			i++;
	arg_new = (char **)ft_calloc(sizeof(char *), i + 2);
	if (!arg_new)
	{
		perror("MS: memory allocation error");
		exit(0);
	}
	arg_new[i + 1] = NULL;
	arg_new[i] = tmp_line;
	while (--i >= 0)
		arg_new[i] = args[i];
	free(args);
	return (arg_new);
}

char	*ft_join_str(char *s1, char *s2)
{
	char			*new_chaine;
	unsigned int	i;
	unsigned int	j;
	size_t			len_1;
	size_t			len_2;

	len_1 = ft_strlen (s1);
	len_2 = ft_strlen (s2);
	new_chaine = (char *)ft_calloc(len_1 + len_2 + 20, sizeof(char));
	if (!new_chaine)
		return (NULL);
	i = 0;
	j = 0;
	while (j < len_1)
		new_chaine[i++] = s1[j++];
	j = 0;
	while (j < len_2)
		new_chaine[i++] = s2[j++];
	free(s1);
	free(s2);
	s2 = 0;
	s1 = 0;
	return (new_chaine);
}

int	ft_strcmp(const char *str_1, const char *str_2)
{
	size_t	i;

	if (ft_strlen(str_1) != ft_strlen(str_2))
		return (0);
	i = 0;
	while (str_1[i])
	{
		if (str_1[i] != str_2[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_args_last(t_lpars *tokens)
{
	int	j;

	j = 0;
	while (tokens->args[j])
		j++;
	if (j > 0)
		return (j - 1);
	return (0);
}
