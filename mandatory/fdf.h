/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abattagi <abattagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:51:43 by abattagi          #+#    #+#             */
/*   Updated: 2024/07/05 05:43:44 by abattagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "./../MLX42/include/MLX42/MLX42.h"
# include "fdf_data.h"
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include <stdlib.h>
# define BASE1 "0123456789ABCDEF"
# define BASE2 "0123456789abcdef"
#include<stdio.h>

t_dimensions	ft_dimension(char *map);
t_point			*ft_get_point(char *line, int y, int columns);
void			ft_map(char *map, t_dimensions dm, t_point **map_points, int i);
void			map_parser(char *map, mlx_image_t *img);
void			ft_transformation_z(t_point *point);
void			ft_transformation_x(t_point *point);
void			ft_draw_map(t_point **map_points, t_dimensions dm,
					mlx_image_t *img, t_cdim ndm);
t_cdim			ft_iso_calcul(t_point **map_points, t_dimensions dm);
float			ft_scale_factor(float columns, float rows);
void			ft_zoom(t_point **map_points, t_dimensions dm, t_cdim ndm);
uint32_t		ft_get_color(char *str);
int				test_name(char *str);
void			key_hook(struct mlx_key_data key_data, void *param);
void			ft_exit(int fd);
void			ft_free_exit(char *tmp);
void			ft_error_exit(void);
int				check_map(char *map);
void ft_initial(void);
void ft_columes(char *map, t_dimensions dm);
// static int	rows_count(char *line);

#endif
