/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 23:19:32 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/03/14 23:19:34 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_moves
{
	int				*up;
	int				*down;
	int				*left;
	int				*right;
}					t_moves;

typedef struct s_bfs
{
	int				x;
	int				y;
	int				index;
	int				position;
	struct s_bfs	*next;
}					t_bfs;
typedef struct s_mlx
{
	char			**map;
	void			*mlx;
	void			*mlx_win;
	void			*wall;
	void			*player;
	void			*enemy;
	void			*door;
	void			*collectible;
	int				height;
	int				width;
	int				player_position[2];
	int				**enemy_position;
	int				num_enemy;
	int				n_mov;
	int				num_coll;
	int				collected;
}					t_mlx;

/**********parsing file****** */
int					ft_error(char *str, char **map, t_bfs **a, int e);
int					check_argument(char *av);
void				*check_image(t_mlx *mlx, char *img);
void				init_value(t_mlx *mlx, int line_size, int n_line);
void				check_new_line(char *buf, char *line, int fd);
/**********map_operations**** */
char				**read_map(int fd, char *line);
int					check_rectangular(char **map);
void				check_wall(char **map, int line);
int					check_map(char **map, int *num_enemy);
void				check_caracter(char **map);
/**********components**** */
int					check_components(char **map, int line_size);
int					count_components(char *str, int line_size, char c);
int					*position(char **map, int line_size, char c);
int					size_queue(t_bfs *a);
int					check_exit(t_bfs *a, int *e);
/************bfs********** */
int					valid_path(char **map, int line_size);
int					valid_moves(char **map, int *p, t_bfs **a, int index);
int					the_first(t_bfs *a, int *p, int *count, int check);
t_bfs				**bfs(char **map, int *collectible, int *p, int *e);
t_bfs				**fill_queue(char **map, int *p, int *coll);
/************queue_operations */
int					isvisited(t_bfs *a, int x, int y);
t_bfs				*new_node(int x, int y, int index);
t_bfs				*last_node(t_bfs *a);
void				add_next(t_bfs **a, int x, int y, int index);
t_bfs				*queue_position(t_bfs *a);

/*************utils********* */
int					the_same_index(t_bfs *a, int index);
void				change_moves(int *x, int *y, int moves);
void				find_enemies(t_mlx *mlx);
void				player_animation(char **path, char move);
void				put_image_to_window(t_mlx *mlx, int i, int j, int change);

/*************screen ********/
void				screen(t_mlx *mlx, int line_size, int n_line,
						int num_enemy);
void				display_images(t_mlx *mlx, int change);
int					clean_all(t_mlx *mlx);
int					key_press(int key_code, t_mlx *mlx);

/*************player_moves */
void				move_player(t_mlx *mlx, int x, int y, char move);
void				player_move(t_mlx *mlx);
void				move_enemy(t_mlx *mlx);
void				animation(t_mlx *mlx);
void				player(t_mlx *mlx, char **path);
/**************so_long* */
void				free_array(char **map);
void				clear_queue(t_bfs **a);
#endif
