/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:05:08 by mmatime           #+#    #+#             */
/*   Updated: 2018/03/02 11:05:09 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

t_room	*go_to_next_min(t_room *end, int min)
{
	int i;

	i = 0;
	while (i < end->num_link)
	{
		if (end->link[i]->path == min)
			return (end->link[i]);
		i++;
	}
	return (NULL);
}

int		ant_in_next(t_room *end)
{
	if (end->ant)
		return (1);
	return (0);
}

void	move_ant(t_room *tmp, t_room *end)
{
	static int ant = 1;
	tmp->ant++;
	if (tmp->path == 1)
	{
		end->ant_name = ant;
		ant++;
	}
	tmp->ant_name = end->ant_name;
	end->ant--;
	
}

void	display_solution(t_room *end, t_env *env)
{
	int min;
	t_room *end_final = end;
	t_room *tmp;

	min = min_path(end);
	while (!end->start)
	{
		tmp = end;
		end = go_to_next_min(end, min);
		if (ant_in_next(end))
		{
			move_ant(tmp, end);
			if (tmp->ant && !tmp->start)
			{
				ft_putchar('L');
				ft_putnbr_c(tmp->ant_name, '-');
				ft_putstr(tmp->name);
				ft_putchar(' ');
			}
		}
		min--;
	}
	ft_putchar('\n');
	if (end_final->ant != env->ant_max)
		display_solution(end_final, env);
}
