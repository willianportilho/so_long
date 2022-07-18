/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 03:02:21 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/18 22:18:51 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"
#include "../inc/libft.h"

int	before_close(t_game *game)
{
	close_game("You left the game!", game);
	return (1);
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
