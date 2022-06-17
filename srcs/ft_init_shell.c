/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:27:07 by msosnova          #+#    #+#             */
/*   Updated: 2022/03/10 17:56:59 by tjudlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_shell	*ft_init_shell(char **environ)
{
	t_shell	*shell;

	shell = malloc(sizeof(t_shell));
	if (!shell)
	{
		perror("shell:");
		exit(0);
	}
	shell->line = NULL;
	shell->line_args = NULL;
	shell->envp = ft_copy_tab2(environ);
	shell->envp2 = NULL;
	shell->nb_cmd = 0;
	shell->first_token = NULL;
	shell->tmp_line = 0;
	shell->is_error = 0;
	shell->heredoc_varign = 0;
	g_error = 0;
	return (shell);
}
