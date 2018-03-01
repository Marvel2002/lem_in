#include "struct.h"

t_env	*init_env(void)
{
	t_env *env;

	if (!(env = (t_env *)ft_memalloc(sizeof(t_env))))
		return (NULL);
	if (!(env->isset = (t_isset *)ft_memalloc(sizeof(t_isset))))
		return (NULL);
	return (env);
}
