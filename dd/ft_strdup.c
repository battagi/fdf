/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abattagi <abattagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:43:31 by abattagi          #+#    #+#             */
/*   Updated: 2024/01/07 18:29:54 by abattagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *array;
	int size;
	int i;

	i = 0;
	size = 0;
	while (s[size] != '\0')
		size++;

	array = (char *)malloc(size + 1);
	if (array == NULL)
		return (NULL);

	while (i < size)
	{
		array[i] = s[i];
		i++;
	}
	array[i] = '\0';

	return (array);
}