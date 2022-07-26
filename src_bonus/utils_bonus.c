/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:25:54 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/26 21:06:40 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	put_counter(t_game *game)
{
	char	*str;

	str = ft_itoa(game->num.moviments);
	mlx_put_image_to_window(game->init.mlx, game->init.win, \
	game->spt.board, 0, 0);
	mlx_string_put(game->init.mlx, game->init.win, 9, 19, 0xffffff, "MOVES:");
	mlx_string_put(game->init.mlx, game->init.win, 16, 37, 0xffffff, str);
	free (str);
}

int	handle_input(int ksym, t_game *game)
{
	if (ksym == KEY_ESC)
		close_game("You left the game!", game);
	if (((ksym == KEY_W) || (ksym == UP)) && (game->num.key_game == 0))
	{
		if (game->txt.map_lines[game->num.yp - 1][game->num.xp] != '1')
			change_map('U', -1, 0, game);
	}
	else if (((ksym == KEY_S) || (ksym == DOWN)) && (game->num.key_game == 0))
	{
		if (game->txt.map_lines[game->num.yp + 1][game->num.xp] != '1')
			change_map('D', 1, 0, game);
	}
	else if (((ksym == KEY_A) || (ksym == LEFT)) && (game->num.key_game == 0))
	{
		if (game->txt.map_lines[game->num.yp][game->num.xp - 1] != '1')
			change_map('L', 0, -1, game);
	}
	else if (((ksym == KEY_D) || (ksym == RIGHT)) && (game->num.key_game == 0))
	{
		if (game->txt.map_lines[game->num.yp][game->num.xp + 1] != '1')
			change_map('R', 0, 1, game);
	}
	return (0);
}

int	reprint(t_game *game)
{
	start_map(game);
	return (0);
}

void	update_map(t_game *game)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	game->num.xp = 0;
	game->num.yp = 0;
	game->num.n_bones = 0;
	while (game->txt.map_lines[i])
	{
		while (game->txt.map_lines[i][i2])
		{
			if (game->txt.map_lines[i][i2] == 'P')
			{
				game->num.xp = i2;
				game->num.yp = i;
			}
			if (game->txt.map_lines[i][i2] == 'C')
				game->num.n_bones++;
			i2++;
		}
		i++;
		i2 = 0;
	}
}

void	change_dog(char c, t_game *game)
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
