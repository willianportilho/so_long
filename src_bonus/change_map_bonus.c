/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 04:09:25 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/26 21:06:24 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static void	check_not_yet(char c, t_game *game)
{
	int	check;

	check = 0;
	if ((game->txt.map_lines[game->num.yp - 1][game->num.xp] == 'E') \
	&& (c == 'U'))
		check = 1;
	if ((game->txt.map_lines[game->num.yp + 1][game->num.xp] == 'E') \
	&& (c == 'D'))
		check = 1;
	if ((game->txt.map_lines[game->num.yp][game->num.xp - 1] == 'E') \
	&& (c == 'L'))
		check = 1;
	if ((game->txt.map_lines[game->num.yp][game->num.xp + 1] == 'E') \
	&& (c == 'R'))
		check = 1;
	if (check == 1)
	{
		mlx_destroy_image(game->init.mlx, game->spt.dog);
		game->spt.dog = mlx_xpm_file_to_image(\
		game->init.mlx, "./img/dog_woof.xpm", &game->num.i, &game->num.j);
		game->num.try_exit = 1;
	}
}

static void	check_exit(char c, t_game *game)
{
	int	check;

	check = 0;
	if ((game->txt.map_lines[game->num.yp - 1][game->num.xp] == 'E') \
	&& (c == 'U'))
		check = 1;
	if ((game->txt.map_lines[game->num.yp + 1][game->num.xp] == 'E') \
	&& (c == 'D'))
		check = 1;
	if ((game->txt.map_lines[game->num.yp][game->num.xp - 1] == 'E') \
	&& (c == 'L'))
		check = 1;
	if ((game->txt.map_lines[game->num.yp][game->num.xp + 1] == 'E') \
	&& (c == 'R'))
		check = 1;
	if (check == 1)
		you_win_or_lose(0, game);
}

static void	check_dead(char c, t_game *game)
{
	int	check;

	check = 0;
	if ((game->txt.map_lines[game->num.yp - 1][game->num.xp] == 'M') \
	&& (c == 'U'))
		check = 1;
	if ((game->txt.map_lines[game->num.yp + 1][game->num.xp] == 'M') \
	&& (c == 'D'))
		check = 1;
	if ((game->txt.map_lines[game->num.yp][game->num.xp - 1] == 'M') \
	&& (c == 'L'))
		check = 1;
	if ((game->txt.map_lines[game->num.yp][game->num.xp + 1] == 'M') \
	&& (c == 'R'))
		check = 1;
	if (check == 1)
		you_win_or_lose(1, game);
}

static void	change_letter(t_game *game)
{
	game->txt.map_lines[game->num.yp][game->num.xp] = game->txt.sprite_curr;
	game->txt.map_lines[game->num.yp + game->num.yp2][\
	game->num.xp + game->num.xp2] = game->txt.sprite_next;
}

void	change_map(char c, int yp2, int xp2, t_game *game)
{
	game->num.yp2 = yp2;
	game->num.xp2 = xp2;
	change_dog(c, game);
	check_dead(c, game);
	if (game->num.n_bones == 0)
		check_exit(c, game);
	check_not_yet(c, game);
	change_letter(game);
	if (game->num.try_exit == 1)
		game->txt.sprite_curr = 'E';
	else
		game->txt.sprite_curr = '0';
	game->num.try_exit = 0;
	game->num.moviments++;
	start_map(game);
}
