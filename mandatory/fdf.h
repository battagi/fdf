/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abattagi <abattagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:41:07 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/22 15:55:00 by abattagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libftt/libft.h"
# include "./../MLX42/include/MLX42/MLX42.h"
# include "fdf_data.h"
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# define BASE1 "0123456789ABCDEF"
# define BASE2 "0123456789abcdef"

t_dimensions	ft_dimension(char *map);
t_point			*ft_get_point(char *line, int y, int columns, int rows);
t_point			**ft_map(char *map, t_dimensions dm);
void			map_parser(char *map, mlx_image_t *img);
void			ft_transformation_z(t_point *point);
void			ft_transformation_x(t_point *point);
void			ft_draw_map(t_point **map_points, t_dimensions dm,
					mlx_image_t *img, t_cdim ndm);
t_cdim			ft_iso_calcul(t_point **map_points, t_dimensions dm);
float			ft_scale_factor(float columns, float rows);
void			ft_zoom(t_point **map_points, t_dimensions dm, t_cdim ndm);
uint32_t		ft_get_color(char *str);

#endif