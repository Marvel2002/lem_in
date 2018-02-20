#include "struct.h"

int		main(void)
{
	t_env *env;

	env = NULL;
	if ((env = init_env(env)))
		parsing_loop(env);
	else
		write(2, "ERROR\n", 6);
	return (0);
}