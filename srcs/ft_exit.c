/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:56:13 by msosnova          #+#    #+#             */
/*   Updated: 2022/03/10 21:17:57 by tjudlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_exit(t_shell *shell)
{
	rl_clear_history();
	if (shell)
	{
		if (shell->first_token)
			ft_lst_clear(shell, shell->first_token);
		if (shell->envp)
			ft_freetab2(shell->envp);
		if (shell->envp2)
			ft_freetab2(shell->envp2);
		if (shell->line_args)
			free(shell->line_args);
		if (shell->tmp_line)
			free(shell->tmp_line);
		if (shell->line)
			free(shell->line);
		free(shell);
	}
	exit(g_error);
}
