/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abattagi <abattagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:41:27 by abattagi          #+#    #+#             */
/*   Updated: 2024/01/08 16:00:47 by abattagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*space;
	size_t			total_size;

	total_size = size * count;
	space = malloc(total_size);
	if (space == NULL)
		return (NULL);
	ft_memset(space, 0, total_size);
	return ((void *)space);
}
