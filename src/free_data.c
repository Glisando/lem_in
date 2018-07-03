/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 15:50:01 by hdanylev          #+#    #+#             */
/*   Updated: 2018/04/28 15:51:18 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	free_queue(t_q *qhead)
{
	t_q		*ptr;

	while (qhead)
	{
		ptr = qhead;
		qhead = qhead->next;
		free(ptr);
	}
}

void	free_all_links(t_link *link)
{
	t_link *ptr;

	ptr = NULL;
	while (link)
	{
		free(link->name);
		ptr = link;
		link = link->next;
		free(ptr);
		ptr = NULL;
	}
}

void	free_main_list(t_rooms *rooms)
{
	t_rooms *tmp;

	tmp = NULL;
	while (rooms)
	{
		free_all_links(rooms->links);
		free(rooms->name);
		free(rooms->path);
		tmp = rooms;
		rooms = rooms->next;
		free(tmp);
		tmp = NULL;
	}
}

int		free_mass(char **mass)
{
	int i;

	i = 0;
	while (mass[i])
	{
		free(mass[i]);
		i++;
	}
	free(mass);
	return (0);
}

int		del(char *line, char *print, t_val *ant)
{
	free(ant);
	ant = NULL;
	if (line)
		ft_strdel(&line);
	if (print)
		ft_strdel(&print);
	return (0);
}
