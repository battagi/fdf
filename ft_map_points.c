/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abattagi <abattagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:52:12 by abattagi          #+#    #+#             */
/*   Updated: 2024/07/01 12:04:24 by abattagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dimensions	ft_dimension(char *map)
{
	int				fd;
	char			**tmp;
	char			*line;
	t_dimensions	dm;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		ft_exit(fd);
	dm.rows = 1;
	tmp = ft_split(line, ' ');
	if (!tmp)
		ft_exit(fd);
	dm.columns = ft_split_count(tmp);
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		dm.rows++;
		free(line);
		line = get_next_line(fd);
	}
	ft_free(tmp);
	close(fd);
	return (dm);
}

t_point	*ft_get_point(char *line, int y, int columns)
{
	t_point	*point;
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_split(line, ' ');
	if (!tmp)
	{
		ft_free(tmp);
		ft_free_exit(line);
	}
	point = malloc(sizeof(t_point) * columns);
	if (!point)
		ft_free_exit(line);
	while (tmp[i] != '\0' && i < columns)
	{
		point[i].x = i;
		point[i].y = y;
		point[i].z = ft_atoi(tmp[i]);
		ft_transformation_z(&point[i]);
		ft_transformation_x(&point[i]);
		point[i].color = ft_get_color(tmp[i]);
		i++;
	}
	return (ft_free(tmp), point);
}

void	ft_map(char *map, t_dimensions dm, t_point **map_points, int i)
{
	char	*line;
	int		fd;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		while (i < dm.rows && map_points[i])
		{
			free(map_points[i]);
			i++;
		}
		free(map_points);
		free(line);
		exit(1);
	}
	while (line && i < dm.rows)
	{
		map_points[i] = ft_get_point(line, i, dm.columns);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
}
