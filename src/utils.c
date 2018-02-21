#include "struct.h"

int		tab_len(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		all_is_set(t_env *env)
{
	if (!env->isset->room_is_set)
		return (1);
	else if	(!env->isset->start_is_set)
		return (2);
	else if (!env->isset->end_is_set)
		return (3);
	else if	(!env->isset->start_is_set)
		return (4);
	return (0);
}

void	display_exit(int exit)
{
	if (exit == 1)
		ft_putendl("No enough rooms found, exiting");
	else if (exit == 2)
		ft_putendl("Start room is not set, exiting");
	else if (exit == 3)
		ft_putendl("End room is not set, exiting");
	else if (exit == 4)
		ft_putendl("No tubes found, exiting");
}

void	ft_exit(t_env *env)
{
	int exit_num;

	exit_num = 0;
	if ((exit_num = all_is_set(env)) > 0)
	{
		display_exit(exit_num);
		//write(2, "ERROR\n", 6);
		//free_tab(tab);
		//free_list(list);
		//free_env(env);
		exit (1);
	}
	env->wrong_but_set = 1;
	ft_putendl("Bad argument but everything is set for next step!");
}