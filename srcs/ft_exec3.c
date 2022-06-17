/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjudlin <tjudlin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:26:00 by tjudlin           #+#    #+#             */
/*   Updated: 2022/03/10 21:44:54 by tjudlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_get_fd_redirect(t_lpars *cmd)
{
	if (cmd->redirect_1 != 0)
		ft_get_fd(cmd, 1);
	if (cmd->redirect_2 != 0)
		ft_get_fd(cmd, 2);
}

int	ft_execute_bi(t_shell *shell, t_lpars *cmd)
{
	char		*exe;

	if (ft_strncmp(cmd->args[0], "pwd", 4) == 0)
	{
		exe = ft_built_in_pwd();
		printf("%s\n", exe);
		free(exe);
		exe = 0;
		return (0);
	}
	else if (ft_strncmp(cmd->args[0], "env", 4) == 0)
		return (ft_built_in_env(shell, cmd, 0));
	else if (ft_strncmp(cmd->args[0], "cd", 3) == 0)
		return (ft_built_in_cd(cmd->args[1], shell));
	else if (ft_strncmp(cmd->args[0], "export", 7) == 0)
		return (ft_bi_exp(shell, cmd));
	else if (ft_strncmp(cmd->args[0], "unset", 6) == 0)
		return (ft_built_in_unset0(shell, cmd, -1));
	else if (ft_strncmp(cmd->args[0], "echo", 5) == 0)
		return (ft_built_in_echo(cmd));
	else if (ft_strncmp(cmd->args[0], "exit", 5) == 0)
		ft_built_in_exit(shell, cmd);
	else if ((ft_built_in_var(shell, cmd)) == 0)
		return (0);
	return (-1);
}

char	**ft_get_paths(t_lpars *cmd, t_shell *shell)
{
	int		pos;
	char	**paths;

	pos = ft_get_env("PATH", shell, -1);
	if (pos == -1)
	{
		ft_errormsg(cmd->args[0], " ", "No such file or directory\n");
		exit(127);
	}
	else
		paths = (ft_split(shell->envp[pos] + 5, ':'));
	return (paths);
}

int	ft_is_bi(t_lpars *cmd)
{
	if (ft_strncmp(cmd->args[0], "cd", 3) == 0)
		return (1);
	else if (ft_strncmp(cmd->args[0], "unset", 6) == 0)
		return (2);
	else if (ft_strncmp(cmd->args[0], "export", 7) == 0)
		return (3);
	else if (ft_poschar(cmd->args[0], '=') > 0)
		return (4);
	else if (ft_strncmp(cmd->args[0], "exit", 5) == 0)
		return (5);
	else if (ft_strncmp(cmd->args[0], "pwd", 3) == 0)
		return (6);
	else
		return (0);
}
