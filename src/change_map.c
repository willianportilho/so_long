/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 04:09:25 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/16 05:46:04 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"

static int	check_exit(char *sprite_letter, char c, t_mlx *init)
{
	if ((init->map_lines[init->yp - 1][init->xp] == 'E') && (c = 'U'))
		*sprite_letter = 'A';
	if ((init->map_lines[init->yp + 1][init->xp] == 'E') && (c = 'D'))
		change_map('D', init);
	if ((init->map_lines[init->yp][init->xp - 1] == 'E') && (c = 'L'))
		change_map('L', init);
	if ((init->map_lines[init->yp][init->xp + 1] == 'E') && (c = 'R'))
		change_map('R', init);
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
	char	sprite_letter;

	sprite_letter = 'P';
	//check_exit(&sprite_letter, c, init);
	if (c == 'U')
		init->yp2 = -1;
	if (c == 'D')
		init->yp2 = 1;
	if (c == 'L')
		init->xp2 = -1;
	if (c == 'R')
		init->xp2 = 1;
	change(sprite_letter, init);
}