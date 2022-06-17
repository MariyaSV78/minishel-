/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_export.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjudlin <tjudlin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:03:04 by tjudlin           #+#    #+#             */
/*   Updated: 2022/03/10 00:38:43 by tjudlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_onlychar(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=' && (ft_isalnum(str[i]) > 0 || str[i] == '_'))
		i++;
	if (str[i] != '=' && str[i] != 0)
		return (1);
	return (0);
}

int	ft_bi_exp(t_shell *shell, t_lpars *cmd)
{
	int	i;

	i = 0;
	if (cmd->args[1] == 0)
		return (ft_built_in_env(shell, 0, 1));
	while (cmd->args[++i])
	{
		if (ft_onlychar(cmd->args[i]) == 1 || cmd->args[i][0] == '=')
		{
			ft_errormsg("export", cmd->args[i], " : not a valid identifier\n");
			return (1);
		}
	}
	i = 0;
	while (cmd->args[++i])
		ft_built_in_export(shell, cmd->args[i]);
	return (0);
}

void	ft_built_in_export(t_shell *shell, char *arg)
{
	int	pos;
	int	pos2;

	pos2 = ft_poschar(arg, '=');
	pos = ft_get_env2(arg, shell, -1);
	if (pos2 > 0)
	{
		pos = ft_get_env(arg, shell, pos2);
		if (pos != -1)
			ft_built_in_unset(shell, arg, pos);
		shell->envp = ft_add_arg(shell->envp, ft_strdup(arg));
	}
	else if (pos != -1)
	{
		ft_built_in_export(shell, shell->envp2[pos]);
		ft_built_in_unvar(shell, arg, pos);
	}
}

int	ft_built_in_var(t_shell *shell, t_lpars *cmd)
{
	int	pos;
	int	pos2;

	pos2 = ft_poschar(cmd->args[0], '=');
	if (pos2 > 0)
	{
		pos = ft_get_env(cmd->args[0], shell, pos2);
		if (ft_onlychar(cmd->args[0]) == 1)
		{
			g_error = 1;
			ft_errormsg(cmd->args[0], "", ": not a valid identifier\n");
		}
		else if (pos != -1)
			ft_built_in_export(shell, cmd->args[0]);
		else
		{
			pos = ft_get_env2(cmd->args[0], shell, pos2);
			if (pos != -1)
				ft_built_in_unvar(shell, cmd->args[0], pos);
			shell->envp2 = ft_add_arg(shell->envp2, ft_strdup(cmd->args[0]));
		}
		return (0);
	}
	return (-1);
}

int	ft_built_in_unset(t_shell *shell, char *arg, int pos)
{
	if (pos == -1)
		pos = ft_get_env(arg, shell, -1);
	if (pos == -1)
		ft_built_in_unvar(shell, arg, pos);
	if (pos != -1)
	{
		free(shell->envp[pos]);
		shell->envp[pos] = 0;
		while (shell->envp[++pos])
			shell->envp[pos - 1] = shell->envp[pos];
		shell->envp[pos - 1] = 0;
		return (0);
	}
	return (1);
}
