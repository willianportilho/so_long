/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 05:26:04 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/18 22:18:52 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"
#include "../inc/libft.h"

void	map_error(char *message, t_game *game)
{
	ft_printf("Error\n%s", message);
	clear_map(game);
	free (game->txt.all_map);
	exit(EXIT_FAILURE);
}

void	put_error(char *message)
{
	ft_printf("Error\n%s\n", message);
	exit(EXIT_FAILURE);
}
