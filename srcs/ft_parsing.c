/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:15:36 by msosnova          #+#    #+#             */
/*   Updated: 2022/03/10 16:13:21 by tjudlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"

void	if_quotes(int	*i, t_shell	*shell, t_lpars *token)
{
	char	*tmp_line;
	int		j;

	tmp_line = ft_is_quotes(i, shell);
	if (shell->is_error)
		return ;
	if (shell->is_space == 0)
	{
		j = ft_args_last(token);
		token->args[j] = ft_join_str(token->args[j], tmp_line);
	}
	else
	{
		token->args = ft_add_arg(token->args, tmp_line);
		shell->is_space = 0;
	}
}

void	if_arg(int	*i, t_shell	*shell, t_lpars *token)
{
	char	*tmp_line;
	int		j;

	tmp_line = ft_is_arg(shell, i);
	if (shell->is_space == 0)
	{
		j = ft_args_last(token);
		token->args[j] = ft_join_str(token->args[j], tmp_line);
	}
	else
	{
		token->args = ft_add_arg(token->args, tmp_line);
		shell->is_space = 0;
	}
}

int	if_pipe_error(int *i, t_shell *shell, t_lpars **token)
{
	if (shell->line[(*i) + 1] == '|')
	{
		g_error = 2;
		shell->is_error++;
		printf("MS: syntax error near unexpected token `||' \n");
		return (1);
	}
	if (shell->line[(*i) + 1] == '\0')
	{
		g_error = 2;
		shell->is_error++;
		printf("MS: syntax error near unexpected token `|' \n");
		return (1);
	}
	*token = ft_lst_add_back(*token, ft_new_lst(shell));
	(*i)++;
	shell->is_space = 1;
	return (0);
}

void	if_pars(int *i, t_shell *shell, t_lpars **token)
{
	if (shell->line[*i] == '<' || shell->line[*i] == '>' )
	{
		if (!ft_is_redirect(shell, shell->line, i, *token))
		{
			shell->is_error++;
			return ;
		}
	}
	else if (shell->line[*i] == '"' || shell->line[*i] == '\'' )
		if_quotes (i, shell, *token);
	else if (shell->line[*i] == '|')
	{
		if (if_pipe_error(i, shell, token))
			return ;
	}
	else if (shell->line[*i] != ' ' && shell->line[*i] != '\t')
		if_arg(i, shell, *token);
	else
	{
		shell->is_space = 1;
		(*i)++;
	}
	if (!shell->is_error)
		if ((*token)->redirect_1 == 2 && (*token)->file_1 != NULL)
			ft_is_heredoc((*token)->file_1, *token, shell);
}

void	ft_parsing(t_shell *shell)
{
	int		i;
	t_lpars	*token;

	token = ft_new_lst(shell);
	shell->first_token = token;
	if (ft_poschar(shell->line, '$') > -1)
		ft_is_var(shell);
	i = 0;
	shell->is_space = 1;
	while (shell->line[i] && shell->is_error == 0)
	{
		if_pars(&i, shell, &token);
		if (shell->is_error)
			return ;
	}
	//ft_print_lst(token);
}
