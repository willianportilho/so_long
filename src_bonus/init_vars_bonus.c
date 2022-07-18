/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 05:29:49 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/18 03:17:24 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"
#include "../inc/libft.h"

static void	start_mlx(t_mlx *init)
{
	init->mlx = mlx_init();
	if (init->mlx == NULL)
		put_error("mlx_init error.");
	init->win = mlx_new_window(init->mlx, init->rows * 50, \
	init->cols * 50, "so_long");
	if (init->win == NULL)
	{
		free (init->win);
		put_error("mlx_new_window error.");
	}
}

static void	loading_xpms(t_mlx *init)
{
	init->flower = mlx_xpm_file_to_image(\
	init->mlx, "./img/flower.xpm", &init->i, &init->j);
	init->bone = mlx_xpm_file_to_image(\
	init->mlx, "./img/bone.xpm", &init->i, &init->j);
	init->home = mlx_xpm_file_to_image(\
	init->mlx, "./img/home.xpm", &init->i, &init->j);
	init->dog = mlx_xpm_file_to_image(\
	init->mlx, "./img/dog_r.xpm", &init->i, &init->j);
	init->gram = mlx_xpm_file_to_image(\
	init->mlx, "./img/gram.xpm", &init->i, &init->j);
	init->board = mlx_xpm_file_to_image(\
	init->mlx, "./img/board.xpm", &init->i, &init->j);
}

void	init_vars(t_mlx *init)
{
	init->count = 0;
	init->count2 = 0;
	init->yp2 = 0;
	init->xp2 = 0;
	init->moviments = 0;
	init->try_exit = 0;
	init->sprite_curr = '0';
	init->sprite_next = 'P';
	init->key_game = 0;
	start_mlx(init);
	loading_xpms(init);
}
