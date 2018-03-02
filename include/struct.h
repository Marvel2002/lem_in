#ifndef STRUCT_H

#include "libft.h"
#define STRUCT_H

#define ANT 0
#define ROOM 1
#define LINK 2

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
	int ant_name;
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

int		analyse_and_init_tube(char *line_buf, t_env *env);
int		analyse_and_init_room(char *line_buf, t_env *env);
void	free_stdin(t_stdin *stdin_list);
void	free_isset(t_isset *isset);
void	free_link(struct s_room **link, int num_link);
void	free_room(t_room *room);
void	full_free(t_env *env);
t_env	*init_env(void);
void	fill_node_tube(char **tab, t_env *env);
void	add_tube_to_list(t_room *node, t_room *to_add);
void	fill_node_room(char **tab, t_env *env);
t_room	*find_first_room(char **tab, t_env *env);
t_room	*find_second_room(char **tab, t_env *env);
void	init_node_list(t_env *env, t_stdin *line_list, char *line_buf);
void	create_node_list(t_env *env, char *line_buf);
int 	tab_is_valid_two(char **tab, t_env *env);
int		no_match_list(char **tab, t_env *env);
int		tab_is_valid_three(char **tab, t_env *env);
int		parsing_loop(t_env *env);
void	set_path(t_room *start, int path);
int		min_path(t_room *end);
int		path_exists(t_env *env);
t_room	*go_to_next_min(t_room *end, int min);
void	move_ant(t_room *tmp, t_room *end);
void	display_solution(t_room *end, t_env *env);
void	display_list(t_env *env);
int		count_list(t_env *env);
t_room	*find_start(t_env *env);
t_room	*find_end(t_env *env);
int		check_end(t_room *start);
int		tab_len(char **tab);
int		str_is_digit(char *line);
void	restart_start_end(t_env *env);
void	check_comment_start_end(t_env *env, t_stdin *line_list);
void	set_start_end(t_env *env, t_room *room);
int		all_is_set(t_env *env);

#endif