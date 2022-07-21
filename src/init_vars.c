/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 05:29:49 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/19 04:57:28 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	start_mlx(t_game *game)
{
	game->init.mlx = mlx_init();
	if (game->init.mlx == NULL)
		put_error("mlx_init error.");
	game->init.win = mlx_new_window(game->init.mlx, game->num.rows * 50, \
	game->num.cols * 50, "so_long");
	if (game->init.win == NULL)
	{
		free (game->init.win);
		put_error("mlx_new_window error.");
	}
}

static void	loading_xpms(t_game *game)
{
	game->spt.flower = mlx_xpm_file_to_image(\
	game->init.mlx, "./img/flower.xpm", &game->num.i, &game->num.j);
	game->spt.bone = mlx_xpm_file_to_image(\
	game->init.mlx, "./img/bone.xpm", &game->num.i, &game->num.j);
	game->spt.home = mlx_xpm_file_to_image(\
	game->init.mlx, "./img/home.xpm", &game->num.i, &game->num.j);
	game->spt.dog = mlx_xpm_file_to_image(\
	game->init.mlx, "./img/dog_r.xpm", &game->num.i, &game->num.j);
	game->spt.gram = mlx_xpm_file_to_image(\
	game->init.mlx, "./img/gram.xpm", &game->num.i, &game->num.j);
}

void	init_vars(t_game *game)
{
	game->num.count = 0;
	game->num.count2 = 0;
	game->num.yp2 = 0;
	game->num.xp2 = 0;
	game->num.moviments = 0;
	game->num.try_exit = 0;
	game->num.key_game = 0;
	game->txt.sprite_curr = '0';
	game->txt.sprite_next = 'P';
	start_mlx(game);
	loading_xpms(game);
}
