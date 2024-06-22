/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abattagi <abattagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:44:29 by abattagi          #+#    #+#             */
/*   Updated: 2023/12/26 23:45:28 by abattagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *n, size_t l)
{
	size_t	i;
	size_t	x;
	size_t	a;

	i = 0;
	if (n[i] == '\0')
		return ((char *)s);
	if (l == 0)
		return (NULL);
	while (s[i] != '\0' && i < l)
	{
		x = 0;
		a = i;
		while (s[a] == n[x] && a < l)
		{
			if (n[x + 1] == '\0')
				return ((char *)s + i);
			x++;
			a++;
		}
		i++;
	}
	return (0);
}
