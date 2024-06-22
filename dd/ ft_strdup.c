/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ft_strdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abattagi <abattagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:43:31 by abattagi          #+#    #+#             */
/*   Updated: 2023/12/26 23:43:32 by abattagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*pointer;

	size = ft_strlen(s1);
	pointer = malloc(size + 1);
	if (pointer == NULL)
		return (NULL);
	ft_strcpy(pointer, s1);
	return (pointer);
}
