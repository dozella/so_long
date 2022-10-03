/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <dozella@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:46:12 by dozella           #+#    #+#             */
/*   Updated: 2022/07/01 17:46:47 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;
	t_vars	vars;

	if (argc != 2 || !check_valid_map(&vars, &map, argv[1]))
		ft_exit(&map);
	start_game(&map, &vars);
	return (0);
}
