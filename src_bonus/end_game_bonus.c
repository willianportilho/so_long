/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 03:02:21 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/19 22:42:59 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	before_close(t_game *game)
{
	close_game("You left the game!", game);
	exit(EXIT_FAILURE);
}

int	close_game(char *message, t_game *game)
{
	clear_xpms(game);
	clear_map(game);
	mlx_destroy_window(game->init.mlx, game->init.win);
	mlx_destroy_display(game->init.mlx);
	free (game->txt.all_map);
	free (game->init.mlx);
	ft_printf("%s\n", message);
	exit(EXIT_SUCCESS);
}

void	you_win_or_lose(int i, t_game *game)
{
	game->num.key_game = 1;
	game->txt.map_lines[game->num.yp][game->num.xp] = game->txt.sprite_curr;
	game->txt.map_lines[game->num.yp + game->num.yp2][\
	game->num.xp + game->num.xp2] = game->txt.sprite_next;
	mlx_destroy_image(game->init.mlx, game->spt.dog);
	if (i == 0)
	{
		game->spt.dog = mlx_xpm_file_to_image(\
		game->init.mlx, "./img/you_win.xpm", &game->num.i, &game->num.j);
	}
	else
	{
		game->spt.dog = mlx_xpm_file_to_image(\
		game->init.mlx, "./img/you_lose.xpm", &game->num.i, &game->num.j);
	}
}
