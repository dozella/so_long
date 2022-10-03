/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <dozella@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:44:26 by dozella           #+#    #+#             */
/*   Updated: 2022/07/01 17:44:46 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	read_map(t_vars *vars, t_map *map, const char *file_name)
{
	char	*tmp;

	tmp = NULL;
	vars->fd = open(file_name, O_RDONLY);
	if (vars->fd < 0)
		return (0);
	while (1)
	{
		tmp = get_next_line(vars->fd);
		if (!tmp)
			break ;
		if (*tmp == '\n')
		{
			free (tmp);
			return (0);
		}
		vars->line_map = ft_strjoin(vars->line_map, tmp);
		free(tmp);
	}
	map->map = ft_split(vars->line_map, '\n');
	free(vars->line_map);
	close (vars->fd);
	return (1);
}
