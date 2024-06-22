/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abattagi <abattagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:44:01 by abattagi          #+#    #+#             */
/*   Updated: 2024/01/03 18:00:27 by abattagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*temp1;
	const unsigned char	*temp2;
	size_t				index;

	if (dest == NULL && src == NULL)
		return (NULL);
	temp1 = dest;
	temp2 = src;
	index = 0;
	while (index < n)
	{
		temp1[index] = temp2[index];
		index++;
	}
	return (dest);
}
