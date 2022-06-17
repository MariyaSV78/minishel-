/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:19:41 by msosnova          #+#    #+#             */
/*   Updated: 2022/02/24 17:19:44 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_error_2(t_shell *shell, char arg)
{
	if (arg == '/' && (!ft_isalpha(shell->first_token->args[0][1])))
	{
		g_error = 126;
		if (shell->first_token->args[0][1] != '/')
			printf("MS: %c: Is a directory\n", arg);
		else
			printf("MS: %c%c: Is a directory\n", arg, arg);
		return (0);
	}
	if (arg == '&' || arg == ';')
	{
		printf("MS: syntax error near unexpected token `%c%c`\n", arg, arg);
		g_error = 2;
		return (0);
	}
	if (arg == '(' || arg == ')')
	{
		printf("MS: syntax error near unexpected token `)`\n");
		g_error = 2;
		return (0);
	}
	return (1);
}

int	ft_error(t_shell *shell)
{
	if (shell->is_error || shell->first_token->args == NULL
		|| shell->first_token->args[0] == NULL)
		return (0);
	if (!ft_error_2(shell, shell->first_token->args[0][0]))
		return (0);
	return (1);
}
