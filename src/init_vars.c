/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 05:29:49 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/15 20:54:51 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"

static void	start_mlx(t_mlx *init)
{
	init->mlx = mlx_init();
	if(init->mlx == NULL)
		return ;
	init->win = mlx_new_window(init->mlx, 500, 500, "so_long");
	if(init->win == NULL)
	{
		free (init->win);
		return ;
	}
}

static void loading_xpms(t_mlx *init)
{
	init->wall = mlx_xpm_file_to_image(init->mlx, "./img/wall.xpm", &init->i, &init->j);
	init->coin = mlx_xpm_file_to_image(init->mlx, "./img/coin.xpm", &init->i, &init->j);
	init->hole = mlx_xpm_file_to_image(init->mlx, "./img/hole.xpm", &init->i, &init->j);
	init->hero = mlx_xpm_file_to_image(init->mlx, "./img/hero.xpm", &init->i, &init->j);
	init->ground = mlx_xpm_file_to_image(init->mlx, "./img/ground.xpm", &init->i, &init->j);
}

void	init_vars(t_mlx *init)
{
	start_mlx(init);
	loading_xpms(init);
}