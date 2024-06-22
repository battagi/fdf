/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abattagi <abattagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:44:14 by abattagi          #+#    #+#             */
/*   Updated: 2023/12/30 17:42:44 by abattagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	c;
	int		i;
	size_t	s1_size;
	char	*pointer;

	c = 0;
	i = 0;
	s1_size = ft_strlen(s1);
	pointer = malloc((s1_size + ft_strlen(s2)) + 1);
	if (pointer == NULL)
		return (NULL);
	while (c < s1_size)
	{
		pointer[c] = s1[c];
		c++;
	}
	while (c < (s1_size + ft_strlen(s2)))
	{
		pointer[c] = s2[i];
		c++;
		i++;
	}
	pointer[c] = '\0';
	return (pointer);
}
