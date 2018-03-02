/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list_stdin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:04:56 by mmatime           #+#    #+#             */
/*   Updated: 2018/03/02 11:04:57 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

t_room	*find_second_room(char **tab, t_env *env)
{
	t_room *tmp;

	tmp = env->room;
	while (ft_strcmp(tmp->name, tab[1]))
		tmp = tmp->next;
	return (tmp);
}

t_room	*find_first_room(char **tab, t_env *env)
{
	t_room *tmp;

	tmp = env->room;
	while (ft_strcmp(tmp->name, tab[0]))
		tmp = tmp->next;
	return (tmp);
}

void	init_node_list(t_env *env, t_stdin *line_list, char *line_buf)
{
	t_stdin *tmp;

	tmp = env->stdin_list;
	line_list->line = ft_strdup(line_buf);
	line_list->next = NULL;
	if (!env->stdin_list)
		env->stdin_list = line_list;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = line_list;

	}
	check_comment_start_end(env, line_list);
}

void	create_node_list(t_env *env, char *line_buf)
{
	t_stdin	*line_list;

	line_list = (t_stdin*)ft_memalloc(sizeof(t_stdin));
	if (line_list)
		init_node_list(env, line_list, line_buf);
}
