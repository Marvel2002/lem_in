#include "struct.h"

t_env 	*init_env_ant(char *line)
{
	t_env *env;
 
	if (!(env = (t_env *)ft_memalloc(sizeof(t_env))))
		return (NULL);
	if (!(env->isset = (t_isset *)ft_memalloc(sizeof(t_isset))))
		return (NULL);
	env->ant_max = ft_atoi(line);
	ft_putstr("ant_max est OK\n"); 
	return (env);
}

t_env	*init_env(t_env *env)
{
	char *line;

	line = NULL;
	get_next_line(0, &line);
	if (str_is_digit(line) && ft_atoi(line) > 0)
		env = init_env_ant(line);
	free(line);
	return (env);
}

int 	tab_match(char **tab, t_env *env)
{
	int match_1;
	int match_2;
	t_room *tmp;

	tmp = env->room;
	match_1 = 0;
	match_2 = 0;
	if (tmp)
	{
		while (tmp)
		{
			if (ft_strcmp(tab[0], tmp->name) == 0)
				match_1 = 1;
			else if (ft_strcmp(tab[1], tmp->name) == 0)
				match_2 = 1;
			tmp = tmp->next;
		}
	}
	if (match_1 && match_2)
		return (1);
	return (0);
}

void	tube_init(char *line, t_env *env)
{
	char **tab;

	tab = ft_strsplit(line, '-');
	if (tab_len(tab) == 2 && tab_match(tab, env))
	{
		ft_putstr("link\n");
		env->isset->tube_is_set = 1;
	}
	else
		ft_exit(env);
}

void	parsing_loop(t_env *env)
{
	char *line;

	line = NULL;
	while (get_next_line(0, &line) > 0 && env->wrong_but_set == 0)
	{
		if (!env->isset->tube_is_set)
			room_init(line, env);
		else
			tube_init(line, env);
	}

}