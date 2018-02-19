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
	t_room **list;
}				t_env;

#endif