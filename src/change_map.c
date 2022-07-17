/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 04:09:25 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/16 22:55:45 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"

static int	check_exit(char c, t_mlx *init)
{
	if ((init->map_lines[init->yp - 1][init->xp] == 'E') && (c == 'U'))
		close_game(init);
	if ((init->map_lines[init->yp + 1][init->xp] == 'E') && (c == 'D'))
		close_game(init);
	if ((init->map_lines[init->yp][init->xp - 1] == 'E') && (c == 'L'))
		close_game(init);
	if ((init->map_lines[init->yp][init->xp + 1] == 'E') && (c == 'R'))
		close_game(init);
}

static void	change(char c, t_mlx *init)
{
	init->map_lines[init->yp][init->xp] = '0';
	init->map_lines[init->yp + init->yp2][init->xp + init->xp2] = c;
	init->yp2 = 0;
	init->xp2 = 0;
}

void	change_map(char c, t_mlx *init)
{
	if (c == 'U')
		init->yp2 = -1;
	else if (c == 'D')
		init->yp2 = 1;
	else if (c == 'L')
		init->xp2 = -1;
	else if (c == 'R')
		init->xp2 = 1;
	if (init->n_coins == 0)
		check_exit(c, init);
	change('P', init);
	ft_printf("C = %d", init->n_coins);
}
