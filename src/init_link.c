/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:04:52 by mmatime           #+#    #+#             */
/*   Updated: 2018/03/02 11:04:53 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	fill_node_tube(char **tab, t_env *env)
{
	t_room *first;
	t_room *second;

	first = find_first_room(tab, env);
	second = find_second_room(tab, env);
	if (!first->link)
	{
		first->link = (t_room **)ft_memalloc(sizeof(t_room *));
		first->link[0] = second;
		first->num_link++;
	}
	else
		add_tube_to_list(first, second);
	if (!second->link)
	{
		second->link = (t_room **)ft_memalloc(sizeof(t_room *));
		second->link[0] = first;
		second->num_link++;
	}
	else
		add_tube_to_list(second, first);
	if (!env->isset->tube_is_set)
			env->isset->tube_is_set = 1;
}

