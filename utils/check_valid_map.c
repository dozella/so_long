/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <dozella@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:38:13 by dozella           #+#    #+#             */
/*   Updated: 2022/07/01 21:08:33 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_line(t_map *map, int i)
{
	int	j;

	if (i == 0)
	{
		map->columns = ft_strlen(map->map[i]) - 1;
		map->rows++;
		return (1);
	}
	else if (map->columns != ft_strlen(map->map[i]) - 1)
		return (0);
	j = 0;
	while (map->map[i][j])
	{
		if (map->map[i][j] != '0' && map->map[i][j] != '1'
			&& map->map[i][j] != 'C' && map->map[i][j] != 'E'
				&& map->map[i][j] != 'P')
			return (0);
		j++;
	}
	map->rows++;
	return (1);
}

int	check_valid_file(const char *file_name)
{
	int	i;

	i = 0;
	while (file_name[i])
		i++;
	if (file_name[i - 4] != '.' || file_name[i - 3] != 'b'
		|| file_name[i - 2] != 'e' || file_name[i - 1] != 'r')
		return (0);
	return (1);
}

int	check_valid_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (i == 0 && map->map[i][j] != '1')
				return (0);
			else if ((j == 0 || j == map->columns) && map->map[i][j] != '1')
				return (0);
			else if (i == map->rows - 1 && map->map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_valid_map(t_vars *vars, t_map *map, const char *file_name)
{
	int	i;

	ft_init_map(map);
	ft_init_vars(vars);
	if (!check_valid_file(file_name) || !read_map(vars, map, file_name))
		return (0);
	i = -1;
	while (map->map[++i])
	{
		if (!check_line(map, i))
			return (0);
		count_characters(map, i);
	}
	if (!check_valid_walls(map))
		return (0);
	if (!map->coin || !map->exit || map->player != 1)
		return (0);
	return (1);
}
