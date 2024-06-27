/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abattagi <abattagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:09:13 by abattagi          #+#    #+#             */
/*   Updated: 2024/06/26 18:56:28 by abattagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DATA_H
# define FDF_DATA_H

# include "fdf.h"
# define FDF_HEIGHT 1200
# define FDF_WIDTH 1920

typedef struct s_dimensions
{
	int			columns;
	int			rows;

}				t_dimensions;

typedef struct s_point
{
	float		x;
	float		y;
	float		z;
	uint32_t	color;

}				t_point;

typedef struct s_increment
{
	float		x;
	float		y;
	int			steps;
}				t_increment;

typedef struct s_cdim
{
	float		min_x;
	float		max_x;
	float		min_y;
	float		max_y;
	float		t_x;
	float		t_y;
	float		scale_factor;
}				t_cdim;
#endif
