/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abattagi <abattagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:43:42 by abattagi          #+#    #+#             */
/*   Updated: 2023/12/30 15:19:01 by abattagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	size;
	char	*new;
	size_t	index;

	size = ft_strlen(s);
	new = malloc(size + 1);
	if (new == NULL)
		return (NULL);
	index = 0;
	while (index < size)
	{
		new[index] = f(index, s[index]);
		index++;
	}
	new[index] = '\0';
	return (new);
}

// char map_function(unsigned int index, char c)
// {
//     if (c >= 'a' && c <= 'z') {
//         return (c - 32);
//     }
//     return (c);
// }
// int main(void)
// {
//     const char *original = "Hello, World!";

//     // Testing ft_strmapi with the example map_function
//     char *result = ft_strmapi(original, map_function);

//     if (result != NULL)
//     {
//         printf("Original string: %s\n", original);
//         printf("Mapped string:   %s\n", result);

//         // Don't forget to free the memory allocated by ft_strmapi
//         free(result);
//     }
//     else
//     {
//         printf("Memory allocation failed.\n");
//     }

//     return (0);
// }
