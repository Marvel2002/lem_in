#include "struct.h"

t_env 	*init_env_ant(char *line)
{
	t_env *env;
 
	if (!(env = (t_env *)ft_memalloc(sizeof(t_env))))
		return (NULL);
	if (!(env->isset = (t_isset *)ft_memalloc(sizeof(t_isset))))
		return (NULL);
	env->ant_max = ft_atoi(line);
	ft_putstr("ant_max est OK\n"); 
	return (env);
}

t_env	*init_env(t_env *env)
{
	char *line;

	line = NULL;
	get_next_line(0, &line);
	if (str_is_digit(line) && ft_atoi(line) > 0)
		env = init_env_ant(line);
	free(line);
	return (env);
}

void	parsing_loop(t_env *env)
{
	char *line;

	line = NULL;
	while (get_next_line(0, &line) > 0 && env->wrong_but_set == 0)
		list_parse_init(line, env);
}