/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <dozella@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:46:44 by dozella           #+#    #+#             */
/*   Updated: 2022/07/01 21:11:09 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WALL "images/wall.xpm"
# define PLAYER "images/player.xpm"
# define EXIT "images/exit.xpm"
# define COIN "images/collectible.xpm"
# define FLOOR "images/floor.xpm"

# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"

typedef struct s_map{
	char	**map;
	int		coin;
	int		exit;
	int		player;
	int		x;
	int		y;
	int		rows;
	int		columns;
}			t_map;

typedef struct s_vars{
	t_map	*map;
	void	*mlx;
	void	*mlx_win;
	int		fd;
	int		pxl_x;
	int		pxl_y;
	long	count_steps;
	char	*line_map;
	void	*img_wall;
	void	*img_player;
	void	*img_coin;
	void	*img_floor;
	void	*img_exit;
}			t_vars;

char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
void	ft_exit(t_map *map);
void	start_game(t_map *map, t_vars *vars);
int		end_prog(t_vars *vars);
void	draw_map(t_map *map, t_vars *vars);
void	ft_putnbr(int n);
void	ft_exit_win(t_vars *vars);

void	count_characters(t_map *map, int i);
int		check_valid_map(t_vars *vars, t_map *map, const char *file_name);
int		read_map(t_vars *vars, t_map *map, const char *file_name);

void	ft_init_vars(t_vars *vars);
void	ft_init_map(t_map *map);

void	move_up(t_vars *vars);
void	move_down(t_vars *vars);
void	move_left(t_vars *vars);
void	move_right(t_vars *vars);

#endif