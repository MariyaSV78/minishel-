/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_vars2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:07:11 by msosnova          #+#    #+#             */
/*   Updated: 2022/03/10 14:14:58 by tjudlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*ft_get_var(char *line, int *i)
{
	int		start;
	char	*tmp_line;

	tmp_line = NULL;
	if (line[*i] == ' ' || line[*i] == '\t' || line[*i] == '"' || \
	line[*i] == '\'')
		return (tmp_line);
	start = *i;
	while ((ft_isalnum(line[*i]) > 0 || line[*i] == '_') && line[*i])
		(*i)++;
	tmp_line = (char *)malloc(sizeof(char) * (*i - start + 1));
	if (!tmp_line)
		exit(0);
	ft_strlcpy(tmp_line, line + start, *i - start + 1);
	return (tmp_line);
}

char	*ft_get_sepvar(char *line, int *i, char ch1, char ch2)
{
	int		start;
	char	*tmp_line;

	tmp_line = NULL;
	if (line[*i] != ch1)
		return (tmp_line);
	start = ++(*i);
	while (line[*i] != ch2 && line[*i])
		(*i)++;
	if (!line[*i])
	{
		g_error = 2;
		printf("MS: s: syntax error\n");
		return (0);
	}
	else
	{
		tmp_line = ft_calloc(sizeof(char), *i - start + 1);
		if (!tmp_line)
			ft_merror2(errno, "MS: memory allocation");
		ft_strlcpy(tmp_line, line + start, *i - start + 1);
		(*i)++;
	}
	return (tmp_line);
}

char	*ft_put_var(char *out_line, char *var_name, char *rest, t_shell *shell)
{
	int		pos;

	pos = ft_get_env(var_name, shell, -1);
	if (pos != -1)
		out_line = ft_join_str(out_line, ft_strdup(shell->envp[pos] + \
		ft_poschar(shell->envp[pos], '=') + 1));
	else
	{
		pos = ft_get_env2(var_name, shell, -1);
		if (pos != -1)
			out_line = ft_join_str(out_line, ft_strdup(shell->envp2[pos] + \
			ft_poschar(shell->envp2[pos], '=') + 1));
	}
	out_line = ft_join_str(out_line, ft_strdup(rest));
	return (out_line);
}

int	check_parentheses(t_shell *shell, char *split, char **out_line, int *i)
{
	char	*var_name;

	var_name = ft_get_sepvar(split, i, '[', ']');
	if (!var_name)
	{
		var_name = ft_get_sepvar(split, i, '{', '}');
		if (!var_name)
		{
			var_name = ft_get_sepvar(split, i, '(', ')');
			if (var_name)
			{
				printf("MS: %s command not found\n", var_name);
				shell->is_error++;
			}
		}
	}
	if (var_name)
	{
		*out_line = ft_put_var(*out_line, var_name, split + *i, shell);
		free(var_name);
		return (1);
	}
	return (0);
}
