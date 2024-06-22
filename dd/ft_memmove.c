/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abattagi <abattagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:30:31 by abattagi          #+#    #+#             */
/*   Updated: 2024/01/04 22:56:29 by abattagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		index;
	char		*dest_char;
	const char	*src_char;

	index = 0;
	dest_char = (char *)dest;
	src_char = (const char *)src;
	if (dest_char > src_char)
	{
		while (n > index)
		{
			dest_char[n - 1] = src_char[n - 1];
			n--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
