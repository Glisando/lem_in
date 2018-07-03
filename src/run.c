/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 12:18:27 by hdanylev          #+#    #+#             */
/*   Updated: 2018/05/10 19:11:31 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	set_here(t_rooms **rooms, int *tab, int lvl)
{
	int		i;
	t_rooms	*tmp;

	i = 0;
	while (i < lvl + 1)
	{
		tmp = find_index((*rooms), tab[i]);
		tmp->here = 0;
		i++;
	}
}

void	run_run(t_rooms *rooms, t_ant *ant, int ant_sum)
{
	int		d;
	int		num;
	t_rooms	*tmp;

	d = 0;
	while (ant[ant_sum - 1].room != 0)
	{
		if (ant[d].room != 0)
		{
			num = ant[d].i + 1;
			tmp = find_index(rooms, ant[d].tab[num]);
			if (tmp->here == 0)
			{
				ant[d].i += 1;
				tmp->here = tmp->index == 0 ? 0 : 1;
				ant[d].room = tmp->index;
				ft_printf("L%d-%s ", ant[d].ant + 1, tmp->name);
				tmp = find_index(rooms, ant[d].tab[num - 1]);
				tmp->here = 0;
			}
		}
		if (++d == ant_sum && ft_printf("\n"))
			d = 0;
	}
}

void	are_you_ready_for_run(t_rooms *rooms)
{
	int		i;
	t_ant	*ant;
	t_rooms	*tmp;

	ant = (t_ant*)malloc(sizeof(t_ant) * rooms->ant_sum);
	tmp = find_index(rooms, 0);
	i = 0;
	while (i < rooms->ant_sum)
	{
		ant[i].ant = i;
		ant[i].tab = tmp->path;
		ant[i].i = 0;
		ant[i].room = 1;
		i++;
	}
	set_here(&rooms, tmp->path, tmp->lvl);
	run_run(rooms, ant, tmp->ant_sum);
	free(ant);
}
