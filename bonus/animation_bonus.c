/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 07:19:47 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/19 08:36:27 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"
#include "../inc/libft.h"

static void	delay(int i)
{
	int	i2;
	int	i3;

	i2 = 0;
	i3 = 0;
	while (i2 < i)
	{
		while (i3 < i2)
			i3++;
		i2++;
	}
}

static void	define_animation(char *str, t_game *game)
{
	delay (7000000);
	mlx_destroy_image(game->init.mlx, game->spt.bone);
	game->spt.bone = mlx_xpm_file_to_image(\
	game->init.mlx, str, &game->num.i, &game->num.j);
	start_map(game);
}

int	animation(t_game *game)
{
	define_animation("./img/bone_2.xpm", game);
	define_animation("./img/bone_3.xpm", game);
	define_animation("./img/bone_2.xpm", game);
	define_animation("./img/bone.xpm", game);
	return (0);
}
