/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjudlin <tjudlin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:39:06 by tjudlin           #+#    #+#             */
/*   Updated: 2022/03/07 15:22:41 by tjudlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_sighandler(int i)
{
	if (i == SIGINT)
	{
		g_error = 130;
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (i == SIGQUIT)
	{
		printf("Quit\n");
		exit (1);
	}
}

void	ft_sighandler2(int i)
{
	if (i == SIGINT)
	{
		g_error = 130;
		printf("\n");
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (i == SIGQUIT)
	{
		g_error = 131;
		printf("Quit\n");
	}
}

void	ft_init_signal(void)
{
	signal(SIGINT, ft_sighandler);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_init_signal2(void)
{
	signal(SIGINT, ft_sighandler2);
	signal(SIGQUIT, ft_sighandler2);
}
