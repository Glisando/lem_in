/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path_que.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 12:48:51 by hdanylev          #+#    #+#             */
/*   Updated: 2018/05/09 12:50:17 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

t_q		*set_to_the_queue(t_q *que, t_q **qlink, t_link *ptr)
{
	t_q	*new;

	new = (t_q*)malloc(sizeof(t_q));
	new->qrm = ptr->link_room;
	if (que == NULL)
	{
		(*qlink) = new;
		que = (*qlink);
	}
	else
	{
		que->next = new;
		que = que->next;
	}
	que->next = NULL;
	return (que);
}

void	set_path(t_rooms *tmp, t_q **que)
{
	int		i;

	(*que)->qrm->path = (int*)malloc(sizeof(int) * tmp->rum_sum - 1);
	i = 0;
	while (i < tmp->rum_sum - 1)
	{
		if (i < tmp->lvl)
			(*que)->qrm->path[i] = tmp->path[i];
		else if (i == tmp->lvl)
			(*que)->qrm->path[i] = tmp->index;
		else if ((*que)->qrm->index == 0)
			(*que)->qrm->path[i] = 0;
		else
			(*que)->qrm->path[i] = -1;
		i++;
	}
	if ((*que)->qrm->index == 0)
		(*que)->qrm->path[i] = 0;
}
