/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjudlin <tjudlin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:58:50 by tjudlin           #+#    #+#             */
/*   Updated: 2022/03/10 22:02:55 by tjudlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_get_fd(t_lpars *cmd, int cas)
{
	if (cas == 1)
	{
		cmd->fd1 = open(cmd->file_1, O_RDONLY);
		if (cmd->fd1 < 0)
		{
			perror("FD error :");
			return (errno);
		}
	}
	if (cas == 2)
	{
		if (cmd->redirect_2 == 1)
			cmd->fd2 = open(cmd->file_2, O_CREAT | O_WRONLY | O_TRUNC, 0777);
		else
			cmd->fd2 = open(cmd->file_2, O_CREAT | O_WRONLY | O_APPEND, 0777);
		if (cmd->fd2 < 0)
		{
			perror("FD error :");
			return (errno);
		}
	}
	return (0);
}

void	ft_close_p(t_lpars *cmdi, t_lpars *cmd)
{
	if (cmdi->next != 0 && cmdi->next->redirect_1 == 0)
		close(cmdi->pipe[0]);
	if (cmdi->prev != 0 && cmd->prev->redirect_2 == 0)
		close(cmdi->prev->pipe[1]);
	if (cmdi->redirect_1 != 0)
		close(cmdi->fd1);
	if (cmdi->redirect_2 != 0)
		close(cmdi->fd2);
}

void	ft_child_fun(t_shell *shell, t_lpars *cmd)
{
	int		res;
	t_lpars	*cmdi;

	g_error = ft_dupfdcmd(cmd);
	if (g_error == 0)
	{
		cmdi = shell->first_token;
		while (cmdi != cmd->next)
		{
			ft_close_p(cmdi, cmd);
			cmdi = cmdi->next;
		}
		cmd->args[0] = ft_tolower2(cmd->args[0]);
		res = -2;
		res = ft_execute_bi(shell, cmd);
		if (res == -1)
			ft_execute_ve(shell, cmd);
		ft_exit(shell);
		g_error = 0;
		exit(EXIT_SUCCESS);
	}
	ft_exit(shell);
	exit(g_error);
}

void	ft_close_wait(t_shell *shell)
{
	t_lpars	*cmd;
	int		status;

	cmd = shell->first_token;
	while (cmd != 0)
	{
		if (cmd->pipe[0] != 0)
		{
			close(cmd->pipe[0]);
			close(cmd->pipe[1]);
		}
		ft_init_signal2();
		cmd = cmd->next;
	}
	cmd = shell->first_token;
	while (cmd != 0)
	{
		waitpid(cmd->pid, &status, 0);
		if (WIFEXITED(status))
			g_error = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			g_error = 128 + WTERMSIG(status);
		cmd = cmd->next;
	}
}

void	ft_multpipes(t_shell *shell)
{
	t_lpars	*cmd;

	cmd = shell->first_token;
	while (cmd != 0)
	{
		cmd->pipe[0] = 0;
		cmd->pipe[1] = 0;
		if (cmd->next != 0 && cmd->redirect_2 == 0 && \
		cmd->next->redirect_1 == 0)
			pipe(cmd->pipe);
		ft_get_fd_redirect(cmd);
		cmd->pid = fork();
		if (cmd->pid < 0)
			return (perror("Fork: "));
		if (cmd->pid == 0)
		{
			signal(SIGQUIT, ft_sighandler2);
			ft_child_fun(shell, cmd);
		}
		cmd = cmd->next;
	}
	ft_close_wait(shell);
}
