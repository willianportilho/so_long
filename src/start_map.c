/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 05:14:36 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/16 03:42:05 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"

void	start_map(t_mlx *init)
{
	while (init->map_lines[init->count])
	{
		while (init->map_lines[init->count][init->count2])
		{
			if (init->map_lines[init->count][init->count2] == '1')
				mlx_put_image_to_window(init->mlx, init->win, \
				init->wall, (init->count2 * 50), (init->count * 50));
			else if (init->map_lines[init->count][init->count2] == '0')
				mlx_put_image_to_window(init->mlx, init->win, \
				init->ground, (init->count2 * 50), (init->count * 50));
			else if (init->map_lines[init->count][init->count2] == 'P')
				mlx_put_image_to_window(init->mlx, init->win, \
				init->hero, (init->count2 * 50), (init->count * 50));
			else if (init->map_lines[init->count][init->count2] == 'C')
				mlx_put_image_to_window(init->mlx, init->win, \
				init->coin, (init->count2 * 50), (init->count * 50));
			else if (init->map_lines[init->count][init->count2] == 'E')
				mlx_put_image_to_window(init->mlx, init->win, \
				init->hole, (init->count2 * 50), (init->count * 50));
			init->count2++;
		}
		init->count++;
		init->count2 = 0;
	}
	init->count = 0;
	found_p(init);
}
