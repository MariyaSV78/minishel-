/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:20:21 by msosnova          #+#    #+#             */
/*   Updated: 2022/03/06 22:12:34 by tjudlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	change_cat(t_shell *shell, t_lpars *token, char *out_line)
{
	if (ft_strcmp(token->args[0], "cat"))
	{
		free(token->args[0]);
		token->args[0] = ft_strdup("echo");
		if (!shell->heredoc_varign)
			out_line = ft_insert_vars(shell, out_line);
		token->args = ft_add_arg(token->args, out_line);
	}
	else
		free(out_line);
}

void	add_text(char **out_line, char *tmp_line)
{
	if (*out_line == NULL)
		*out_line = ft_strdup(tmp_line);
	else
		*out_line = ft_join_str(*out_line, ft_strjoin("\n", tmp_line));
	free(tmp_line);
}

int	ft_is_heredoc(char *heredoc, t_lpars *last_token, t_shell *shell)
{
	char	*tmp_line;
	char	*out_line;

	out_line = NULL;
	while (1)
	{
		tmp_line = readline("> ");
		if (tmp_line == NULL)
			return (0);
		if (ft_strcmp(tmp_line, heredoc))
		{
			free(tmp_line);
			break ;
		}
		add_text(&out_line, tmp_line);
	}
	if (tab_len(last_token->args) == 1)
		change_cat(shell, last_token, out_line);
	else
		free(out_line);
	last_token->redirect_1 = 0;
	shell->heredoc_varign = 0;
	g_error = 0;
	return (1);
}
