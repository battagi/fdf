/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfomation_matrix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abattagi <abattagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:41:31 by abattagi          #+#    #+#             */
/*   Updated: 2024/06/07 16:14:38 by abattagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_transformation_z(t_point *point)
{
	float	y;
	float	x;
	float	tmp;
	float	degree;

	x = point->x;
	y = point->y;
	degree = (45 * (M_PI / 180));
	tmp = x;
	point->x = (cos(degree) * (x)) - (sin(degree) * (y));
	point->y = sin(degree) * tmp + cos(degree) * (y);
}

void	ft_transformation_x(t_point *point)
{
	float	y;
	float	z;
	float	tmp;
	float	degree;

	y = point->y;
	z = point->z;
	degree = atan(1 / sqrt(2));
	tmp = y;
	point->y = (cos(degree) * (y)) - (sin(degree) * (z));
	point->z = (sin(degree) * tmp) + (cos(degree) * (z));
}
