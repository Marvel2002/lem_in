#include "struct.h"

int		main(void)
{
	t_env *env;

	env = (t_env *)malloc(sizeof(t_env));
	while (parsing_loop(env))
		;
	return (0);
}