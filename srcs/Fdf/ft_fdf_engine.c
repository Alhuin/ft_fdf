/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fdf_engine.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 19:27:50 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/28 19:27:52 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/fdf.h"

static int	ft_open_error(int fd, char *file)
{
	if (fd == 1)
		write(1, "No data found\n", 14);
	else
	{
		write(1, "No file ", 8);
		write(1, file, ft_strlen(file));
		write(1, "\n", 1);
	}
	return (FAIL);
}

int			ft_fdf_engine(char *file)
{
	int		fd;
	t_map	*map;

	map = NULL;
	if ((fd = open(file, O_RDONLY)) == -1 || fd == 1)
		return (ft_open_error(fd, file));
	if (ft_fdf_parse(fd, &map) == 0)
		return (close(fd));
	close(fd);
	perspective(map);
	map->mlx.mlx_ptr = mlx_init();
	map->mlx.win_ptr = mlx_new_window(map->mlx.mlx_ptr, WINX, WINY,
			"FDF_WINDOW");
	mlx_key_hook(map->mlx.win_ptr, ft_deal_key, &map);
	ft_fdf_draw(map);
	mlx_loop(map->mlx.mlx_ptr);
	return (SUCCESS);
}
