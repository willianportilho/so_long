/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:25:54 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/18 04:45:06 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"
#include "../inc/libft.h"

void	put_counter(t_mlx *init)
{
	char	*str;

	str = ft_itoa(init->moviments);
	mlx_put_image_to_window(init->mlx, init->win, \
	init->board, 0, 0);
	mlx_string_put(init->mlx, init->win, 9, 19, 0xffffff, "MOVES:");
	mlx_string_put(init->mlx, init->win, 16, 37, 0xffffff, str);
	free (str);
}

int	handle_input(int keysym, t_mlx *init)
{
	if (keysym == KEY_ESCAPE)
		close_game("You left the game!", init);
	else if ((keysym == KEY_ABNT_W) && (init->key_game == 0))
	{
		if (init->map_lines[init->yp - 1][init->xp] != '1')
			change_map('U', init);
	}
	else if ((keysym == KEY_ABNT_S) && (init->key_game == 0))
	{
		if (init->map_lines[init->yp + 1][init->xp] != '1')
			change_map('D', init);
	}
	else if ((keysym == KEY_ABNT_A) && (init->key_game == 0))
	{
		if (init->map_lines[init->yp][init->xp - 1] != '1')
			change_map('L', init);
	}
	else if ((keysym == KEY_ABNT_D) && (init->key_game == 0))
	{
		if (init->map_lines[init->yp][init->xp + 1] != '1')
			change_map('R', init);
	}
	return (0);
}

int	reprint(t_mlx *init)
{
	start_map(init);
	return (0);
}

void	update_map(t_mlx *init)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	init->xp = 0;
	init->yp = 0;
	init->n_bones = 0;
	while (init->map_lines[i])
	{
		while (init->map_lines[i][i2])
		{
			if (init->map_lines[i][i2] == 'P')
			{
				init->xp = i2;
				init->yp = i;
			}
			if (init->map_lines[i][i2] == 'C')
				init->n_bones++;
			i2++;
		}
		i++;
		i2 = 0;
	}
}
