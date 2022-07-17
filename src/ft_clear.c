/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:08:29 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/17 23:15:26 by wportilh         ###   ########.fr       */
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
	mlx_destroy_image(init->mlx, init->flower);
	mlx_destroy_image(init->mlx, init->bone);
	mlx_destroy_image(init->mlx, init->gram);
	mlx_destroy_image(init->mlx, init->home);
	mlx_destroy_image(init->mlx, init->dog);
}
