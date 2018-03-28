/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 19:28:24 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/28 19:28:25 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/fdf.h"

static int	ft_fdf_usage(void)
{
	write(2, "Usage : ./fdf <filename>\n", 25);
	return (1);
}

int			main(int argc, const char **argv)
{
	if (argc != 2)
		return (ft_fdf_usage());
	if (!ft_fdf_engine((char *)argv[1]))
		return (1);
	return (0);
}
