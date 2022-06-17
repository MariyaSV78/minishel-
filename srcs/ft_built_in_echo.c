/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_echo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:29:08 by msosnova          #+#    #+#             */
/*   Updated: 2022/03/10 22:54:20 by tjudlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_check_n(char *str)
{
	int	i;

	if (str)
	{
		if (ft_strlen(str) >= 2)
		{
			if (str[0] == '-' && str[1] == 'n')
			{
				i = 2;
				while (str[i] == 'n')
					i++;
				if (!str[i])
					return (1);
			}
		}
	}
	return (0);
}

int	ft_built_in_echo(t_lpars *cmd)
{
	int	i;
	int	j;

	i = 1;
	j = ft_check_n(cmd->args[1]);
	if (j > 0)
		i++;
	while (cmd->args[i])
	{
		printf("%s", cmd->args[i]);
		if (cmd->args[i + 1])
			printf(" ");
		i++;
	}
	if (j == 0)
		printf("\n");
	g_error = 0;
	return (0);
}
