/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 05:11:31 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/26 21:10:13 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "./libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <X11/X.h>

# define KEY_ESC	(0xff1b)
# define KEY_W		(0x77)
# define KEY_A		(0x61)
# define KEY_S		(0x73)
# define KEY_D		(0x64)
# define UP			(0xff52)
# define DOWN		(0xff54)
# define LEFT		(0xff51)
# define RIGHT		(0xff53)

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}			t_mlx;

typedef struct s_sprite
{
	void	*flower;
	void	*home;
	void	*bone;
	void	*gram;
	void	*dog;
	void	*sprite;
	void	*board;
	void	*mad_dog;
}			t_sprite;

typedef struct s_text
{
	char	sprite_curr;
	char	sprite_next;
	char	*all_map;
	char	**map_lines;
}			t_text;

typedef struct s_number
{
	int		i;
	int		j;
	int		cols;
	int		rows;
	int		xp;
	int		yp;
	int		xp2;
	int		yp2;
	int		count;
	int		count2;
	int		n_bones;
	int		moviments;
	int		try_exit;
	int		key_game;
	int		index;
	int		c;
	int		e;
	int		p;
	int		m;
	int		key;
}			t_number;

typedef struct s_game
{
	t_mlx		init;
	t_sprite	spt;
	t_text		txt;
	t_number	num;
}				t_game;

void	start_map(t_game *game);
void	put_error(char *message);
void	check_input(int argc, char *argv);
void	check_map(t_game *game);
void	clear_map(t_game *game);
void	clear_xpms(t_game *game);
void	get_map(t_game *game, char *argv);
void	map_error(char *message, t_game *game);
void	init_vars(t_game *game);
int		reprint(t_game *game);
int		close_game(char *message, t_game *game);
void	update_map(t_game *game);
void	change_map(char c, int yp2, int xp2, t_game *game);
int		before_close(t_game *game);
int		handle_input(int keysym, t_game *game);
void	put_counter(t_game *game);
void	change_dog(char c, t_game *game);
void	you_win_or_lose(int i, t_game *game);
int		animation(t_game *game);

#endif