#include "struct.h"

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

int		tab_is_valid_three(char **tab)
{
	if (tab[0][0] == 'L' || tab[0][0] == '#')
		return (0);
	else if (!str_is_digit(tab[1]) || !str_is_digit(tab[2]))
		return (0);
	return (1);
}

void	set_start_end(char **tab, t_env *env)
{
	if (ft_strcmp(tab[0], "##start") == 0 && env->isset->start_is_set == 0)
		env->next_room_is_start = 1;
	else if (ft_strcmp(tab[0], "##end") == 0 && env->isset->end_is_set == 0)
		env->next_room_is_end = 1;
}

//int		next_step()

/*void	room_init(char *line, t_env *env)
{
	char **tab;

	tab = ft_strsplit(line, ' ');
	if (tab_len(tab) == 1 && tab[0][0] == '#')
		set_start_end(tab, env);
	else if (tab_len(tab) == 3 && tab_is_valid_three(tab))
		add_node(tab, env);
	else
	{
		//free_tab(tab);
		tube_init(line, env);
	}
	//free(line);
}*/