/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_all_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:05:14 by mmatime           #+#    #+#             */
/*   Updated: 2018/03/02 11:05:18 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	restart_start_end(t_env *env)
{
	if (env->next_room_is_start)
		env->next_room_is_start = 0;
	if (env->next_room_is_end)
		env->next_room_is_end = 0;
}

void	check_comment_start_end(t_env *env, t_stdin *line_list)
{
	if (!ft_strcmp(line_list->line, "##start") && !env->isset->start_is_set)
		env->next_room_is_start = 1;
	else if (!ft_strcmp(line_list->line, "##end") && !env->isset->end_is_set)
		env->next_room_is_end = 1;
}

void	set_start_end(t_env *env, t_room *room)
{
	if (env->next_room_is_start)
	{
		room->start = 1;
		env->isset->start_is_set = 1;
	}
	else if (env->next_room_is_end)
	{
		room->end = 1;
		env->isset->end_is_set = 1;
	}
	restart_start_end(env);
}

int		all_is_set(t_env *env)
{
	if (env->isset->room_is_set && env->isset->tube_is_set &&
		env->isset->end_is_set && env->isset->start_is_set)
		return (1);
	return (0);
}
