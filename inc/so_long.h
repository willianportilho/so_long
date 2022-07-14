/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 05:11:31 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/14 21:38:30 by wportilh         ###   ########.fr       */
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
	void	*hero;
	int		i;
	int		j;
}			t_mlx;

typedef struct s_cep
{
	int	i;
	int	c;
	int	e;
	int	p;
}	t_cep;

void	read_map(char **map_lines);
void	insert_map(t_mlx *init);
void	check_input(int argc, char *argv);
void	check_map(char **all_map);
void	clear_map(char ***map_lines);
char	*get_map(char *argv);
void	map_error(char *message, char **all_map);

#endif