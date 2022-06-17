/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:05:03 by msosnova          #+#    #+#             */
/*   Updated: 2022/02/24 10:07:04 by tjudlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	skip_whites(char *line, int *i)
{
	while (line[*i] == ' ' || line[*i] == '\t')
		(*i)++;
}

int	count_redirections(char *line, int *i, char redirect)
{
	int		n_redirect;

	n_redirect = 1;
	while (line[*i] == redirect)
	{
		n_redirect++;
		(*i)++;
	}
	if (n_redirect > 2 && !line[*i])
	{
		printf("MS: syntax error near unexpected token `%c%c`\n",
			redirect, redirect);
		g_error = 2;
		return (0);
	}
	skip_whites(line, i);
	if (line[*i] == '<' || line[*i] == '>')
	{
		printf("MS: syntax error near unexpected token `%c`\n", redirect);
		g_error = 2;
		return (0);
	}
	return (n_redirect);
}

int	set_redirections(t_lpars *token, char *line, char redirect, int n_redirect)
{
	int		fd;

	if (redirect == '<')
	{
		token->redirect_1 = n_redirect;
		if (n_redirect == 1 && access(line, R_OK) != 0)
		{
			printf("MS: %s: No such file or directory\n", line);
			g_error = 1;
			return (1);
		}
		token->file_1 = line;
	}
	else
	{
		token->redirect_2 = n_redirect;
		if (n_redirect == 1)
			fd = open(line, O_CREAT | O_WRONLY | O_TRUNC, 0777);
		else
			fd = open(line, O_CREAT | O_WRONLY | O_APPEND, 0777);
		close(fd);
		free(token->file_2);
		token->file_2 = line;
	}
	return (0);
}

int	ft_is_redirect(t_shell *shell, char *line, int *i, t_lpars *last_token)
{
	char	redirect;
	int		n_redirect;
	char	*tmp_line;

	tmp_line = NULL;
	redirect = line[(*i)++];
	n_redirect = count_redirections(line, i, redirect);
	if (!n_redirect)
		return (0);
	else if (line[*i] == '"' || line[*i] == '\'')
		tmp_line = ft_join_str(tmp_line, ft_is_quotes(i, shell));
	else if (line[*i] != ' ' && line[*i] != '\t' && line[*i])
		tmp_line = ft_join_str(tmp_line, ft_is_arg(shell, i));
	if (set_redirections(last_token, tmp_line, redirect, n_redirect))
		return (0);
	if ((last_token->redirect_1 != 0 && last_token->file_1 == 0)
		|| (last_token->redirect_2 != 0 && last_token->file_2 == 0))
	{
		printf("MS: syntax error near unexpected token `newline'\n");
		g_error = 2;
		return (0);
	}
	return (1);
}
