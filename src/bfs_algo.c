/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 19:27:26 by hdanylev          #+#    #+#             */
/*   Updated: 2018/05/01 19:27:34 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

t_rooms	*queue(t_q **qlink, t_rooms *tmp, int *stop)
{
	t_q		*que;
	t_link	*ptr;

	que = (*qlink);
	ptr = tmp->links;
	while (que && que->next)
		que = que->next;
	while (ptr)
	{
		if (ptr->link_room->lvl == 0)
		{
			que = set_to_the_queue(que, qlink, ptr);
			que->qrm->lvl = tmp->lvl + 1;
			set_path(tmp, &que);
		}
		ptr = ptr->next;
	}
	if (tmp->index == 0)
		*stop = 9999;
	return ((*qlink) != NULL ? (*qlink)->qrm : tmp);
}

int		bfs_algo2(t_rooms *tmp, t_q *qlink, int stop)
{
	int		brk;

	brk = 0;
	while (stop != 9999 && brk != 5)
	{
		if (qlink->next)
			qlink = qlink->next;
		else
			brk++;
		tmp = queue(&qlink, tmp, &stop);
	}
	return (brk == 5 ? 0 : 1);
}

int		bfs_algo(t_rooms *rooms, t_q **qhead)
{
	t_rooms	*tmp;
	t_q		*qlink;
	int		stop;

	tmp = find_index(rooms, 1);
	qlink = NULL;
	stop = 0;
	tmp = queue(&qlink, tmp, &stop);
	if (!qlink)
		return (0);
	*qhead = qlink;
	return (bfs_algo2(tmp, qlink, stop));
}

int		bfs_preparation(t_rooms *rooms)
{
	int			i;
	t_q			*qhead;

	i = 0;
	qhead = NULL;
	if (!(bfs_algo(rooms, &qhead)))
	{
		free_queue(qhead);
		return (0);
	}
	free_queue(qhead);
	are_you_ready_for_run(rooms);
	return (1);
}
