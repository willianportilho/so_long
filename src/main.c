/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:31:27 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/15 05:37:29 by wportilh         ###   ########.fr       */
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
	init_vars(&init);
	check_map(&init);
	read_map(&init);
}
