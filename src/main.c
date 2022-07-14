/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:31:27 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/14 22:47:57 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"


// MUDAR CONFGS DE USUÁRIO GIT ANTES DE ENTREGAR
int	main(int argc, char *argv[])
{
	t_mlx	init;

	check_input(argc, argv[1]);
	init.all_map = get_map(argv[1]);
	check_map(&init);
	read_map(&init);
	map_error("Deu tudo certo até aqui, graças a Deus!\n", &init);
}
