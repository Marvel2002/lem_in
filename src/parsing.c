#include "struct.h"

int 	tab_is_valid_two(char **tab, t_env *env)
{
	int match_1;
	int match_2;
	t_room *tmp;

	tmp = env->room;
	match_1 = 0;
	match_2 = 0;
	while (tmp)
	{
		if (ft_strcmp(tab[0], tmp->name) == 0)
			match_1 = 1;
		else if (ft_strcmp(tab[1], tmp->name) == 0)
			match_2 = 1;
		tmp = tmp->next;
	}
	if (match_1 && match_2)
		return (1);
	return (0);
}

int		tab_is_valid_three(char **tab)
{
	if (tab[0][0] == 'L' || tab[0][0] == '#')
		return (0);
	else if (!str_is_digit(tab[1]) || !str_is_digit(tab[2]))
		return (0);
	return (1);
}

/*void	init_ant(t_env *env, char *line_buf)
{
	env->ant_max = ft_atoi(line_buf);
}*/

int		parsing_loop(t_env *env)
{
	char *line_buf;
	static int mode;

	line_buf = NULL;
	while (get_next_line(0, &line_buf) > 0)
	{
		if (line_buf[0] == '#')
			;
		else if (mode == 0 && str_is_digit(line_buf) && ft_atoi(line_buf))
		{
			//init_ant(env, line_buf);
			env->ant_max = ft_atoi(line_buf);
			restart_start_end(env);
			mode++;
		}
		else if (mode == 1 && (mode = analyse_and_init_room(line_buf, env)))
			;
		else if (mode == 2)
			analyse_and_init_tube(line_buf, env);
		else
			break ;
		create_node_list(env, line_buf);
	}
	return (0);
}