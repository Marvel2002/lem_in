/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:05:10 by mmatime           #+#    #+#             */
/*   Updated: 2018/03/02 11:05:11 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	display_list(t_env *env)
{
	t_stdin *tmp;

	tmp = env->stdin_list;
	while (tmp)
	{
		ft_putendl(tmp->line);
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

int		count_list(t_env *env)
{
	int i;
	t_room *tmp;

	tmp = env->room;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_room	*find_start(t_env *env)
{
	t_room *tmp;

	tmp = env->room;
	while (!tmp->start)
		tmp = tmp->next;
	return (tmp);
}

t_room	*find_end(t_env *env)
{
	t_room *tmp;

	tmp = env->room;
	while (!tmp->end)
		tmp = tmp->next;
	return (tmp);
}

int		check_end(t_room *start)
{
	if (start->end)
		return (1);
	return (0);
}
