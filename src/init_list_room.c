/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list_room.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:04:54 by mmatime           #+#    #+#             */
/*   Updated: 2018/03/02 11:04:55 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	add_tube_to_list(t_room *node, t_room *to_add)
{
	int i;
	t_room **new_link;

	i = 0;
	new_link = (t_room **)ft_memalloc(sizeof(t_room *) * (node->num_link + 1));
	if (new_link)
	{
		while (i < node->num_link)
		{
			new_link[i] = node->link[i];
			i++;
		}
		new_link[i] = to_add;
		node->link = new_link;
		node->num_link++;
	}
}

void	fill_node_room(char **tab, t_env *env)
{
	t_room *room;

	room = (t_room *)ft_memalloc(sizeof(t_room));
	if (room)
	{
		room->name = ft_strdup(tab[0]);
		room->x = ft_atoi(tab[1]);
		room->y = ft_atoi(tab[2]);
		if (env->room)
			room->next = env->room;
		else
			room->next = NULL;
		env->room = room;
		set_start_end(env, room);
		restart_start_end(env);
		if (!env->isset->room_is_set)
			env->isset->room_is_set = 1;
		ft_free_tab(tab);
	}
}
