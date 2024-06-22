/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abattagi <abattagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:41:23 by abattagi          #+#    #+#             */
/*   Updated: 2024/01/04 22:55:56 by abattagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	index_start;
	size_t	index_end;
	char	*new;
	size_t	index;

	index_start = 0;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[index_start]))
		index_start++;
	index_end = ft_strlen(s1);
	while (index_end > index_start && ft_strchr(set, s1[index_end]))
		index_end--;
	if ((index_end - index_start) <= 0)
		return (NULL);
	new = (char *)malloc((index_end - index_start + 1) + 1);
	if (new == NULL)
		return (NULL);
	index = 0;
	while (index < (index_end - index_start + 1))
	{
		new[index] = s1[index_start + index];
		index++;
	}
	new[index] = '\0';
	return (new);
}

// int main(void)
// {
//     // Example usage of ft_strtrim
//     const char *s1 = "   Hello, World!   ";
//     const char *set = " ";

//     char *trimmed = ft_strtrim(s1, set);

//         printf("Original string: \"%s\"\n", s1);
//         printf("Trimmed string:  \"%s\"\n", trimmed);

//         free(trimmed);

//     return (0);
// }