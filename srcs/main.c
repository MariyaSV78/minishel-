/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 04:20:54 by msosnova          #+#    #+#             */
/*   Updated: 2022/03/10 22:15:31 by tjudlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	g_error;

void	ft_execution(t_shell *shell)
{
	if (ft_error(shell))
	{
		if (shell->first_token->next || ft_is_bi(shell->first_token) == 0)
			ft_multpipes(shell);
		else
			g_error = ft_single_exec(shell);
	}
}

void	ft_ext_main(t_shell *shell)
{
	ft_lst_clear(shell, shell->first_token);
	if (shell->line)
		free(shell->line);
	if (shell->line_args)
		free(shell->line_args);
	if (shell->tmp_line)
		free(shell->tmp_line);
}

int	main(int ac, char **av, char **environ)
{
	t_shell	*shell;

	if (ac != 1 || !av)
		return (0);
	shell = ft_init_shell(environ);
	ft_init_signal();
	while (1)
	{
		ft_init_signal();
		shell->line = readline("minishell$> ");
		if (shell->line == NULL)
		{
			printf("\nExit\n");
			ft_exit(shell);
		}
		add_history(shell->line);
		shell->is_error = 0;
		ft_parsing(shell);
		ft_execution(shell);
		ft_ext_main(shell);
	}
}
