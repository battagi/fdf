/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abattagi <abattagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:09:00 by abattagi          #+#    #+#             */
/*   Updated: 2024/07/01 13:16:09 by abattagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_increment	ft_steps(t_point p1, t_point p2)
{
	t_increment	increment;
	float		delta_x;
	float		delta_y;
	float		steps;

	delta_x = p2.x - p1.x;
	delta_y = p2.y - p1.y;
	if (fabs(delta_x) > fabs(delta_y))
		steps = fabs(delta_x);
	else
		steps = fabs(delta_y);
	increment.steps = fabs(steps);
	increment.x = delta_x / steps;
	increment.y = delta_y / steps;
	return (increment);
}

void	ft_draw_line(t_point p1, t_point p2, mlx_image_t *img, t_cdim ndm)
{
	t_increment	factors;
	t_point		tmp;
	int			i;

	factors = ft_steps(p1, p2);
	tmp = p1;
	(void)ndm;
	tmp.x = tmp.x + (FDF_WIDTH - (ndm.t_x * ndm.scale_factor)) / 2;
	tmp.y = tmp.y + (FDF_HEIGHT - (ndm.t_y * ndm.scale_factor)) / 2;
	i = 0;
	while (i < factors.steps)
	{
		if (tmp.x < FDF_WIDTH && tmp.y < FDF_HEIGHT && tmp.x >= 0 && tmp.y >= 0)
			mlx_put_pixel(img, tmp.x, tmp.y, tmp.color);
		tmp.x += factors.x;
		tmp.y += factors.y;
		i++;
	}
}

void	ft_draw_map(t_point **map_points, t_dimensions dm, mlx_image_t *img,
		t_cdim ndm)
{
	t_point	tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_zoom(map_points, dm, ndm);
	while (i < dm.rows)
	{
		j = 0;
		while (j < dm.columns)
		{
			tmp = map_points[i][j];
			if (j != dm.columns - 1)
				ft_draw_line(tmp, map_points[i][j + 1], img, ndm);
			if (i != dm.rows - 1)
				ft_draw_line(tmp, map_points[i + 1][j], img, ndm);
			j++;
		}
		i++;
	}
}
