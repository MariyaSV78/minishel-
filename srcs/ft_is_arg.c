/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:25:40 by msosnova          #+#    #+#             */
/*   Updated: 2022/02/17 10:59:47 by tjudlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	if_is_wordend(char *line, int *i)
{
	if (line[*i] && line[*i] != ' '
		&& line[*i] != '\t' && line[*i] != '<' && line[*i] != '>'
		&&line[*i] != '"' && line[*i] != '\'' && line[*i] != '|')
		return (1);
	else
		return (0);
}

char	*ft_is_arg(t_shell *shell, int *i)
{
	int		start;
	char	*tmp_line;

	start = *i;
	while (if_is_wordend(shell->line, i))
		(*i)++;
	tmp_line = (char *)malloc(sizeof(char) * (*i - start + 1));
	if (!tmp_line)
	{
		perror("MS:");
		ft_exit(shell);
	}
	ft_strlcpy(tmp_line, shell->line + start, *i - start + 1);
	return (tmp_line);
}
