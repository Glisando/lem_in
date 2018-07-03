/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 12:37:26 by hdanylev          #+#    #+#             */
/*   Updated: 2018/04/17 12:37:28 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

t_rooms		*create_room(void)
{
	t_rooms *rooms;

	rooms = (t_rooms*)malloc(sizeof(t_rooms));
	rooms->ant_sum = 0;
	rooms->x = -1;
	rooms->y = -1;
	rooms->lvl = 0;
	rooms->name = NULL;
	rooms->links = NULL;
	rooms->next = NULL;
	rooms->prev = NULL;
	rooms->path = NULL;
	rooms->index = 0;
	return (rooms);
}

t_val		*set_val(t_val *ant)
{
	ant->index = 2;
	ant->comment = 0;
	ant->ant_sum = 0;
	ant->start = 0;
	ant->end = 0;
	ant->rm_num = 0;
	ant->rooms_beg = 0;
	ant->links_beg = 0;
	ant->start_room = 0;
	ant->finish_room = 0;
	ant->end_room = 0;
	return (ant);
}

void		set_rum_sum(t_rooms **rooms, t_val *ant)
{
	t_rooms *tmp;

	tmp = (*rooms);
	while (tmp)
	{
		tmp->rum_sum = ant->rm_num;
		tmp = tmp->next;
	}
}

int			second_main(t_val *ant, t_rooms *rooms, char *line)
{
	char *print;
	char *ptr;

	ptr = NULL;
	print = (char*)malloc(sizeof(char));
	while ((get_next_line(0, &line)))
	{
		ptr = print;
		print = ft_strjoin(print, line);
		free(ptr);
		ptr = print;
		print = ft_strjoin(print, "\n");
		free(ptr);
		if ((validation(&ant, line, &rooms)) == 0)
			return (del(line, print, ant));
		free(line);
	}
	if (ant->links_beg == 0 || ant->comment)
		return (del(line, print, ant));
	set_rum_sum(&rooms, ant);
	ft_printf("%s\n", print);
	free(print);
	return (1);
}

int			main(void)
{
	t_val	*ant;
	t_rooms	*rooms;

	if ((read(0, NULL, 0)) <= -1)
		return (0);
	ant = (t_val*)malloc(sizeof(t_val));
	rooms = create_room();
	ant = set_val(ant);
	if (!(second_main(ant, rooms, NULL)))
		return (write(1, "ERROR\n", 6));
	if (!(bfs_preparation(rooms)))
	{
		free(ant);
		free_main_list(rooms);
		return (0);
	}
	free(ant);
	free_main_list(rooms);
	return (0);
}
