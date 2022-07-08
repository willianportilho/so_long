/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 05:01:18 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/08 01:26:50 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"

void	read_map(char	**map_lines)
{
	t_mlx	init;
	void	*wall;
	void	*ground;
	void	*hero;
	void	*coin;
	void	*hole;
	int		i;
	int		j;
	int		i2;
	int		j2;
	int		index;
	int		index2;

	index = 0;
	index2 = 0;
	init.mlx = mlx_init();
	init.win = mlx_new_window(init.mlx, 500, 500, "so_long");
	wall = mlx_xpm_file_to_image(init.mlx, "./img/wall.xpm", &i, &j);
	ground = mlx_xpm_file_to_image(init.mlx, "./img/ground.xpm", &i, &j);
	hero = mlx_xpm_file_to_image(init.mlx, "./img/hero.xpm", &i, &j);
	coin = mlx_xpm_file_to_image(init.mlx, "./img/coin.xpm", &i, &j);
	hole = mlx_xpm_file_to_image(init.mlx, "./img/hole.xpm", &i, &j);
	while (map_lines[index])
	{
		while (map_lines[index][index2])
		{
			if (map_lines[index][index2] == '1')
				mlx_put_image_to_window(init.mlx, init.win, wall, (index2 * 50), (index * 50));
			else if (map_lines[index][index2] == '0')
				mlx_put_image_to_window(init.mlx, init.win, ground, (index2 * 50), (index * 50));
			else if (map_lines[index][index2] == 'P')
				mlx_put_image_to_window(init.mlx, init.win, hero, (index2 * 50), (index * 50));
			else if (map_lines[index][index2] == 'C')
				mlx_put_image_to_window(init.mlx, init.win, coin, (index2 * 50), (index * 50));
			else if (map_lines[index][index2] == 'E')
				mlx_put_image_to_window(init.mlx, init.win, hole, (index2 * 50), (index * 50));
			index2++;
		}
		index++;
		index2 = 0;
	}
	mlx_loop(init.mlx);
}
