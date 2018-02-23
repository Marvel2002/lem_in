#include "struct.h"

int		main(void)
{
	t_env *env;
	int i;

	env = init_env();
	i = 0;
	parsing_loop(env);
	if (all_is_set(env))
	{
		display_list(env);
		ft_putendl("ALL IS SET, READY FOR ALGO");
		while (env->room)
		{
			ft_putstr(env->room->name);
			ft_putchar(' ');
			ft_putnbr(env->room->x);
			ft_putchar(' ');
			ft_putnbr(env->room->y);
			ft_putchar('\n');
			env->room = env->room->next;
		}
	}
	else
	{
		display_list(env);
		write(2, "ERROR\n", 6);
	}
	return (0);
} // PROBLEME AVEC LE GROS FICHIER MEGATEXT, POURQUOI IL NAFFICHE PAS LES LIENS TROUVER LA CAUSE