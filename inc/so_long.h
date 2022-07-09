/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 05:11:31 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/09 04:03:18 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h> // TIRAR DEPOIS
# include <math.h>

void	read_map(char	**map_lines);
void	check_input(int argc, char *argv);
void	check_map(char **map_lines);
char	**get_map(char *argv);

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
}					t_mlx;

#endif