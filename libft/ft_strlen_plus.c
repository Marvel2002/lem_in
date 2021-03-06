/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_plus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:41:00 by mmatime           #+#    #+#             */
/*   Updated: 2017/12/26 15:59:08 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strlen_plus(const char *s1, int nb)
{
	int i;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i] || nb > 0)
	{
		if (s1[i] == '\0')
			nb--;
		i++;
	}
	return (i);
}
