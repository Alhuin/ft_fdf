/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/24 15:20:01 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/28 15:17:54 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/fdf.h"

static void			ft_swap_points(t_dot *a, t_dot *b)
{
	int tmpy;
	int tmpx;

	tmpy = a->y;
	tmpx = a->x;
	a->y = b->y;
	b->y = tmpy;
	a->x = b->x;
	b->x = tmpx;
}

static void			ft_put_color(t_dot a, t_dot b, t_seg *seg, t_map *map)
{
	int az;
	int bz;

	az = a.z * map->z_size;
	bz = b.z * map->z_size;
	if (az == 0 && bz == 0)
		mlx_pixel_put(map->mlx.mlx_ptr, map->mlx.win_ptr, seg->x, seg->y,
				0x7FDD4C);
	else if (az > 0 && az < 40 && bz > 0 && bz < 40)
		mlx_pixel_put(map->mlx.mlx_ptr, map->mlx.win_ptr, seg->x, seg->y,
				0xDAB30A);
	else if (az >= 40 && bz >= 40)
		mlx_pixel_put(map->mlx.mlx_ptr, map->mlx.win_ptr, seg->x, seg->y,
				0xffffff);
	else if (az <= -40 && bz <= -40)
		mlx_pixel_put(map->mlx.mlx_ptr, map->mlx.win_ptr, seg->x, seg->y,
				0xff0000);
	else if (az != bz)
		mlx_pixel_put(map->mlx.mlx_ptr, map->mlx.win_ptr, seg->x, seg->y,
				0x87591A);
	else
		mlx_pixel_put(map->mlx.mlx_ptr, map->mlx.win_ptr, seg->x, seg->y,
				250250250);
}

static void			ft_trace_seg(t_seg *seg, t_dot a, t_dot b, t_map *map)
{
	int i;

	i = -1;
	if (seg->dx > seg->dy)
	{
		while (++i <= seg->dx)
		{
			seg->x = (b.x - a.x < 0 ? a.x - i : a.x + i);
			seg->y = a.y + seg->m * i;
			FT_ROUND(seg->y);
			ft_put_color(a, b, seg, map);
		}
	}
	else
	{
		while (++i <= seg->dy)
		{
			seg->y = a.y + i;
			seg->x = (b.x - a.x < 0 && seg->dx != seg->dy ? a.x - seg->m * i :
					a.x + seg->m * i);
			FT_ROUND(seg->x);
			ft_put_color(a, b, seg, map);
		}
	}
}

static int			ft_init_seg(t_seg *seg, t_dot *a, t_dot *b)
{
	seg->dx = b->x - a->x;
	if (seg->dx < 0)
		ft_swap_points(a, b);
	seg->dx = FT_ABS(seg->dx);
	seg->dy = b->y - a->y;
	if (seg->dy < 0)
		ft_swap_points(a, b);
	seg->dy = FT_ABS(seg->dy);
	if (seg->dy > seg->dx)
		seg->m = (float)seg->dx / (float)seg->dy;
	else
		seg->m = (float)seg->dy / (float)seg->dx;
	if (seg->dy == seg->dx)
	{
		if (a->x > b->x && a->y < b->y)
			seg->m = -1;
		else
			seg->m = 1;
	}
	return (0);
}

int					ft_bresenham(t_dot a, t_dot b, t_map *map)
{
	t_seg	seg;

	ft_init_seg(&seg, &a, &b);
	ft_trace_seg(&seg, a, b, map);
	return (0);
}
