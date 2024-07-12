/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abattagi <abattagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:51:18 by abattagi          #+#    #+#             */
/*   Updated: 2024/07/05 22:35:38 by abattagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_parser(char *map, mlx_image_t *img)
{
	t_dimensions	dm;
	t_point			**map_points;
	t_cdim			nwdm;
	int				i;

	ft_initial();
	dm = ft_dimension(map);
	map_points = malloc(sizeof(t_point *) * dm.rows);
	if (!map_points)
		exit(1);
	ft_map(map, dm, map_points, 0);
	ft_columes(map, dm);
	nwdm = ft_iso_calcul(map_points, dm);
	ft_draw_map(map_points, dm, img, nwdm);
	i = 0;
	while (i < dm.rows)
	{
		free(map_points[i]);
		i++;
	}
	free(map_points);
}

void	key_hook(struct mlx_key_data key_data, void *param)
{
	mlx_t	*mlx;

	mlx = (mlx_t *)param;
	if (key_data.os_key == 53)
	{
		mlx_terminate(mlx);
		exit(0);
	}
}

int	test_name(char *str)
{
	int		i;
	char	*fdf;

	i = (ft_strlen(str) - 4);
	fdf = ".fdf";
	while (str[i])
	{
		if (str[i] != *fdf)
			return (1);
		i++;
		fdf++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	if (argc == 2 && test_name(argv[1]) == 0 && check_map(argv[1]) != 1)
	{
		mlx = mlx_init(1920, 1200, "FDF", false);
		if (!mlx)
			return (1);
		img = mlx_new_image(mlx, 1920, 1200);
		if (!img)
			return (1);
		map_parser(argv[1], img);
		mlx_image_to_window(mlx, img, 0, 0);
		mlx_key_hook(mlx, key_hook, mlx);
		mlx_loop(mlx);
	}
	else
	{
		write(1, "error\n", 6);
		exit(1);
	}
}
