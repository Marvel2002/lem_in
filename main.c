/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 18:53:57 by mmatime           #+#    #+#             */
/*   Updated: 2018/02/23 19:05:19 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void		ft_realloc(char **ptr, size_t size, char c)
{
	char		*newptr;

	newptr = NULL;
	if (*ptr)
	{
		newptr = (char *)malloc(sizeof(char) * (size + 2));
		if (!newptr)
			return ;
		memcpy(newptr, *ptr, size);
		free((void *)*ptr);
		*ptr = newptr;
		(*ptr)[size] = c;
	}
	else
	{
		*ptr = (char *)malloc(sizeof(char) * 2);
		if (!ptr)
			return ;
		*ptr[size] = c;
	}
}

int		main(void)
{
	char *str;
	char **str2;
	char ***str3;

	char c = 'a';

	str = &c;
	str2 = &str;
	str3 = &str2;
	ft_realloc(&str, 2, 'b');
	return (0);
}