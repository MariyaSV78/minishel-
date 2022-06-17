/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 01:57:59 by msosnova          #+#    #+#             */
/*   Updated: 2022/02/10 01:58:30 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*ft_malloc(int *i, t_shell *shell, int start)
{
	char	*tmp_line;

	tmp_line = (char *)malloc(sizeof(char) * (*i - start + 1));
	if (!tmp_line)
	{
		perror("MS:");
		g_error = errno;
		ft_exit(shell);
	}
	return (tmp_line);
}

char	*ft_is_quotes(int *i, t_shell *shell)
{
	char	quote;
	int		start;
	char	*tmp_line;

	tmp_line = NULL;
	quote = shell->line[*i];
	shell->heredoc_varign = 1;
	start = ++(*i);
	while (shell->line[*i] != quote && shell->line[*i])
		(*i)++;
	if (!shell->line[*i])
	{
		g_error = 126;
		printf("MS: s: syntax error\n");
		shell->is_error++;
		return (NULL);
	}
	else
	{
		tmp_line = ft_malloc(i, shell, start);
		ft_strlcpy(tmp_line, ((shell->line) + start), *i - start + 1);
		(*i)++;
	}
	return (tmp_line);
}
