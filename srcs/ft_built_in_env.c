/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjudlin <tjudlin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:04:39 by tjudlin           #+#    #+#             */
/*   Updated: 2022/03/10 16:48:44 by tjudlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*ft_built_in_pwd(void)
{
	char	*cwd;

	cwd = NULL;
	cwd = (char *)ft_calloc(sizeof(char), PATH_MAX + ft_strlen("PWD=") + 1);
	if (cwd == NULL)
		return (NULL);
	ft_strlcat(cwd, "PWD=", 5);
	if (getcwd(&cwd[4], PATH_MAX) == NULL)
		perror("getcwd()");
	return (cwd);
}

int	ft_bi_env2(t_shell *shell)
{
	int	i;

	i = -1;
	while (shell->envp2 && shell->envp2[++i] != 0)
		printf("%s%s\n", "export ", shell->envp2[i]);
	return (0);
}

int	ft_built_in_env(t_shell *shell, t_lpars *cmd, int exp)
{
	int	i;

	i = -1;
	if (exp == 0 && cmd->args[1])
	{
		ft_errormsg(cmd->args[0], cmd->args[1], " : No such file - directory\n");
		exit(127);
	}
	else
	{
		while (shell->envp && shell->envp[++i] != 0)
		{
			if (exp == 1)
				printf("%s", "export ");
			printf("%s\n", shell->envp[i]);
		}
	}
	return (0);
}

int	ft_get_env(char *str, t_shell *shell, int len)
{
	int	i;

	i = -1;
	if (len == -1)
		len = ft_strlen(str);
	while (shell->envp && shell->envp[++i])
	{
		if (ft_strncmp(str, shell->envp[i], len) == 0 && \
		shell->envp[i][len] == '=')
			return (i);
	}
	return (-1);
}

int	ft_get_env2(char *str, t_shell *shell, int len)
{
	int	i;

	i = -1;
	if (len == -1)
		len = ft_strlen(str);
	while (shell->envp2 && shell->envp2[++i])
	{
		if (ft_strncmp(str, shell->envp2[i], len) == 0 && \
		shell->envp2[i][len] == '=')
			return (i);
	}
	return (-1);
}
