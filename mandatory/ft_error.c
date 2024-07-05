/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abattagi <abattagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:21:58 by abattagi          #+#    #+#             */
/*   Updated: 2024/07/04 22:07:39 by abattagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error_exit(void)
{	
	write(1, "error\n", 1);
	exit(1);
}
int	check_map(char *map)
{
	int	fd;
	char	**tmp;
	char	*line;
	int count ;
	count = 0;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		ft_exit(fd);
	tmp = ft_split(line, ' ');
	if (!tmp)
		ft_exit(fd);
	count = ft_split_count(tmp);
	free(line);
	close(fd);
	if(count == 0)
		return 1;
	return count;
}
