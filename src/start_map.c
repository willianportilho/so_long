/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 05:14:36 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/17 23:12:52 by wportilh         ###   ########.fr       */
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
				init->sprite = init->flower;
			else if (init->map_lines[init->count][init->count2] == '0')
				init->sprite = init->gram;
			else if (init->map_lines[init->count][init->count2] == 'P')
				init->sprite = init->dog;
			else if (init->map_lines[init->count][init->count2] == 'C')
				init->sprite = init->bone;
			else if (init->map_lines[init->count][init->count2] == 'E')
				init->sprite = init->home;
			put_sprite(init);
			init->count2++;
		}
		init->count++;
		init->count2 = 0;
	}
	init->count = 0;
	update_map(init);
}
