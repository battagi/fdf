/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abattagi <abattagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:43:40 by abattagi          #+#    #+#             */
/*   Updated: 2023/12/30 16:38:35 by abattagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;
	size_t			index;

	temp = s;
	index = 0;
	while (index < n)
	{
		temp[index] = 0;
		index++;
	}
}
