#include "struct.h"

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
		set_start_end(env, room);
		restart_start_end(env);
		ft_putendl("room is created");
	}
}

int		analyse_and_init_tube(char *line_buf, t_env *env)
{
	char **tab;

	tab = ft_strsplit(line_buf, '-');
	if (tab_len(tab) == 2 && tab_is_valid_two(tab, env))
	{
		//fill_node_link
		return (2);
	}
	return (0);
}

int		analyse_and_init_room(char *line_buf, t_env *env)
{
	char **tab;

	tab = ft_strsplit(line_buf, ' ');
	if (tab_len(tab) == 3 && tab_is_valid_three(tab))
	{
		//free_tab(tab);
		fill_node_room(tab, env);
		return (1);
	}
	if (analyse_and_init_tube(line_buf, env))
		return (2);
	//free_tab(tab);
	
	//free_tab(tab)
	return (0);
}

void	init_node_list(t_env *env, t_stdin *line_list, char *line_buf)
{
	t_stdin *tmp;

	tmp = env->stdin_list;
	line_list->line = ft_strdup(line_buf);
	line_list->next = NULL;
	if (!env->stdin_list)
		env->stdin_list = line_list;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = line_list;

	}
	check_comment_start_end(env, line_list);
}

void	create_node_list(t_env *env, char *line_buf)
{
	t_stdin	*line_list;

	line_list = (t_stdin*)ft_memalloc(sizeof(t_stdin));
	if (line_list)
		init_node_list(env, line_list, line_buf);
}