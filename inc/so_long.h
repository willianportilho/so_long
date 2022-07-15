/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 05:11:31 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/15 05:41:05 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <math.h>
# include <X11/X.h>

# define KEY_ESCAPE	(0xff1b)
# define KEY_ABNT_A	(0x61)
# define KEY_ABNT_W	(0x77)
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
	int		count;
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

void	read_map(t_mlx *init);
void	insert_map(t_mlx *init);
void	insert_name(t_mlx *init);
void	check_input(int argc, char *argv);
void	check_map(t_mlx *init);
void	clear_map(t_mlx *init);
void	get_map(t_mlx *init, char *argv);
void	map_error(char *message, t_mlx *init);
void	init_vars(t_mlx *init);

#endif