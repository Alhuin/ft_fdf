/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fdf_test_file.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 19:28:15 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/28 19:28:16 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/fdf.h"

int				ft_fdf_test_map(t_line *read, t_map *map)
{
	t_line *tmp;

	tmp = read;
	while (tmp)
	{
		if (ft_str2dlen(tmp->str) < map->width)
			return (FAIL);
		tmp = tmp->next;
	}
	return (SUCCESS);
}

int				ft_fdf_free_t_dot(t_map **map)
{
	t_dot		**tab;
	int			i;

	i = -1;
	tab = (*map)->tab;
	while (++i < (*map)->height + 1)
		free(tab[i]);
	free(tab);
	(*map)->tab = NULL;
	return (SUCCESS);
}

int				ft_fdf_free(t_line **read, t_map **map)
{
	t_line		*tmp;

	if (read && *read)
	{
		tmp = *read;
		while (tmp)
		{
			ft_freestr2d(tmp->str);
			tmp = tmp->next;
			free(*read);
			*read = tmp;
		}
		free(*read);
		read = NULL;
	}
	if (map && *map)
	{
		if ((*map)->tab)
			ft_fdf_free_t_dot(map);
		free(*map);
		map = NULL;
	}
	return (FAIL);
}
