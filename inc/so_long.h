/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 05:11:31 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/16 01:14:16 by wportilh         ###   ########.fr       */
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
	int		i;
	int		j;
	int		cols;
	int		rows;
	int		xp;
	int		yp;
	int		count;
	int		count2;
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
int		close_game(t_mlx *init);
void	found_p(t_mlx *init);
//int		handle_keyrelease(int keysym, void *data);
int		handle_input(int keysym, t_mlx *init);

#endif