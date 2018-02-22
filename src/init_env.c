#include "struct.h"
/*
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
}*/

void	fill_node_room(char **tab, t_env *env)
{
	t_room *room;

	room = (t_room *)ft_memalloc(sizeof(t_room));
	if (room)
	{
		room->name = ft_strdup(tab[0]);
		room->x = ft_atoi(tab[1]);
		room->y = ft_atoi(tab[2]);
		if (env->room)
			room->next = env->room;
		else
			room->next = NULL;
		env->room = room;
	}
	ft_putendl("room is created");
}


int		analyse_tube_and_init(char *line_buf, t_env *env)
{
	char **tab;

	tab = ft_strsplit(line_buf, '-');
	if (tab_len(tab) == 2 && tab_is_valid_two(tab))
	{
		return (2);
	}
	return (0);
}

int		analyse_room_and_init(char *line_buf, t_env *env)
{
	char **tab;

	tab = ft_strsplit(line_buf, ' ');
	if (tab_len(tab) == 3 && tab_is_valid_three(tab))
	{
		//free_tab(tab);
		return (1);
	}
	if (analyse_tube_and_init(line_buf, env))
		return (2);
	//free_tab(tab);
	
	//free_tab(tab)
	return (0);
}

int		analyse_and_parse_tube(char *line_buf, t_env *env) // ON EN EST LA <<<<< CHERCHER SI DES SALLES MATCHS
{
	char **tab;

	tab = ft_strsplit(line_buf, '-');
	if (tab_len(tab) == 2)
	{
		ft_putstr("link\n");
		env->isset->tube_is_set = 1;
	}
	else
		return (0);
	return (1);
}

int		count_list(t_env *env)
{
	t_room *tmp;
	int i;

	tmp = env->room;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	init_node_list(t_env *env, t_stdin *line_list, char *line_buf)
{
	line_list->line = ft_strdup(line_buf);
	if (env->stdin_list)
		line_list->next = env->stdin_list;
	else
		line_list->next = NULL;
	env->stdin_list = line_list;
}

void	create_node_list(t_env *env, char *line_buf)
{
	t_stdin	*line_list;

	line_list = (t_stdin*)ft_memalloc(sizeof(t_stdin));
	if (line_list)
	{
		init_node_list(env, line_list, line_buf);
		set_start_end(env);
	}
}

void	init_ant(t_env *env, char *line_buf)
{
	env->ant_max = ft_atoi(line_buf)	
}

void	check_start_end(t_env *env)
{
	if (env->next_room_is_start)
		env->next_room_is_start = 0;
	if (env->next_room_is_end)
		env->next_room_is_end = 0;
}

int		parsing_loop(t_env *env)
{
	char *line_buf;
	static int mode;

	line_buf = NULL;
	while (get_next_line(0, &line_buf) > 0)
	{
		if (line_buf[0] == '#')
			create_node_list(env, line_buf);
		else if (mode == 0 && str_is_digit(line_buf) && ft_atoi(line_buf))
		{
			create_node_list(env, line_buf);
			init_ant(env, line_buf);
			check_start_end(t_env);
			mode++;
		}
		else if (mode == 1)
		{
			mode = analyse_room_and_init(line_buf); // retour de mode qui decide
			create_node_list(env, line_buf);
		}
		else if (mode == 2)
		{
			analyse_room_and_init(line_buf);
		}
		else
			break ;
	}
}

int		parsing_loop(t_env *env)
{
	char *line_buf;
	t_stdin *line_list;

	line_buf = NULL;
	line_list = NULL;
	while (get_next_line(0, &line_buf) > 0 && analyse_room(line_buf, env))
	{
		line_list = (t_stdin*)ft_memalloc(sizeof(t_stdin));
		if (line_list)
			fill_node_list(env, line_list, line_buf);
		else
			return (0);
		free(line_buf);
	}
	ft_putendl("entree");
	if (count_list(env) > 1 && analyse_and_parse_tube(line_buf, env)) // SOUCIS ICI
	{
		ft_putendl("entree");
		free(line_buf);
		while (get_next_line(0, &line_buf) > 0 && analyse_and_parse_tube(line_buf, env))
		{
			line_list = (t_stdin*)ft_memalloc(sizeof(t_stdin));
			if (line_list)
				fill_node_list(env, line_list, line_buf);
			else
				return (0);
			free(line_buf);
		}
	}
	return (0);
}