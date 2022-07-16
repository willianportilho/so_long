/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:25:54 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/16 01:34:05 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"

int	handle_input(int keysym, t_mlx *init)
{
	if (keysym == KEY_ESCAPE)
		close_game(init);
	else if (keysym == KEY_ABNT_S)
	{
		init->map_lines[init->yp][init->xp] = '0';
		init->map_lines[(init->yp + 1)][init->xp] = 'P';
	}
	else if (keysym == KEY_ABNT_W)
	{
		init->map_lines[init->yp][init->xp] = '0';
		init->map_lines[(init->yp - 1)][init->xp] = 'P';
	}
	else if (keysym == KEY_ABNT_A)
	{
		init->map_lines[init->yp][init->xp] = '0';
		init->map_lines[(init->yp)][init->xp - 1] = 'P';
	}
	else if (keysym == KEY_ABNT_D)
	{
		init->map_lines[init->yp][init->xp] = '0';
		init->map_lines[(init->yp)][init->xp + 1] = 'P';
	}
	start_map(init);
	return (1);
}

int	handle_keyrelease(int keysym, void *data)
{
	ft_printf("Keyrelease: %c\n", keysym);
	return (0);
}

int	close_game(t_mlx *init)
{
	clear_xpms(init);
	clear_map(init);
	mlx_destroy_window(init->mlx, init->win);
	mlx_destroy_display(init->mlx);
	free (init->all_map);
	free (init->mlx);
	ft_printf("You left the game!\n", init);
	exit(EXIT_SUCCESS);
}

int	reprint(t_mlx *init)
{
	start_map(init);
	return (0);
}

void	found_p(t_mlx *init)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	init->xp = 0;
	init->yp = 0;

	while (init->map_lines[i])
	{
		while (init->map_lines[i][i2])
		{
			if (init->map_lines[i][i2] == 'P')
			{
				init->xp = i2;
				init->yp = i;
			}
			i2++;
		}
		i++;
		i2 = 0;
	}
}
