/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <dozella@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:45:35 by dozella           #+#    #+#             */
/*   Updated: 2022/07/01 17:45:38 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_map	map;
	t_vars	vars;

	if (argc != 2 || !check_valid_map(&vars, &map, argv[1]))
		ft_exit(&map);
	start_game(&map, &vars);
	return (0);
}
