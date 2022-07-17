/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:31:27 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/17 05:26:05 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"


// MUDAR CONFGS DE USUÁRIO GIT ANTES DE ENTREGAR
int	main(int argc, char *argv[])
{
	t_mlx	init;

	check_input(argc, argv[1]);
	get_map(&init, argv[1]);
	check_map(&init);
	init_vars(&init);
	start_map(&init);
	mlx_hook(init.win, Expose, ExposureMask, &reprint, &init);
	mlx_hook(init.win, KeyPress, KeyPressMask, &handle_input, &init);
	mlx_hook(init.win, DestroyNotify, NoEventMask, &before_close, &init);
	mlx_loop(init.mlx);
}
