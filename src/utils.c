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