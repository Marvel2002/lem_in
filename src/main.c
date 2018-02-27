#include "struct.h"

t_room	*find_start(t_env *env)
{
	t_room *tmp;

	tmp = env->room;
	while (!tmp->start)
		tmp = tmp->next;
	tmp->check = 1;
	return (tmp);
}

t_room	*find_start(t_env *env)
{
	t_room *tmp;

	tmp = env->room;
	while (!tmp->end)
		tmp = tmp->next;
	tmp->check = 1;
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
		ft_putstr("On est dans la salle ");
		ft_putendl(start->name);
		ft_putstr("Et le path est ");
		ft_putnbr_c(start->path, '\n');
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

int		main(void)
{
	t_env *env;

	env = init_env();
	t_room *start;
	parsing_loop(env);
	if (all_is_set(env))
	{
		display_list(env);
		ft_putendl("ALL IS SET, READY FOR ALGO");
		start = find_start(env);
		end = find_end(env);
		set_path(start, 1);
		display_room(env);	
	}
	else
	{
		//display_list(env);
		write(2, "ERROR\n", 6);
	}
	return (0);
}