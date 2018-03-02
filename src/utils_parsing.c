/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:05:12 by mmatime           #+#    #+#             */
/*   Updated: 2018/03/02 11:05:13 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int		tab_len(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		str_is_digit(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] >= '0' && line[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}
