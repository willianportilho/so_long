/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 05:14:36 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/15 19:16:45 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"

void	start_map(t_mlx *init)
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
