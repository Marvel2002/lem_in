/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:05:02 by mmatime           #+#    #+#             */
/*   Updated: 2018/03/02 11:05:07 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	set_path(t_room *start, int path)
{
	int i;

	i = 0;
	while (i < start->num_link)
	{
		start->check = 1;
		if (!start->link[i]->check && start->link[i]->path == 0)
		{
			start->link[i]->path = path;
			set_path(start->link[i], path + 1);
		}
		else if (start->link[i]->check && start->link[i]->path > path)
		{
			start->link[i]->path = path;
			set_path(start->link[i], path + 1);
		}
		i++;
	}
}

int		min_path(t_room *end)
{
	int i;
	int nb_min;

	i = 0;
	nb_min = end->link[i]->path;
	while (i < end->num_link)
	{
		if (nb_min > end->link[i]->path)
			nb_min = end->link[i]->path;
		i++;
	}
	return (nb_min);
}

int		path_exists(t_env *env)
{
	t_room *start;
	t_room *end;

	start = find_start(env);
	start->ant = env->ant_max;
	end = find_end(env);
	set_path(start, 1);
	if (end->path)
		return (1);
	return (0);
}
