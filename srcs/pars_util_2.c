/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_util_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 01:16:55 by msosnova          #+#    #+#             */
/*   Updated: 2022/03/10 11:58:42 by tjudlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	tab_len(char **args)
{
	int		i;

	i = 0;
	if (args)
		while (args[i])
			i++;
	return (i);
}

char	**ft_copy_tab2(char **args)
{
	char	**arg_new;
	int		i;
	size_t	len;

	i = tab_len(args);
	arg_new = (char **)ft_calloc(sizeof(char *), i + 1);
	if (!arg_new)
	{
		perror("MS: ");
		g_error = errno;
		exit(errno);
	}
	while (--i >= 0)
	{
		len = ft_strlen(args[i]);
		arg_new[i] = (char *)ft_calloc(sizeof(char), len + 1);
		if (!arg_new[i])
		{
			free(arg_new);
			arg_new = 0;
			ft_merror2(errno, "MS: memory allocation");
		}
		ft_strlcpy(arg_new[i], args[i], len + 1);
	}
	return (arg_new);
}
