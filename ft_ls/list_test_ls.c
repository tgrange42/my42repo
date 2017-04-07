#include "ft_ls.h"

t_info*t_info_new(char *name, char type)
{
	t_info*new				;

	if (!(new = (t_info *)ft_memalloc(sizeof(new))))
		return (NULL);
	if (type == 4)
		new->type = 'd';
	else
		new->type = '-';
	new->name = ft_strdup(name);
	return (new);
}
