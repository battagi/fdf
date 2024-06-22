/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abattagi <abattagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:44:02 by abattagi          #+#    #+#             */
/*   Updated: 2023/12/30 16:43:27 by abattagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;
	size_t			index;

	temp = s;
	index = 0;
	while (index < n)
	{
		temp[index] = (unsigned char)c;
		index++;
	}
	return (s);
}
