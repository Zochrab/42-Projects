/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:27:40 by zblume            #+#    #+#             */
/*   Updated: 2024/06/04 13:19:44 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Includes
# include "../libs/printflibft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include "../includes/messages.h" 
//# include "../libs/minilibx-linux/mlx_int.h"

//Macros
# define KEY_ESC		65307
# define KEY_W			119
# define KEY_S			115
# define KEY_A			97
# define KEY_D			100
# define KEY_LEFT		65361
# define KEY_RIGHT		65363
# define KEY_UP			65362
# define KEY_DOWN		65364
# define KEY_Q			113


//Image Macro
# define IMG			32
# define WIDTH			1920
# define HEIGHT		 	1080

//Structures
typedef struct s_img
{
	void	*player;
	void	*wall;
	void	*ground;
	void	*exit;
	void	*collect;
}			t_img;

typedef struct s_map
{
	int		fd;
	char	**matrix;
	int		c;
	int		cleft;
	int		e;
	int		p;
	int		*p_pos;
	int		*exit_pos;
	int		**collect_pos;
	int		depth;
}			t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_img	*img;
	int		x;
	int		y;
	int		w;
	int		h;
	int		collect;
	int		exit;
	int		player;
	int		move;
}			t_data;

//Gaming
void			move_player(t_data *data, int key);

//Map
void			*read_map(char *argv, t_data *data);
void			check_border(t_data *data);
void			find_path(t_data *data, t_map *map);
int				**init_collect(t_map *map);

//Image
void			assign_images(t_data *data);
void			draw_map(t_data *data);
void			draw_player(t_data *data);

//Error Handling
void			error_handler(int num);
void			map_error(int num, t_data *data);
void			check_windowsize(t_data *data);

//Free
void			free_data(t_data *data);
void			free_map(t_map *map);
void			free_vis(t_map *map, char **vis);
void			close_win(void *param);
void			free_images(t_data *data);
int				end_game(t_data *data);

//MLX
int				key_hook(int key, t_data *data);

//Utils
int				mat_depth(char **matrix);

//Debug
void			print_map(t_map *map);
void			print_vis(char **vis);
void			print_collectibles(int **collect, int c);

//Error Codes
# define READ_ERROR		0
# define NOT_BER_FILE	1
# define INVALID_MAP	2
# define WRONG_SYMBOLS	3
# define NO_SOLUTION	4
# define WINDOW_ERROR	5

#endif
