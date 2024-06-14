/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abattagi <abattagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:52:12 by abattagi          #+#    #+#             */
/*   Updated: 2024/06/07 18:22:34 by abattagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dimensions	ft_dimension(char *map)
{
	int				fd;
	char			**tmp;
	char			*line;
	t_dimensions	dm;
	int				i;

	i = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), exit(1), dm);
	dm.rows = 1;
	tmp = ft_split(line, ' ');
	dm.columns = ft_split_count(tmp);
	while (get_next_line(fd))
	{
		dm.rows = dm.rows + 1;
	}
	ft_free(tmp);
	free(line);
	close(fd);
	return (dm);
}

t_point	*ft_get_point(char *line, int y, int columns, int rows)
{
	t_point	*point;
	char	**tmp;
	int		i;

	(void)rows;
	i = 0;
	tmp = ft_split(line, ' ');
	point = malloc(sizeof(t_point) * columns);
	if (!point)
		exit(1);
	while (tmp[i] && i < columns)
	{
		point[i].x = i;
		point[i].y = y;
		point[i].z = ft_atoi(tmp[i]);
		ft_transformation_z(&point[i]);
		ft_transformation_x(&point[i]);
		point[i].color = ft_get_color(tmp[i]);
		i++;
	}
	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
	return (point);
}
t_point	**ft_map(char *map, t_dimensions dm)
{
	t_point	**map_points;
	char	*line;
	int		fd;
	int		i;

	i = 0;
	map_points = malloc(sizeof(t_point *) * dm.rows);
	if (!map_points)
		exit(1);
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line && i < dm.rows)
	{
		map_points[i] = ft_get_point(line, i, dm.columns, dm.rows);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	return (map_points);
}
