/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 04:09:25 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/17 21:09:34 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"

static int	check_not_yet(char c, t_mlx *init)
{
	int	check;

	check = 0;
	if ((init->map_lines[init->yp - 1][init->xp] == 'E') && (c == 'U'))
		check = 1;
	if ((init->map_lines[init->yp + 1][init->xp] == 'E') && (c == 'D'))
		check = 1;
	if ((init->map_lines[init->yp][init->xp - 1] == 'E') && (c == 'L'))
		check = 1;
	if ((init->map_lines[init->yp][init->xp + 1] == 'E') && (c == 'R'))
		check = 1;
	if (check == 1)
	{
		mlx_destroy_image(init->mlx, init->hero);
		init->hero = mlx_xpm_file_to_image(\
		init->mlx, "./img/dog_woof.xpm", &init->i, &init->j);
		init->try_exit = 1;
	}
}

static int	check_exit(char c, t_mlx *init)
{
	int	check;

	check = 0;
	if ((init->map_lines[init->yp - 1][init->xp] == 'E') && (c == 'U'))
		check = 1;
	if ((init->map_lines[init->yp + 1][init->xp] == 'E') && (c == 'D'))
		check = 1;
	if ((init->map_lines[init->yp][init->xp - 1] == 'E') && (c == 'L'))
		check = 1;
	if ((init->map_lines[init->yp][init->xp + 1] == 'E') && (c == 'R'))
		check = 1;
	if (check == 1)
	{
		init->key_game = 1;
		init->map_lines[init->yp][init->xp] = init->sprite_curr;
		init->map_lines[init->yp + init->yp2][init->xp + init->xp2] = init->sprite_next;
		mlx_destroy_image(init->mlx, init->hero);
		init->hero = mlx_xpm_file_to_image(\
		init->mlx, "./img/dog_you_win.xpm", &init->i, &init->j);
		ft_printf("Moviments: %d\n", ++init->moviments);
	}
}

static void	change_letter(t_mlx *init)
{
	init->map_lines[init->yp][init->xp] = init->sprite_curr;
	init->map_lines[init->yp + init->yp2][init->xp + init->xp2] = init->sprite_next;
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
		change_dog(c, init);
	if (init->n_coins > 0)
		check_not_yet(c, init);
	else if (init->n_coins == 0)
		check_exit(c, init);
	change_letter(init);
	if (init->try_exit == 1)
	{
		init->sprite_curr = 'E';
		init->try_exit = 0;
	}
	else
		init->sprite_curr = '0';
	init->moviments++;
	ft_printf("Moviments: %d\n", init->moviments);
}
