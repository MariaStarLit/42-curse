/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:56:02 by mde-avel          #+#    #+#             */
/*   Updated: 2023/09/11 14:42:44 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

//get_next_line.c
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <X11/X.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# define WALL "./sprites/Arvore_64.xpm"
# define EMPTY_SPACE "./sprites/Relva_64.xpm"
# define PLAYER_UP "./sprites/Ash_back_64.xpm"
# define PLAYER_DOWN "./sprites/Ash_front_64.xpm"
# define PLAYER_LEFT "./sprites/Ash_left_64.xpm"
# define PLAYER_RIGHT "./sprites/Ash_right_64.xpm"
# define COLLECT_1 "./sprites/Sylveon_64.xpm"
# define COLLECT_2 "./sprites/Leafeon_64.xpm"
# define COLLECT_3 "./sprites/Flareon_64.xpm"
# define COLLECT_4 "./sprites/Jolteon_64.xpm"
# define COLLECT_5 "./sprites/Umbreon_64.xpm"
# define EXIT "./sprites/Pokeball_64.xpm"
//keys
# define ESC 65307
# define A 97
# define D 100
# define S 115
# define W 119

typedef struct s_sprites
{
	int		w;
	int		h;
	int		eevees_nbr;
	void	*wall;
	void	*empty;
	void	*p_down;
	void	*p_left;
	void	*p_right;
	void	*p_up;
	void	*c_1;
	void	*c_2;
	void	*c_3;
	void	*c_4;
	void	*c_5;
	void	*exit;
}	t_sprites;

typedef struct s_map
{
	char		**matrix;
	void		*mlx;
	void		*window;
	size_t		n_lines;
	size_t		len_line;
	int			n_exit;
	int			n_players;
	int			n_collect;
	t_sprites	img;
}	t_map;

typedef struct s_clone
{
	char		**matris;
	int			n_exit;
	int			n_players;
	int			n_collect;
	size_t		exit_x;
	size_t		exit_y;
}	t_clone;

typedef struct s_player
{
	size_t		x;
	size_t		y;
	int			n_collect;
	int			n_moves;
}	t_player;

//main.c
int			create_matrix(char *map_path, int flag);
int			read_map(char *map_file, int flag);

//util.c
t_map		*map(void);
t_clone		*clone_m(void);
t_player	*player(void);

//get_next_line.c
size_t		ft_strlen_gnl(const char *str);
char		*ft_strjoin_gnl(char const *line, char const *buffer);
char		*get_next_line(int fd);
char		*to_long(int flag, char *buffer, int fd);

//check_map.c
int			check_side_walls(char **matris);
int			check_tb_walls(char **matris);
int			check_n_items(void);
int			register_map_components(char **matris);
int			check_map(char **matris);

//check_map_path.c
int			valid_path(void);
void		check_map_path(char **matris, size_t y, size_t x);
int			create_map_clone(char **matrix);

//draw_map.c
void		create_images(t_sprites *img);
void		draw_map(void);
void		draw_window(void);
void		draw_n_moves(void);

//draw_map_2.c
void		draw_tree(t_sprites	*img, size_t y, size_t x);
void		draw_grass(t_sprites *img, size_t y, size_t x);
void		draw_player(t_sprites *img, size_t y, size_t x);
void		draw_eevee(t_sprites *img, size_t y, size_t x);
void		draw_pokeball(t_sprites	*img, size_t y, size_t x);

//hooks.c
int			move_up(void);
int			move_down(void);
int			move_left(void);
int			move_right(void);
int			hook(int key);

//exit_game.c
void		collect_items(size_t y, size_t x);
void		exit_pokeball(void);
void		free_map(char **matriz);
int			exit_game(void);

#endif