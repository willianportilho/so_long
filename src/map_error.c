/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 05:26:04 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/14 22:55:29 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"

void	map_error(char *message, t_mlx *init)
{
	ft_printf("Error\n%s", message);
	free (init->all_map);
	exit(EXIT_FAILURE);

	// MUDAR O PRINTF POR FT_PRINTF E VER COMO FUNCIONA O EXIT
}
