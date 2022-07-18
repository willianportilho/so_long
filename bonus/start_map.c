/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 05:14:36 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/18 22:19:06 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"
#include "../inc/libft.h"

static void	put_sprite(t_game *game)
{
	mlx_put_image_to_window(game->init.mlx, game->init.win, \
	game->spt.sprite, (game->num.count2 * 50), (game->num.count * 50));
}

void	start_map(t_game *game)
{
	while (game->txt.map_lines[game->num.count])
	{
		while (game->txt.map_lines[game->num.count][game->num.count2])
		{
			if (game->txt.map_lines[game->num.count][game->num.count2] == '1')
				game->spt.sprite = game->spt.flower;
			if (game->txt.map_lines[game->num.count][game->num.count2] == '0')
				game->spt.sprite = game->spt.gram;
			if (game->txt.map_lines[game->num.count][game->num.count2] == 'P')
				game->spt.sprite = game->spt.dog;
			if (game->txt.map_lines[game->num.count][game->num.count2] == 'C')
				game->spt.sprite = game->spt.bone;
			if (game->txt.map_lines[game->num.count][game->num.count2] == 'E')
				game->spt.sprite = game->spt.home;
			put_sprite(game);
			game->num.count2++;
		}
		game->num.count++;
		game->num.count2 = 0;
	}
	game->num.count = 0;
	put_counter(game);
	update_map(game);
}
