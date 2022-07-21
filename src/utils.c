/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:25:54 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/19 05:58:22 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	handle_input(int ksym, t_game *game)
{
	if (ksym == KEY_ESC)
		close_game("You left the game!", game);
	else if ((ksym == KEY_W) && (game->num.key_game == 0))
	{
		if (game->txt.map_lines[game->num.yp - 1][game->num.xp] != '1')
			change_map('U', game);
	}
	else if ((ksym == KEY_S) && (game->num.key_game == 0))
	{
		if (game->txt.map_lines[game->num.yp + 1][game->num.xp] != '1')
			change_map('D', game);
	}
	else if ((ksym == KEY_A) && (game->num.key_game == 0))
	{
		if (game->txt.map_lines[game->num.yp][game->num.xp - 1] != '1')
			change_map('L', game);
	}
	else if ((ksym == KEY_D) && (game->num.key_game == 0))
	{
		if (game->txt.map_lines[game->num.yp][game->num.xp + 1] != '1')
			change_map('R', game);
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
