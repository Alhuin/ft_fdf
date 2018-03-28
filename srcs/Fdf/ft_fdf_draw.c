/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fdf_draw.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 19:27:42 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/28 19:27:43 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/fdf.h"

int			ft_fdf_draw(t_map *map)
{
	int			i;
	int			j;

	i = -1;
	mlx_string_put(map->mlx.mlx_ptr, map->mlx.win_ptr, (WINX - 300) / 3, 10,
	0xffffff,
	"Options: WASD: move || Up and Down: height || + and -: zoom || R: reset");
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (j + 1 < map->width)
				ft_bresenham(map->tab[i][j], map->tab[i][j + 1], map);
			if (i + 1 < map->height)
				ft_bresenham(map->tab[i][j], map->tab[i + 1][j], map);
		}
	}
	return (SUCCESS);
}
