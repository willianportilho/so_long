/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:08:29 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/18 03:21:25 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"
#include "../inc/libft.h"

void	clear_map(t_mlx *init)
{
	int	i;

	i = 0;
	while (init->map_lines[i])
		free (init->map_lines[i++]);
	free (init->map_lines);
}

void	clear_xpms(t_mlx *init)
{
	mlx_destroy_image(init->mlx, init->flower);
	mlx_destroy_image(init->mlx, init->bone);
	mlx_destroy_image(init->mlx, init->gram);
	mlx_destroy_image(init->mlx, init->home);
	mlx_destroy_image(init->mlx, init->dog);
	mlx_destroy_image(init->mlx, init->board);
}
