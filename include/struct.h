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
	int ant;
	int start;
	int end;
	int	path;
	int	check;
	struct s_room *next;
	struct s_room **link;
	int	num_link;
}				t_room;

typedef struct 	s_stdin
{
	char *line;
	struct s_stdin *next;
}				t_stdin;

typedef struct 	s_env
{
	int	ant_max;
	int	next_room_is_start;
	int	next_room_is_end;
	int	end_is_found;
	t_stdin *stdin_list;
	t_room *room;
	t_isset *isset;
}				t_env;

t_env	*init_env(void);
void	fill_node_room(char **tab, t_env *env);
int		analyse_and_init_tube(char *line_buf, t_env *env);
int		analyse_and_init_room(char *line_buf, t_env *env);
void	init_node_list(t_env *env, t_stdin *line_list, char *line_buf);
void	create_node_list(t_env *env, char *line_buf);
int 	tab_is_valid_two(char **tab, t_env *env);
int		tab_is_valid_three(char **tab, t_env *env);
int		parsing_loop(t_env *env);
int		tab_len(char **tab);
int		str_is_digit(char *line);
void	display_list(t_env *env);
int		count_list(t_env *env);
void	restart_start_end(t_env *env);
void	check_comment_start_end(t_env *env, t_stdin *line_list);
void	set_start_end(t_env *env, t_room *room);
int		all_is_set(t_env *env);
int		no_match_list(char **tab, t_env *env);

#endif