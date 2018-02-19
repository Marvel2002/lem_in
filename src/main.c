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

void	ft_exit(char **tab, t_env *env, t_room **list)
{
	free_tab(tab);
	free_list(list);
	free_env(env);
	write(2, "ERROR\n", 6);
	exit(1);
}

int		tab_is_valid_three(char **tab)
{
	if (tab[0[0]] == 'L' || tab[0][0] == '#')
		return (0);
	if (!ft_longtoi(tab[1]) || !ft_longtoi(tab[2]))
		return (0);
	return (1);
}

void	set_start_end(t_env *env)
{

}

void	set_node(t_env *env)

void	list_parse_init(t_env *env)
{
	char **tab;

	tab = ft_strsplit(line, ' ');
	if (tab_len(tab) == 1 && tab[0][0] == '#')
		set_start_end(env);
	else if (tab_len(tab) == 3 && tab_is_valid_three(tab))
		set_node(env);
	else
		ft_exit(tab, env, list, line);
	free_tab(tab);
}

t_env 	*init_env(char *line)
{
	t_env *env;

	env = (t_env *)ft_memalloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->ant_max = ft_atoi(line);
	return (env);
}

int		main(void)
{
	char *line;
	t_env *env;

	line = NULL;
	env = NULL;
	get_next_line(0, &line);
	if (str_is_digit(line) && ft_longtoi(line)) // nb au dessus d'un int pour fourmis possible ?
		env = init_env(line);
	else
		write(2, "ERROR\n", 6); // possible que qq chose de plus facile et opti m'echappe pour ces conditions a la suite
	free(line);
	if (env)
	{
		while (get_next_line(0, &line) > 0)
			list_parse_init(env, line);
	}
	return (0);
}