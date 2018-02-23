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

int		main(void)
{
	char **tab;
	int i;

	i = 0;
	tab = (char **)malloc(sizeof(*tab) * 2);
	tab[0] = (char *)malloc(sizeof(char) * 2);
	tab[0] = "salut";
	tab[1] = "ca va?";
	tab[2] = "oui merci";
	tab[3] = "mdr";
	tab[4] = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}
