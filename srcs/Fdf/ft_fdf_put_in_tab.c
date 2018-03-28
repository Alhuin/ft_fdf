/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fdf_put_in_tab.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 19:28:08 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/28 19:28:09 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/fdf.h"

static int		ft_fdf_create_tab(t_map *map)
{
	int			i;

	i = -1;
	if (!(map->tab = (t_dot **)malloc(sizeof(t_dot *) * map->height + 1)))
		return (FAIL);
	while (++i < map->height)
		if (!(map->tab[i] = (t_dot *)malloc(sizeof(t_dot) * map->width + 1)))
			return (FAIL);
	return (SUCCESS);
}

static t_dot	ft_fdf_new_dot(int y, int x, int z)
{
	t_dot		new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

int				ft_fdf_put_in_tab(t_line *read, t_map *map)
{
	int			i;
	int			j;
	t_line		*tmp;

	tmp = read;
	i = -1;
	if (ft_fdf_create_tab(map) == 0)
		return (FAIL);
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
			map->tab[i][j] = ft_fdf_new_dot(i, j, ft_atoi(tmp->str[j]));
		tmp = tmp->next;
	}
	ft_fdf_free(&read, NULL);
	return (SUCCESS);
}
