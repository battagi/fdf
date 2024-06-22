/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abattagi <abattagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:44:35 by abattagi          #+#    #+#             */
/*   Updated: 2024/01/03 17:08:08 by abattagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*new;
	size_t	index;

	if ((start >= ft_strlen(s)))
		return (ft_strdup(""));
	s_len = ft_strlen(s);
	if (s_len < len + start)
		len = s_len - start;
	new = (char *)malloc((len + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	index = 0;
	while (index < len)
	{
		new[index] = s[start + index];
		index++;
	}
	new[index] = '\0';
	return (new);
}
