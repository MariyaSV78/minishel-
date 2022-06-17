/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_vars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:47:09 by msosnova          #+#    #+#             */
/*   Updated: 2022/03/07 14:27:02 by tjudlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	add_dol(char **out_line, char *split, int n)
{
	if (n > 0)
		*out_line = ft_join_str(ft_join_str(*out_line, ft_strdup("$")), \
		ft_strdup(split));
	else
		*out_line = ft_join_str(*out_line, ft_strdup(split));
}

char	*put_var(t_shell *shell, char *out_line, char *split, int n)
{
	int		i;
	char	*var_name;

	var_name = NULL;
	i = 0;
	if (!check_parentheses(shell, split, &out_line, &i) && split[0] == '?')
	{
		out_line = ft_join_str(out_line, ft_itoa(g_error));
		out_line = ft_join_str(out_line, ft_strdup(split + 1));
	}
	else
	{
		var_name = ft_get_var(split, &i);
		if (n > 0 && var_name)
			out_line = ft_put_var(out_line, var_name, split + i, shell);
		else
			add_dol(&out_line, split, n);
	}
	free(var_name);
	return (out_line);
}

char	*ft_insert_vars(t_shell *shell, char *str)
{
	char	**split;
	int		n;
	char	*out_line;

	out_line = NULL;
	n = -1;
	split = ft_split(str, '$');
	while (split[++n])
		out_line = put_var(shell, out_line, split[n], n);
	if (str[ft_strlen(str)-1] == '$')
	{
		if (!out_line)
			out_line = ft_strdup("$");
		else
			out_line = ft_join_str(out_line, ft_strdup("$"));
	}
	free(str);
	ft_freetab2(split);
	return (out_line);
}
