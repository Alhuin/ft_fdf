/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 19:28:39 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/28 19:28:42 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
*********************************INCLUDES
*/

# include "../libft/ft_libft/libft.h"
# include "../minilibx/mlx.h"

/*
**********************************DEFINES
*/

# define FAIL 0
# define SUCCESS 1
# define WINX 1600
# define WINY 900
# define FT_ABS(Value) Value < 0 ? (-Value) : Value
# define FT_ROUND(Value) (int)(Value + 0.5)

/*
**********************************STRUCTURES
*/

typedef struct		s_dot
{
	int				x;
	int				y;
	int				z;
	int				col;
}					t_dot;

typedef struct		s_line
{
	char			**str;
	struct s_line	*next;
}					t_line;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_mlx;

typedef struct		s_map
{
	int				width;
	int				height;
	int				begx;
	int				begy;
	int				zoom;
	int				z_size;
	t_mlx			mlx;
	t_dot			**tab;
}					t_map;

typedef struct		s_seg
{
	int				x;
	int				y;
	int				dx;
	int				dy;
	float			m;
}					t_seg;

/*
**********************************FUNCTIONS
*/

int					ft_fdf_engine(char *file);
int					ft_fdf_parse(int fd, t_map **map);
int					ft_bresenham(t_dot a, t_dot b, t_map *map);
int					ft_fdf_apply_modifs(t_map *map);
int					ft_fdf_draw(t_map *map);
int					ft_fdf_put_in_tab(t_line *read, t_map *map);
int					ft_deal_key(int key, t_map **map);
int					perspective(t_map *map);
int					ft_fdf_test_map(t_line *read, t_map *map);
int					ft_fdf_free(t_line **read, t_map **map);
int					ft_fdf_init_zoom(t_map **map);

#endif
