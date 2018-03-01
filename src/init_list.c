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
		if (!env->isset->room_is_set)
			env->isset->room_is_set = 1;
	}
}


t_room	*find_second_room(char **tab, t_env *env)
{
	t_room *tmp;

	tmp = env->room;
	while (ft_strcmp(tmp->name, tab[1]))
		tmp = tmp->next;
	return (tmp);
}

t_room	*find_first_room(char **tab, t_env *env)
{
	t_room *tmp;

	tmp = env->room;
	while (ft_strcmp(tmp->name, tab[0]))
		tmp = tmp->next;
	return (tmp);
}

void	add_tube_to_list(t_room *node, t_room *to_add)
{
	int i;
	t_room **new_link;

	i = 0;
	new_link = (t_room **)ft_memalloc(sizeof(t_room *) * (node->num_link + 1));
	if (new_link)
	{
		while (i < node->num_link)
		{
			new_link[i] = node->link[i];
			i++;
		}
		new_link[i] = to_add;
		node->link = new_link;
		node->num_link++;
	}
}

void	fill_node_tube(char **tab, t_env *env)
{
	t_room *first;
	t_room *second;

	first = find_first_room(tab, env);
	second = find_second_room(tab, env);
	if (!first->link)
	{
		first->link = (t_room **)ft_memalloc(sizeof(t_room *));
		first->link[0] = second;
		first->num_link++;
	}
	else
		add_tube_to_list(first, second);
	if (!second->link)
	{
		second->link = (t_room **)ft_memalloc(sizeof(t_room *));
		second->link[0] = first;
		second->num_link++;
	}
	else
		add_tube_to_list(second, first);
	if (!env->isset->tube_is_set)
			env->isset->tube_is_set = 1;
}

int		analyse_and_init_tube(char *line_buf, t_env *env)
{
	char **tab;

	tab = ft_strsplit(line_buf, '-');
	if (tab_len(tab) == 2 && tab_is_valid_two(tab, env))
	{
		fill_node_tube(tab, env);
		return (2);
	}
	return (0);
}

void	ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	tab = NULL;
}

int		analyse_and_init_room(char *line_buf, t_env *env)
{
	char **tab;

	tab = ft_strsplit(line_buf, ' ');
	if (tab_len(tab) == 3 && tab_is_valid_three(tab, env))
	{
		fill_node_room(tab, env);
		return (1);
	}
	if (analyse_and_init_tube(line_buf, env))
		return (2);
	free_tab(tab);
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