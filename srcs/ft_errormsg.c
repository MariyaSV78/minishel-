/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errormsg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:02:18 by msosnova          #+#    #+#             */
/*   Updated: 2022/03/10 21:37:56 by tjudlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

void	ft_errormsg(char *arg0, char *arg1, char *msg)
{
	if (arg1 != 0)
		printf("MS: %s : %s - %s", arg0, arg1, msg);
	else
		printf("MS: %s - %s", arg0, msg);
}

//treatment of the memory allocation error
void	ft_merror(t_shell *shell, int i, char *str)
{
	perror(str);
	g_error = i;
	ft_exit (shell);
}

void	ft_merror2(int i, char *str)
{
	perror(str);
	g_error = i;
	exit (i);
}
