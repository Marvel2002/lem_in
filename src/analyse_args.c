/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:04:30 by mmatime           #+#    #+#             */
/*   Updated: 2018/03/02 11:04:33 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int		analyse_and_init_tube(char *line_buf, t_env *env)
{
	char **tab;

	tab = ft_strsplit(line_buf, '-');
	if (tab_len(tab) == 2 && tab_is_valid_two(tab, env))
	{
		fill_node_tube(tab, env);
		ft_free_tab(tab);
		return (2);
	}
	ft_free_tab(tab);
	return (0);
}

int		analyse_and_init_room(char *line_buf, t_env *env)
{
	char **tab;

	tab = ft_strsplit(line_buf, ' ');
	if (tab_len(tab) == 3 && tab_is_valid_three(tab, env))
	{
		fill_node_room(tab, env);
		return (1);
	}
	if (analyse_and_init_tube(line_buf, env))
		return (2);
	ft_free_tab(tab);
	return (0);
}
