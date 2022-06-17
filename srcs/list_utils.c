/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:47:46 by msosnova          #+#    #+#             */
/*   Updated: 2022/03/10 18:47:21 by tjudlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdlib.h>

//creating a new list
t_lpars	*ft_new_lst(t_shell *shell)
{
	t_lpars	*new_list;

	new_list = (t_lpars *)malloc(sizeof(t_lpars));
	if (!new_list)
	{
		perror("MS:");
		g_error = errno;
		ft_exit(shell);
	}
	new_list->redirect_1 = 0;
	new_list->file_1 = NULL;
	new_list->args = NULL;
	new_list->redirect_2 = 0;
	new_list->file_2 = NULL;
	new_list->next = NULL;
	new_list->prev = NULL;
	new_list->fd1 = 0;
	new_list->fd2 = 1;
	new_list->pipe[0] = 0;
	new_list->pipe[1] = 0;
	shell->nb_cmd++;
	return (new_list);
}

//search for the last list
t_lpars	*ft_lst_last(t_lpars *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

//adding the next list
t_lpars	*ft_lst_add_back(t_lpars *lst, t_lpars *new)
{
	t_lpars	*last;

	last = ft_lst_last(lst);
	if (last)
	{
		last->next = new;
		new->prev = last;
	}
	return (new);
}

//dell lists
void	ft_lst_clear(t_shell *shell, t_lpars *lst)
{
	t_lpars	*nextlst;

	while (lst)
	{
		nextlst = lst->next;
		free(lst->file_1);
		lst->file_1 = 0;
		free(lst->file_2);
		lst->file_2 = 0;
		ft_freetab2(lst->args);
		lst->args = NULL;
		lst->next = NULL;
		lst->prev = NULL;
		free(lst);
		lst = nextlst;
	}
	shell->first_token = NULL;
	shell->nb_cmd = 0;
}

void	ft_print_lst(t_lpars *lst)
{
	int	i;

	while (lst)
	{
		printf("************************************\n");
		printf("redirect_1 = %i\n", lst->redirect_1);
		printf("file_1 = %s\n", lst->file_1);
		if (lst->args)
		{
			i = 0;
			while (lst->args[i])
				printf("\targ = \"%s\"\n", lst->args[i++]);
		}
		printf("file_2 = %s\n", lst->file_2);
		printf("redirect_2 = %i\n", lst->redirect_2);
		printf("************************************\n");
		lst = lst->next;
	}
}
