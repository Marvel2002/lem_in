#include "struct.h"

t_room	*find_start(t_env *env)
{
	t_room *tmp;

	tmp = env->room;
	while (!tmp->start)
		tmp = tmp->next;
	return (tmp);
}

t_room	*find_end(t_env *env)
{
	t_room *tmp;

	tmp = env->room;
	while (!tmp->end)
		tmp = tmp->next;
	return (tmp);
}

int		check_end(t_room *start)
{
	if (start->end)
		return (1);
	return (0);
}

void	set_path(t_room *start, int path)
{
	int i;

	i = 0;
	while (i < start->num_link)
	{
		start->check = 1;
		if (!start->link[i]->check && start->link[i]->path == 0)
		{
			start->link[i]->path = path;
			set_path(start->link[i], path + 1);
		}
		else if (start->link[i]->check && start->link[i]->path > path)
		{
			start->link[i]->path = path;
			set_path(start->link[i], path + 1);
		}
		i++;
	}
	/*ft_putstr("SORTIE DE ");
	ft_putnbr(path);
	ft_putendl(" <<<<<<<<<<<<<");*/
}

void	display_room(t_env *env)
{
	t_room *tmp;

	tmp = env->room;
	while (tmp)
	{
		ft_putnbr(tmp->path);
		tmp = tmp->next;
	}
}

int		min_path(t_room *end)
{
	int i;
	int nb_min;

	i = 0;
	nb_min = end->link[i]->path;
	while (i < end->num_link)
	{
		if (nb_min > end->link[i]->path)
			nb_min = end->link[i]->path;
		i++;
	}
	return (nb_min);
}

t_room	*go_to_next_min(t_room *end, int min)
{
	int i;

	i = 0;
	while (i < end->num_link)
	{
		if (end->link[i]->path == min)
			return (end->link[i]);
		i++;
	}
	return (NULL);
}

int		ant_in_next(t_room *end)
{
	if (end->ant)
		return (1);
	return (0);
}

void	move_ant(t_room *tmp, t_room *end)
{
	tmp->ant++;
	end->ant--;
}

void	display_solution(t_room *end, t_env *env)
{
	int min;
	t_room *end_final = end;
	t_room *tmp;

	min = min_path(end);
	while (!end->start)
	{
		tmp = end;
		end = go_to_next_min(end, min);
		if (ant_in_next(end))
		{
			move_ant(tmp, end);
			if (tmp->ant && !tmp->start)
			{
				ft_putstr(tmp->name);
				ft_putchar(' ');
			}
		}
		min--;
	}
	ft_putchar('\n');
	if (end_final->ant != env->ant_max)
		display_solution(end_final, env);
}

int		path_to_end(t_room *end)
{
	int i;

	i = 0;
	while (i < end->num_link)
	{
		if (end->link[i]->path)
			return (1);
		i++;
	}
	return (0);
}

int		main(void)
{
	t_env *env;

	env = init_env();
	t_room *start;
	t_room *end;
	parsing_loop(env);
	if (all_is_set(env))
	{
		display_list(env);
		start = find_start(env);
		end = find_end(env);
		set_path(start, 1);
		if (path_to_end(end))
		{
			start->ant = env->ant_max;
			ft_putchar('\n');
			display_solution(end, env);
		}
		else
			ft_putendl("Aucun chemin ne mène start à end");
	}
	else
	{
		//display_list(env);
		write(2, "ERROR\n", 6);
	}
	return (0);
}