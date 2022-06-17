/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:19:30 by msosnova          #+#    #+#             */
/*   Updated: 2021/06/06 15:21:42 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	char	new_line;

	if (!s)
		return ;
	write(fd, (void *)s, ft_strlen(s));
	new_line = '\n';
	write(fd, &new_line, 1);
}
