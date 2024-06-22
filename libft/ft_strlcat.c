/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abattagi <abattagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:44:17 by abattagi          #+#    #+#             */
/*   Updated: 2024/01/10 15:49:40 by abattagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;
	size_t	index;

	index = 0;
	i = 0;
	while (dst[i] != '\0' && i < size)
	{
		i++;
	}
	while ((i + (index + 1) < size) && (src[index] != '\0'))
	{
		dst[i + index] = src[index];
		index++;
	}
	if (i + index < size)
	{
		dst[i + index] = '\0';
	}
	len = i + ft_strlen(src);
	return (len);
}
