/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 04:09:25 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/16 04:14:18 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"

static void	change_u(t_mlx *init)
{
	init->map_lines[init->yp][init->xp] = '0';
	init->map_lines[init->yp - 1][init->xp] = 'P';
}

static void	change_d(t_mlx *init)
{
	init->map_lines[init->yp][init->xp] = '0';
	init->map_lines[init->yp + 1][init->xp] = 'P';
}

static void	change_l(t_mlx *init)
{
	init->map_lines[init->yp][init->xp] = '0';
	init->map_lines[init->yp][init->xp - 1] = 'P';
}

static void	change_r(t_mlx *init)
{
	init->map_lines[init->yp][init->xp] = '0';
	init->map_lines[init->yp][init->xp + 1] = 'P';
}

void	change_map(char c, t_mlx *init)
{
	if (c == 'U')
		change_u(init);
	if (c == 'D')
		change_d(init);
	if (c == 'L')
		change_l(init);
	if (c == 'R')
		change_r(init);
}