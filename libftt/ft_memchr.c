/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abattagi <abattagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:43:59 by abattagi          #+#    #+#             */
/*   Updated: 2024/01/11 20:38:29 by abattagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*temp;
	unsigned char		cchar;
	size_t				index;

	temp = s;
	cchar = c;
	index = 0;
	while (index < n)
	{
		if (temp[index] == cchar)
			return (size_t *)(temp + index);
		index++;
	}
	return (NULL);
}
