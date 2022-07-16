/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 05:14:36 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/16 05:10:00 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"

static void	put_sprite(t_mlx *init)
{
	mlx_put_image_to_window(init->mlx, init->win, \
	init->sprite, (init->count2 * 50), (init->count * 50));
}

void	start_map(t_mlx *init)
{
	while (init->map_lines[init->count])
	{
		while (init->map_lines[init->count][init->count2])
		{
			if (init->map_lines[init->count][init->count2] == '1')
				init->sprite = init->wall;
			else if (init->map_lines[init->count][init->count2] == '0')
				init->sprite = init->ground;
			else if (init->map_lines[init->count][init->count2] == 'P')
				init->sprite = init->hero;
			else if (init->map_lines[init->count][init->count2] == 'C')
				init->sprite = init->coin;
			else if (init->map_lines[init->count][init->count2] == 'E')
				init->sprite = init->hole;
			put_sprite(init);
			init->count2++;
		}
		init->count++;
		init->count2 = 0;
	}
	init->count = 0;
	update_map(init);
}
