/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 05:11:31 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/18 03:54:44 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <math.h>
# include <X11/X.h>

# define KEY_ESCAPE	(0xff1b)
# define KEY_ABNT_W	(0x77)
# define KEY_ABNT_A	(0x61)
# define KEY_ABNT_S	(0x73)
# define KEY_ABNT_D	(0x64)

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*flower;
	void	*home;
	void	*bone;
	void	*gram;
	void	*dog;
	void	*sprite;
	void	*board;
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
	char	sprite_curr;
	char	sprite_next;
	char	*all_map;
	char	**map_lines;
}			t_mlx;

void	start_map(t_mlx *init);
void	put_error(char *message);
void	check_input(int argc, char *argv);
void	check_map(t_mlx *init);
void	clear_map(t_mlx *init);
void	clear_xpms(t_mlx *init);
void	get_map(t_mlx *init, char *argv);
void	map_error(char *message, t_mlx *init);
void	init_vars(t_mlx *init);
int		reprint(t_mlx *init);
int		close_game(char *message, t_mlx *init);
void	update_map(t_mlx *init);
void	change_map(char c, t_mlx *init);
int		before_close(t_mlx *init);
int		handle_input(int keysym, t_mlx *init);
void	put_counter(t_mlx *init);

#endif