#include "struct.h"

void	add_node(char **tab, t_env *env)
{
	t_room *node;

	node = (t_room *)ft_memalloc(sizeof(t_room));
	if (node)
	{
		node->name = ft_strdup(tab[0]);
		node->x = ft_atoi(tab[1]);
		node->y = ft_atoi(tab[2]);
		if (env->next_room_is_start == 1)
		{
			node->start = 1;
			env->isset->start_is_set = 1;
			ft_putendl("cette room est START");
			env->next_room_is_start++;
		}
		else if (env->next_room_is_end == 1)
		{
			node->end = 1;
			env->isset->end_is_set = 1;
			env->next_room_is_end++;
			ft_putendl("cette room est END");
		}
		if (!env->room)
		{
			env->room = node;
			ft_putstr("Premier maillon crée, nom de la room = ");
			ft_putendl(node->name);
			ft_putstr("Les coordonnees de la salle sont ");
			ft_putnbr(node->x);
			ft_putstr(" et ");
			ft_putnbr(node->y);
			ft_putchar('\n');

		}
		else
		{
			node->next = env->room;
			env->room = node;
			env->isset->room_is_set = 1;
			ft_putstr("Maillon crée sur liste existante, nom de la room = ");
			ft_putendl(node->name);
			ft_putstr("Les coordonnees de la salle sont ");
			ft_putnbr(node->x);
			ft_putstr(" et ");
			ft_putnbr(node->y);
			ft_putchar('\n');
		}
	}
}

