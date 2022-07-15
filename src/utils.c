/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:25:54 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/15 20:24:20 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"

int	handle_input(int keysym, t_mlx *init)
{
	if (keysym == KEY_ESCAPE)
		close_game(init);
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
	mlx_destroy_display(init->mlx);
	free (init->all_map);
	free (init->mlx);
	mlx_destroy_window(init->mlx, init->win);
	ft_printf("You left the game!\n", init);
	exit(EXIT_SUCCESS);
}

int	reprint(t_mlx *init)
{
	start_map(init);
	return (0);
}
