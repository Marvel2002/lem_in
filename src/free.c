/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:04:46 by mmatime           #+#    #+#             */
/*   Updated: 2018/03/02 11:04:47 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	free_stdin(t_stdin *stdin_list)
{
	t_stdin *next;

	while (stdin_list)
	{
		next = stdin_list->next;
		free(stdin_list->line);
		free(stdin_list);
		stdin_list = next;
	}
	stdin_list = NULL;
}

void	free_isset(t_isset *isset)
{
	free(isset);
}

void	free_link(struct s_room **link, int num_link)
{
	int i;

	i = 0;
	while (i < num_link)
	{
		free(link[i]);
		i++;
	}
	free(link);
}

void	free_room(t_room *room)
{
	t_room *next;

	while (room)
	{
		next = room->next;
		free(room->name);
		//free_link(room->link, room->num_link);
		free(room->link);
		free(room);
		room = next;
	}
	room = NULL;
}

void	full_free(t_env *env)
{
	free_stdin(env->stdin_list);
	free_isset(env->isset);
	free_room(env->room);
	free(env);
}
