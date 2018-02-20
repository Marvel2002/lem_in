#ifndef STRUCT_H

#include "libft.h"
#define STRUCT_H

typedef struct 	s_isset
{
	int		room_is_set;
	int		tube_is_set;
	int		start_is_set;
	int		end_is_set;
}				t_isset;

typedef	struct  s_room
{
	char *name;
	int x;
	int y;
	int start;
	int end;
	struct s_room *next;
}				t_room;

typedef struct 	s_env
{
	int	ant_max;
	int	wrong_but_set;
	int	next_room_is_start;
	int	next_room_is_end;
	t_room **list;
	t_isset *isset;
}				t_env;

int		tab_len(char **tab);
int		str_is_digit(char *line);
int		tab_is_valid_three(char **tab);
void	set_start_end(char **tab, t_env *env);
t_env 	*init_env_ant(char *line);
t_env	*init_env(t_env *env);
void	parsing_loop(t_env *env);
void	add_node(char **tab, t_env *env);
void	list_parse_init(char *line, t_env *env);
int		all_is_set(t_env *env);
void	display_exit(int exit);
void	ft_exit(t_env *env);

#endif