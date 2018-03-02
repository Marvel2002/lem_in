/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:04:57 by mmatime           #+#    #+#             */
/*   Updated: 2018/03/02 11:04:59 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int		main(void)
{
	t_env	*env;
	t_room	*end;

	env = init_env();
	end = NULL;
	if (env)
	{
		parsing_loop(env);
		if (all_is_set(env) && path_exists(env))
		{
			display_list(env);
			end = find_end(env);
			display_solution(end, env);
		}
		else
			write(2, "ERROR\n", 6);
	}
	full_free(env);
	return (0);
}
