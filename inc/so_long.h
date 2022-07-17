/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 05:11:31 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/17 21:02:05 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	void	*wall;
	void	*hole;
	void	*coin;
	void	*ground;
	void	*hero;
	void	*sprite;
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
	int		n_coins;
	int		moviments;
	int		try_exit;
	int		key_game;
	char	sprite_curr;
	char	sprite_next;
	char	*all_map;
	char	**map_lines;
}			t_mlx;

typedef struct s_cep
{
	int	i;
	int	c;
	int	e;
	int	p;
}	t_cep;

void	start_map(t_mlx *init);
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

#endif