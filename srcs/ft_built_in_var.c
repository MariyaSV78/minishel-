/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjudlin <tjudlin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 00:37:06 by tjudlin           #+#    #+#             */
/*   Updated: 2022/03/10 22:50:34 by tjudlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_built_in_unset0(t_shell *shell, t_lpars *cmd, int pos)
{
	int	i;

	i = 0;
	while (cmd->args[++i])
		ft_built_in_unset(shell, cmd->args[i], pos);
	return (0);
}

int	ft_built_in_unvar(t_shell *shell, char *arg, int pos)
{
	if (pos == -1)
		pos = ft_get_env2(arg, shell, -1);
	if (pos != -1)
	{
		free(shell->envp2[pos]);
		shell->envp2[pos] = 0;
		while (shell->envp2[++pos])
			shell->envp2[pos - 1] = shell->envp2[pos];
		shell->envp2[pos - 1] = 0;
		return (0);
	}
	else
		return (1);
}

int	ft_old_pwd(t_shell *shell, int oldpwd, int pwd)
{
	char	*n_old;

	oldpwd = 0;
	n_old = (char *)ft_calloc(sizeof(char), \
	PATH_MAX + ft_strlen("OLDPWD=") + 1);
	if (n_old == NULL)
	{
		perror("alloc()");
		return (errno);
	}
	free(shell->envp[oldpwd]);
	shell->envp[oldpwd] = 0;
	ft_strlcat(n_old, "OLD", 4);
	if (ft_strlcpy(&n_old[3], shell->envp[pwd], \
	ft_strlen(shell->envp[pwd]) + 4) == 0)
	{
		perror("copy()");
		return (errno);
	}
	shell->envp[oldpwd] = n_old;
	return (0);
}

int	ft_built_in_cd(char *path, t_shell *shell)
{
	int		oldpwd;
	int		pwd;
	int		j;

	j = 0;
	pwd = 0;
	if (chdir(path) != 0)
	{
		perror("MS: unknown path");
		return (1);
	}
	else
	{
		pwd = ft_get_env("PWD", shell, -1);
		oldpwd = ft_get_env("OLDPWD", shell, -1);
		if (oldpwd != -1 && pwd != 0)
			j = ft_old_pwd(shell, oldpwd, pwd);
		if (pwd != -1)
		{
			free(shell->envp[pwd]);
			shell->envp[pwd] = ft_built_in_pwd();
		}
		return (j);
	}
}

int	ft_poschar(char	*str, char c)
{
	int	i;

	i = 0;
	if (str == 0)
		return (-1);
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == 0)
		return (-1);
	return (i);
}
