/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:08:29 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/15 20:00:58 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
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
	mlx_destroy_image(init->mlx, init->wall);
	mlx_destroy_image(init->mlx, init->coin);
	mlx_destroy_image(init->mlx, init->ground);
	mlx_destroy_image(init->mlx, init->hole);
	mlx_destroy_image(init->mlx, init->hero);
}
