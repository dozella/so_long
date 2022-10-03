/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <dozella@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:46:03 by dozella           #+#    #+#             */
/*   Updated: 2022/07/01 21:17:53 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define WALL "images/wall_bonus.xpm"
# define PLAYER1 "images/player_bonus_1.xpm"
# define PLAYER2 "images/player_bonus_2.xpm"
# define PLAYER3 "images/player_bonus_3.xpm"
# define EXIT "images/exit_bonus.xpm"
# define COIN "images/collectible_bonus.xpm"
# define FLOOR "images/floor_bonus.xpm"
# define ENEMY1 "images/enemy1.xpm"
# define ENEMY2 "images/enemy2.xpm"
# define ENEMY3 "images/enemy3.xpm"

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
	int		enemy;
}			t_map;

typedef struct s_vars{
	t_map	*map;
	int		steps;
	void	*mlx;
	void	*mlx_win;
	int		fd;
	int		pxl_x;
	int		pxl_y;
	long	count_steps;
	char	*line_map;
	void	*img_wall;
	void	*img_player[3];
	void	*img_coin;
	void	*img_floor;
	void	*img_exit;
	void	*img_enemy[3];
}			t_vars;

char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
void	ft_exit(t_map *map);
void	start_game(t_map *map, t_vars *vars);
int		end_prog(t_vars *vars);
void	draw_map(t_map *map, t_vars *vars);
char	*ft_itoa(int n);
void	animation(t_vars *vars);
void	ft_exit_lost(t_vars *vars);
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
void	enemy_move_left(t_vars	*vars);
void	enemy_move_right(t_vars	*vars);

#endif