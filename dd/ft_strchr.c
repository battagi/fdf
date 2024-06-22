/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abattagi <abattagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:44:13 by abattagi          #+#    #+#             */
/*   Updated: 2024/01/08 15:42:05 by abattagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int character)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)character)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == (unsigned char)character)
		return ((char *)str + i);
	return (NULL);
}
// int main()
// {
// 	printf("%s",ft_strchr( "teste", 357));
// 	printf("\n");
// 	printf("%s",strchr( "teste", 357));
// }