/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 04:09:25 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/17 08:23:07 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"

static int	check_exit(char c, t_mlx *init)
{
	if ((init->map_lines[init->yp - 1][init->xp] == 'E') && (c == 'U'))
	{
		ft_printf("Moviments: %d\n", ++init->moviments);
		close_game("You Win!!!!!!", init);
	}
	if ((init->map_lines[init->yp + 1][init->xp] == 'E') && (c == 'D'))
	{
		ft_printf("Moviments: %d\n", ++init->moviments);
		close_game("You Win!!!!!!", init);
	}
	if ((init->map_lines[init->yp][init->xp - 1] == 'E') && (c == 'L'))
	{
		ft_printf("Moviments: %d\n", ++init->moviments);
		close_game("You Win!!!!!!", init);
	}
	if ((init->map_lines[init->yp][init->xp + 1] == 'E') && (c == 'R'))
	{
		ft_printf("Moviments: %d\n", ++init->moviments);
		close_game("You Win!!!!!!", init);
	}
}

static void	change_letter(char c, t_mlx *init)
{
	init->map_lines[init->yp][init->xp] = '0';
	init->map_lines[init->yp + init->yp2][init->xp + init->xp2] = c;
	init->yp2 = 0;
	init->xp2 = 0;
}

static void	change_dog(char c, t_mlx *init)
{
	mlx_destroy_image(init->mlx, init->hero);
	if (c == 'U')
	{
		init->hero = mlx_xpm_file_to_image(\
		init->mlx, "./img/dog_u.xpm", &init->i, &init->j);
	}
	else if (c == 'D')
	{
		init->hero = mlx_xpm_file_to_image(\
		init->mlx, "./img/dog_d.xpm", &init->i, &init->j);
	}
	else if (c == 'L')
	{
		init->hero = mlx_xpm_file_to_image(\
		init->mlx, "./img/dog_l.xpm", &init->i, &init->j);
	}
	else if (c == 'R')
	{
		init->hero = mlx_xpm_file_to_image(\
		init->mlx, "./img/dog_r.xpm", &init->i, &init->j);
	}
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
	change_dog(c, init);
	change_letter('P', init);
	init->moviments++;
	ft_printf("Moviments: %d\n", init->moviments);
}
