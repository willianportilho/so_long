/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 05:26:04 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/15 20:55:36 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"

void	map_error(char *message, t_mlx *init)
{
	ft_printf("Error\n%s", message);
	//clear_xpms(init);
	clear_map(init);
	//mlx_destroy_display(init->mlx);
	free (init->all_map);
	//free (init->mlx);
	//mlx_destroy_window(init->mlx, init->win);
	exit(EXIT_FAILURE);
}
