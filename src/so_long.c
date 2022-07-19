/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:31:27 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/18 21:39:54 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"


// MUDAR CONFGS DE USUÁRIO GIT ANTES DE ENTREGAR
int	main(int argc, char *argv[])
{
	t_game	game;

	check_input(argc, argv[1]);
	get_map(&game, argv[1]);
	check_map(&game);
	init_vars(&game);
	start_map(&game);
	mlx_hook(game.init.win, Expose, ExposureMask, &reprint, &game);
	mlx_hook(game.init.win, KeyPress, KeyPressMask, &handle_input, &game);
	mlx_hook(game.init.win, DestroyNotify, NoEventMask, &before_close, &game);
	mlx_loop(game.init.mlx);
}