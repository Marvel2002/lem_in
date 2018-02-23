#include "struct.h"

int		main(void)
{
	t_env *env;

	env = init_env();
	parsing_loop(env);
	if (all_is_set(env))
		ft_putendl("ALL IS SET, READY FOR ALGO");
	else
		write(2, "ERROR\n", 6);
	display_list(env);
	return (0);
}