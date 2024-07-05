/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abattagi <abattagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:44:53 by abattagi          #+#    #+#             */
/*   Updated: 2024/07/05 05:49:01 by abattagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	ft_initial(void)
{
	t_increment		b2;
	t_dimensions	b1;
	t_point			b3;
	t_cdim			b4;

	ft_bzero(&b2, sizeof(t_increment));
	ft_bzero(&b1, sizeof(t_dimensions));
	ft_bzero(&b3, sizeof(t_point));
	ft_bzero(&b4, sizeof(t_cdim));
}
static int	rows_count(char *line)
{
	int	rows;

	rows = 0;
	while (*line)
	{
		while (*line && *line == ' ')
			line++;
		if (*line)
			rows++;
		while (*line && *line != ' ')
			line++;
	}
	return (rows);
}
void	ft_columes(char *map, t_dimensions dm)
{
	int		fd;
	int		first_row;
	char	*str;
	int 	i;
	i	= 0;	

	fd = open(map, O_RDONLY);
	first_row = dm.columns;
	str = get_next_line((fd));
	while (str)
	{	
		
		i = rows_count(str);
		if (i != first_row)
		{
			write(1, "error\n", 6);
			exit(1);
		}
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
}
