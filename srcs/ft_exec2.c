/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjudlin <tjudlin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:46:40 by tjudlin           #+#    #+#             */
/*   Updated: 2022/03/10 22:33:20 by tjudlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_single_exec(t_shell *shell)
{
	int	res;

	res = -2;
	ft_get_fd_redirect(shell->first_token);
	ft_dup2(shell->first_token);
	shell->first_token->args[0] = ft_tolower2(shell->first_token->args[0]);
	res = ft_execute_bi(shell, shell->first_token);
	return (res);
}

int	ft_dupfdcmd(t_lpars *cmd)
{
	if (cmd->redirect_1 != 0)
		;
	else if (cmd->prev != 0 && cmd->prev->redirect_2 == 0)
		cmd->fd1 = cmd->prev->pipe[0];
	else
		cmd->fd1 = STDIN_FILENO;
	if (cmd->redirect_2 != 0)
		;
	else if (cmd->next != 0 && cmd->next->redirect_1 == 0)
		cmd->fd2 = cmd->pipe[1];
	else
		cmd->fd2 = STDOUT_FILENO;
	return (ft_dup2(cmd));
}

char	*ft_tolower2(char *txt)
{
	size_t	i;

	if (ft_poschar(txt, '=') == -1)
	{
		i = -1;
		while (++i < ft_strlen(txt))
			txt[i] = ft_tolower(txt[i]);
	}
	return (txt);
}

int	ft_dup2(t_lpars *cmd)
{
	if (cmd->fd1 != 0)
	{
		if (dup2(cmd->fd1, STDIN_FILENO) < 0)
		{
			perror("Dup2: ");
			return (errno);
		}
	}
	if (cmd->fd2 != 1)
	{
		if (dup2(cmd->fd2, STDOUT_FILENO) < 0)
		{
			perror("Dup2: ");
			return (errno);
		}
	}
	return (0);
}

void	ft_execute_ve(t_shell *shell, t_lpars *cmd)
{
	int		i;
	char	**paths;
	char	*exe0;
	char	*exe;

	i = -1;
	g_error = execve(cmd->args[0], cmd->args, shell->envp);
	paths = ft_get_paths(cmd, shell);
	while (paths[++i])
	{
		exe0 = ft_strjoin("/", cmd->args[0]);
		exe = ft_strjoin(paths[i], exe0);
		free(exe0);
		exe0 = 0;
		g_error = execve(exe, cmd->args, shell->envp);
		free(exe);
	}
	ft_freetab2(paths);
	ft_errormsg(cmd->args[0], "", ": Command not found.\n");
	g_error = 127;
	ft_exit(shell);
}
