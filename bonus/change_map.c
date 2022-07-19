/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 04:09:25 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/19 05:07:10 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"
#include "../inc/libft.h"

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
	{
		game->num.key_game = 1;
		game->txt.map_lines[game->num.yp][game->num.xp] = game->txt.sprite_curr;
		game->txt.map_lines[game->num.yp + game->num.yp2][\
		game->num.xp + game->num.xp2] = game->txt.sprite_next;
		mlx_destroy_image(game->init.mlx, game->spt.dog);
		game->spt.dog = mlx_xpm_file_to_image(\
		game->init.mlx, "./img/dog_you_win.xpm", &game->num.i, &game->num.j);
	}
}

static void	change_letter(t_game *game)
{
	game->txt.map_lines[game->num.yp][game->num.xp] = game->txt.sprite_curr;
	game->txt.map_lines[game->num.yp + game->num.yp2][\
	game->num.xp + game->num.xp2] = game->txt.sprite_next;
	game->num.yp2 = 0;
	game->num.xp2 = 0;
}

static void	change_dog(char c, t_game *game)
{
	mlx_destroy_image(game->init.mlx, game->spt.dog);
	if (c == 'U')
	{
		game->spt.dog = mlx_xpm_file_to_image(\
		game->init.mlx, "./img/dog_u.xpm", &game->num.i, &game->num.j);
	}
	else if (c == 'D')
	{
		game->spt.dog = mlx_xpm_file_to_image(\
		game->init.mlx, "./img/dog_d.xpm", &game->num.i, &game->num.j);
	}
	else if (c == 'L')
	{
		game->spt.dog = mlx_xpm_file_to_image(\
		game->init.mlx, "./img/dog_l.xpm", &game->num.i, &game->num.j);
	}
	else if (c == 'R')
	{
		game->spt.dog = mlx_xpm_file_to_image(\
		game->init.mlx, "./img/dog_r.xpm", &game->num.i, &game->num.j);
	}
}

void	change_map(char c, t_game *game)
{
	if (c == 'U')
		game->num.yp2 = -1;
	else if (c == 'D')
		game->num.yp2 = 1;
	else if (c == 'L')
		game->num.xp2 = -1;
	else if (c == 'R')
		game->num.xp2 = 1;
	change_dog(c, game);
	if (game->num.n_bones == 0)
		check_exit(c, game);
	check_not_yet(c, game);
	change_letter(game);
	if (game->num.try_exit == 1)
	{
		game->txt.sprite_curr = 'E';
		game->num.try_exit = 0;
	}
	else
		game->txt.sprite_curr = '0';
	game->num.moviments++;
	start_map(game);
	ft_printf("Moviments: %d\n", game->num.moviments);
}
