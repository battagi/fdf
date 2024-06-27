/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale_factor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abattagi <abattagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:08:36 by abattagi          #+#    #+#             */
/*   Updated: 2024/06/22 20:47:12 by abattagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	_inbase(char c)
{
	int	i;

	i = 0;
	while (BASE1[i] && BASE2[i])
	{
		if (c == BASE1[i] || c == BASE2[i])
			return (i + 1);
		i++;
	}
	return (0);
}

uint32_t	ft_hexaa(char *str)
{
	uint32_t	res;
	int			i;

	i = 0;
	if (!str)
		return (i);
	res = 0;
	while (str[i] && _inbase(str[i]))
	{
		res = (res * 16) + _inbase(str[i]) - 1;
		i++;
	}
	if (ft_strlen(str) == 8)
		return (res);
	return ((res << 8) | 0x000000FF);
}

uint32_t	ft_get_color(char *str)
{
	char		**spl;
	uint32_t	color;
	char		*tmp;

	if (!str)
		return (0xFFFFFFFF);
	spl = ft_split(str, ',');
	if (!spl || ft_split_count(spl) != 2)
		return (ft_free(spl), 0xFFFFFFFF);
	if (!ft_strncmp(spl[1], "0x", 2))
		tmp = &spl[1][2];
	else
		tmp = spl[1];
	color = ft_hexaa(tmp);
	return (ft_free(spl), color);
}

float	ft_scale_factor(float columns, float rows)
{
	float	scale_f;

	if (1100 / columns < 1100 / rows)
		scale_f = 1100 / columns;
	else
		scale_f = 1100 / rows;
	return (scale_f);
}

void	ft_zoom(t_point **map_points, t_dimensions dm, t_cdim ndm)
{
	int	i;
	int	j;

	i = 0;
	while (i < dm.rows)
	{
		j = 0;
		while (j < dm.columns)
		{
			map_points[i][j].x = (map_points[i][j].x * ndm.scale_factor) + ((0
						- ndm.min_x) * ndm.scale_factor);
			map_points[i][j].y = (map_points[i][j].y * ndm.scale_factor) + ((0
						- ndm.min_y) * ndm.scale_factor);
			j++;
		}
		i++;
	}
}
