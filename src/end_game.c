/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 03:02:21 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/18 03:02:36 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"

int	before_close(t_mlx *init)
{
	close_game("You left the game!", init);
	return (1);
}

int	close_game(char *message, t_mlx *init)
{
	clear_xpms(init);
	clear_map(init);
	mlx_destroy_window(init->mlx, init->win);
	mlx_destroy_display(init->mlx);
	free (init->all_map);
	free (init->mlx);
	ft_printf("%s\n", message);
	exit(EXIT_SUCCESS);
}
