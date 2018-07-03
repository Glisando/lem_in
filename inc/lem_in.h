/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:14:51 by hdanylev          #+#    #+#             */
/*   Updated: 2018/05/30 12:33:45 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../lib/libftprintf/inc/printf.h"

typedef struct		s_link
{
	int				index;
	char			*name;
	struct s_rooms	*link_room;
	struct s_link	*next;
}					t_link;

typedef struct		s_rooms
{
	int				ant_sum;
	int				rum_sum;
	int				x;
	int				y;
	int				lvl;
	int				index;
	int				usd;
	int				here;
	int				find_zero;
	char			*name;
	int				*path;
	struct s_rooms	*next;
	struct s_rooms	*prev;
	struct s_link	*links;
}					t_rooms;

typedef struct		s_val
{
	int				index;
	int				ant_sum;
	int				start;
	int				end;
	int				end_room;
	int				comment;
	int				finish_room;
	int				start_room;
	int				rooms_beg;
	int				links_beg;
	int				rm_num;
}					t_val;

typedef struct		s_ant
{
	int				ant;
	int				*tab;
	int				i;
	int				room;
}					t_ant;

typedef struct		s_q
{
	t_rooms			*qrm;
	int				lvl;
	struct s_q		*next;
}					t_q;

int					validation(t_val **ant, char *line, t_rooms **rooms);
int					ant_sum(t_val **ant, char *line);
void				put_room(t_rooms **rooms, char **mass, t_val **ant);
void				put_links(t_rooms **rooms, char **mass);
t_rooms				*create_room();
int					check_links(t_val **ant, t_rooms **rooms, char *line);
t_rooms				*find_name(t_rooms **rooms, char *name);
int					free_mass(char **mass);
t_rooms				*find_index(t_rooms *rooms, int index);
int					bfs_preparation(t_rooms *rooms);
void				are_you_ready_for_run(t_rooms *rooms);
void				run_run(t_rooms *rooms, t_ant *ant, int ant_sum);
void				free_main_list(t_rooms *rooms);
t_q					*set_to_the_queue(t_q *que, t_q **qlink, t_link *ptr);
void				set_path(t_rooms *tmp, t_q **que);
void				free_queue(t_q *qhead);
void				free_all_links(t_link *link);
int					del(char *line, char *print, t_val *ant);

#endif
