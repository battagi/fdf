/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iso_calcul.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abattagi <abattagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:08:53 by abattagi          #+#    #+#             */
/*   Updated: 2024/06/27 14:32:44 by abattagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cdim	calcul_dm(t_point **map_points, t_dimensions dm)
{
	t_cdim	newdm;
	int		i;
	int		j;

	i = 0;
	newdm.min_x = map_points[0][0].x;
	newdm.min_y = map_points[0][0].y;
	while (i < dm.rows)
	{
		j = 0;
		while (j < dm.columns)
		{
			if (newdm.min_x > map_points[i][j].x)
				newdm.min_x = map_points[i][j].x;
			if (newdm.max_x < map_points[i][j].x)
				newdm.max_x = map_points[i][j].x;
			if (newdm.min_y > map_points[i][j].y)
				newdm.min_y = map_points[i][j].y;
			if (newdm.max_y < map_points[i][j].y)
				newdm.max_y = map_points[i][j].y;
			j++;
		}
		i++;
	}
	return (newdm);
}

t_cdim	ft_iso_calcul(t_point **map_points, t_dimensions dm)
{
	t_cdim	dem;

	dem = calcul_dm(map_points, dm);
	dem.t_x = dem.max_x - dem.min_x;
	dem.t_y = dem.max_y - dem.min_y;
	dem.scale_factor = ft_scale_factor(dem.t_x, dem.t_y);
	return (dem);
}
