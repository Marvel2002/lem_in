#include "struct.h"

t_env	*init_env(void)
{
	t_env *env;

	env = (t_env *)ft_memalloc(sizeof(t_env));
	env->isset = (t_isset *)ft_memalloc(sizeof(t_isset));
	return (env);
}
