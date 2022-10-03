/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <dozella@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:40:51 by dozella           #+#    #+#             */
/*   Updated: 2022/07/01 21:08:33 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	count_characters(t_map *map, int i)
{
	int	j;

	j = 0;
	while (map->map[i][j])
	{
		if (map->map[i][j] == 'P')
		{
			map->player++;
			if (map->player == 1)
			{
				map->x = j;
				map->y = i;
			}			
		}
		else if (map->map[i][j] == 'E')
			map->exit++;
		else if (map->map[i][j] == 'C')
			map->coin++;
		j++;
	}	
}
