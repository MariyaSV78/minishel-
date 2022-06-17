/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:57:28 by msosnova          #+#    #+#             */
/*   Updated: 2022/03/10 00:46:59 by tjudlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*alloc(t_shell *shell, int start, int i)
{
	char	*tmp_line;

	tmp_line = (char *)ft_calloc(sizeof(char), i - start + 1);
	if (!tmp_line)
	{
		perror("MS: ");
		g_error = errno;
		ft_exit(shell);
	}
	ft_strlcpy(tmp_line, ((shell->line) + start), i - start + 1);
	return (tmp_line);
}

char	*ft_is_quotes_var(int *i, t_shell *shell)
{
	char	quote;
	int		start;
	char	*tmp_line;

	quote = shell->line[*i];
	start = (*i)++;
	while (shell->line[*i] != quote && shell->line[*i])
		(*i)++;
	if (!shell->line[*i])
	{
		g_error = 126;
		printf("MS: syntax error: miss quote\n");
		return (0);
	}
	else
	{
		(*i)++;
		tmp_line = alloc(shell, start, *i);
	}
	if (quote == '\'')
		return (tmp_line);
	else
		return (ft_insert_vars(shell, tmp_line));
}

void	extract_var(t_shell *shell, char **out_line, int *start, int *i)
{
	char	*tmp_line;

	if (shell->line[*i] != '\'' && shell->line[*i] != '"')
		(*i)++;
	else
	{
		tmp_line = (char *)ft_calloc((*i - *start + 1), sizeof(char));
		if (!tmp_line)
		{
			perror("MS: ");
			g_error = errno;
			ft_exit(shell);
		}
		ft_strlcpy(tmp_line, shell->line + *start, *i - *start + 1);
		if (ft_poschar(tmp_line, '$') > -1)
			tmp_line = ft_insert_vars(shell, tmp_line);
		*out_line = ft_join_str(*out_line, tmp_line);
		tmp_line = ft_is_quotes_var(i, shell);
		*out_line = ft_join_str(*out_line, tmp_line);
		*start = *i;
	}
}

void	ft_is_var(t_shell *shell)
{
	int		i;
	int		start;
	char	*tmp_line;
	char	*out_line;

	out_line = NULL;
	start = 0;
	i = 0;
	while (shell->line[i])
		extract_var(shell, &out_line, &start, &i);
	if (start < i)
	{
		tmp_line = (char *)ft_calloc(i - start + 1, sizeof(char));
		if (!tmp_line)
			ft_merror(shell, errno, "MS: memory allocation");
		ft_strlcpy(tmp_line, shell->line + start, i - start + 1);
		if (ft_poschar(tmp_line, '$') > -1)
			tmp_line = ft_insert_vars(shell, tmp_line);
		out_line = ft_join_str(out_line, tmp_line);
	}
	free(shell->line);
	shell->line = out_line;
}
