#include "struct.h"

t_room	*find_start(t_env *env)
{
	t_room *tmp;

	tmp = env->room;
	while (!tmp->start)
		tmp = tmp->next;
	return (tmp);
}

int		find_end(t_room *start)
{
	int i;

	i = 0;
	while (i < start->num_link)
	{
		if (start->link[i]->end)
		{
			ft_putendl("end trouve");
			return (1);
		}
		i++;
	}
	return (0);
}

int		main(void)
{
	t_env *env;
	int i;

	env = init_env();
	t_room *start;
	t_room *tmp;
	i = 0;
	parsing_loop(env);
	if (all_is_set(env))
	{
		display_list(env);
		ft_putendl("ALL IS SET, READY FOR ALGO");
		start = find_start(env);
		while (!find_end(start))
		{
			tmp = start;
			while (i < start->num_link)
				start = start->link[i];
		}		
	}
	else
	{
		//display_list(env);
		write(2, "ERROR\n", 6);
	}
	return (0);
}