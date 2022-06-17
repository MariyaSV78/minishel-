/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 02:06:43 by msosnova          #+#    #+#             */
/*   Updated: 2022/03/10 21:52:38 by tjudlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_non_int(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	ft_built_in_exit(t_shell *shell, t_lpars *tokens)
{
	printf("exit\n");
	if (tokens->args[1])
	{
		if (ft_non_int(tokens->args[1]))
		{
			printf("MS: exit: %s numeric argument required\n", tokens->args[1]);
			g_error = 2;
		}
		else
			g_error = ft_atoi(tokens->args[1]);
	}
	ft_exit(shell);
}
