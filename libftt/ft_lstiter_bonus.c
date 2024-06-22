/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abattagi <abattagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:33:11 by abattagi          #+#    #+#             */
/*   Updated: 2024/01/11 20:33:12 by abattagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// void print_content(void *content)
// {
//     printf("Content: %s\n", (char *)content);
// }
// // int main()
// // {
// // t_list *lst = ft_lstnew("Hello");
// // ft_lstadd_back(&lst, ft_lstnew("World"));
// // ft_lstiter(lst, print_content);
// // }