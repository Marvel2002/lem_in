/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:04:49 by mmatime           #+#    #+#             */
/*   Updated: 2018/03/02 11:04:50 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

t_env	*init_env(void)
{
	t_env *env;

	if (!(env = (t_env *)ft_memalloc(sizeof(t_env))))
		return (NULL);
	if (!(env->isset = (t_isset *)ft_memalloc(sizeof(t_isset))))
		return (NULL);
	return (env);
}
