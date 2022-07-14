/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 05:14:36 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/14 22:36:59 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"

void	insert_name(t_mlx *init)
{
	init->wall = mlx_xpm_file_to_image(init->mlx, "./img/wall.xpm", &init->i, &init->j);
}

void	insert_map(t_mlx *init)
{
	//init->wall = mlx_xpm_file_to_image(init->mlx, "./img/wall.xpm", &init->i, &init->j);
	mlx_put_image_to_window(init->mlx, init->win, init->wall, 50, 50);
}
