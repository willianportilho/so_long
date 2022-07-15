/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 05:14:36 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/15 05:04:02 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"

void	insert_name(t_mlx *init)
{
	init->wall = mlx_xpm_file_to_image(init->mlx, "./img/wall.xpm", &init->i, &init->j);
	init->coin = mlx_xpm_file_to_image(init->mlx, "./img/coin.xpm", &init->i, &init->j);
	init->hole = mlx_xpm_file_to_image(init->mlx, "./img/hole.xpm", &init->i, &init->j);
	init->hero = mlx_xpm_file_to_image(init->mlx, "./img/hero.xpm", &init->i, &init->j);
	init->ground = mlx_xpm_file_to_image(init->mlx, "./img/ground.xpm", &init->i, &init->j);
}

void	insert_map(t_mlx *init)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	while (init->map_lines[i])
	{
		while (init->map_lines[i][i2])
		{
			if (init->map_lines[i][i2] == '1')
				mlx_put_image_to_window(init->mlx, init->win, init->wall, (i2 * 50), (i * 50));
			else if (init->map_lines[i][i2] == '0')
				mlx_put_image_to_window(init->mlx, init->win, init->ground, (i2 * 50), (i * 50));
			else if (init->map_lines[i][i2] == 'P')
				mlx_put_image_to_window(init->mlx, init->win, init->hero, (i2 * 50), (i * 50));
			else if (init->map_lines[i][i2] == 'C')
				mlx_put_image_to_window(init->mlx, init->win, init->coin, (i2 * 50), (i * 50));
			else if (init->map_lines[i][i2] == 'E')
				mlx_put_image_to_window(init->mlx, init->win, init->hole, (i2 * 50), (i * 50));
			i2++;
		}
		i++;
		i2 = 0;
	}
}
