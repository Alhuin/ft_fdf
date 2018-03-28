/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fdf_parse.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 19:27:59 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/28 19:28:00 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/fdf.h"

static int		ft_fdf_add_line(t_line **read, char *line)
{
	t_line		*new;
	t_line		*tmp;

	tmp = *read;
	if (!(new = (t_line*)malloc(sizeof(t_line))))
		return (FAIL);
	new->next = NULL;
	new->str = ft_strsplit(line, ' ');
	if (*read == NULL)
		*read = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (SUCCESS);
}

static int		ft_fdf_read(int fd, t_line **read)
{
	char		*line;
	int			hei;

	hei = 0;
	line = NULL;
	while (get_next_line(fd, &line) != 0)
	{
		if ((ft_fdf_add_line(read, line)) == 0)
			return (FAIL);
		ft_strdel(&line);
		hei++;
	}
	ft_strdel(&line);
	return (hei);
}

static int		ft_fdf_init_map(t_map **map)
{
	t_mlx		mlx;

	mlx.mlx_ptr = NULL;
	mlx.win_ptr = NULL;
	if (!(*map = (t_map *)malloc(sizeof(t_map))))
		return (FAIL);
	(*map)->width = 0;
	(*map)->height = 0;
	(*map)->begx = WINX / 16;
	(*map)->begy = WINY / 16;
	(*map)->zoom = 0;
	(*map)->z_size = 3;
	(*map)->mlx = mlx;
	(*map)->tab = NULL;
	return (SUCCESS);
}

int				ft_fdf_init_zoom(t_map **map)
{
	int			hei;
	int			wid;
	int			zom;

	zom = 0;
	hei = (*map)->height;
	wid = (*map)->width;
	while (((zom * hei) / 2) + (wid * zom) < WINX - (WINX / 8))
		zom++;
	(*map)->zoom = zom;
	zom = 0;
	while (hei * zom < WINY - (WINY / 8))
		zom++;
	(*map)->zoom = ((*map)->zoom < zom ? (*map)->zoom : zom);
	return (SUCCESS);
}

int				ft_fdf_parse(int fd, t_map **map)
{
	t_line		*read;

	read = NULL;
	if (ft_fdf_init_map(map) == 0)
		return (FAIL);
	if (((*map)->height = ft_fdf_read(fd, &read)) == 0)
		return (FAIL);
	(*map)->width = ft_str2dlen(read->str);
	if (!(ft_fdf_test_map(read, *map)))
	{
		write(2, "Invalid map\n", 12);
		return (ft_fdf_free(&read, map));
	}
	if (ft_fdf_put_in_tab(read, *map) == 0)
		return (FAIL);
	ft_fdf_init_zoom(map);
	return (SUCCESS);
}
