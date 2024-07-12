/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abattagi <abattagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:21:58 by abattagi          #+#    #+#             */
/*   Updated: 2024/07/05 22:36:08 by abattagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error_exit(void)
{
	write(1, "error\n", 1);
	exit(1);
}

void	ft_exit(int fd)
{
	close(fd);
	write(1, "error\n", 6);
	exit(1);
}

void	ft_free_exit(char *tmp)
{
	free(tmp);
	exit(1);
}
