/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   keys.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 14:54:16 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/28 18:33:45 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/fdf.h"

static void			ft_move(int key, t_map **map)
{
	if (key == 13)
		(*map)->begy -= 20;
	if (key == 1)
		(*map)->begy += 20;
	if (key == 0)
		(*map)->begx -= 20;
	if (key == 2)
		(*map)->begx += 20;
	if (key == 78)
	{
		(*map)->begx -= 10;
		(*map)->begy -= 10;
		(*map)->zoom -= 5;
	}
	if (key == 69)
	{
		(*map)->begx += 10;
		(*map)->begy += 10;
		(*map)->zoom += 5;
	}
}

int					ft_deal_key(int key, t_map **map)
{
	if (key == 53)
	{
		ft_fdf_free(NULL, map);
		exit(0);
	}
	if (key == 126)
		(*map)->z_size++;
	if (key == 125)
		(*map)->z_size--;
	if (key == 15)
	{
		ft_fdf_init_zoom(map);
		(*map)->begx = WINX / 16;
		(*map)->begy = WINY / 16;
		(*map)->z_size = 3;
	}
	ft_move(key, map);
	mlx_clear_window((*map)->mlx.mlx_ptr, (*map)->mlx.win_ptr);
	perspective(*map);
	ft_fdf_draw(*map);
	return (0);
}
