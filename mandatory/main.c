/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abattagi <abattagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:36:40 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/07 16:15:06 by abattagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_parser(char *map, mlx_image_t *img)
{
	t_dimensions	dm;
	t_point			**map_points;
	t_cdim			nwdm;

	dm = ft_dimension(map);
	map_points = ft_map(map, dm);
	nwdm = ft_iso_calcul(map_points, dm);
	ft_draw_map(map_points, dm, img, nwdm);
}

int	main(int argc, char **argv)
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	
	t_dimensions	b;
	t_point			b1;
	t_increment		b2;
	t_cdim			b3;
	
	(void)argc;
	ft_bzero(&b2, sizeof(t_increment));
	ft_bzero(&b3, sizeof(t_cdim));
	ft_bzero(&b, sizeof(t_dimensions));
	ft_bzero(&b1, sizeof(t_point));
	mlx = mlx_init(1920, 1200, "FDF", false);
	if (!mlx)
		return (1);
	img = mlx_new_image(mlx, 1920, 1200);
	if (!img)
		return (1);
	map_parser(argv[1], img);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
}
