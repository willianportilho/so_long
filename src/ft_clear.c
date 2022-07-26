/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:08:29 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/26 21:05:30 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	clear_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->txt.map_lines[i])
		free (game->txt.map_lines[i++]);
	free (game->txt.map_lines);
}

void	clear_xpms(t_game *game)
{
	mlx_destroy_image(game->init.mlx, game->spt.flower);
	mlx_destroy_image(game->init.mlx, game->spt.bone);
	mlx_destroy_image(game->init.mlx, game->spt.gram);
	mlx_destroy_image(game->init.mlx, game->spt.home);
	mlx_destroy_image(game->init.mlx, game->spt.dog);
}
