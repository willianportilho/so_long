/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:31:27 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/12 21:43:48 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"


// MUDAR CONFGS DE USUÁRIO GIT ANTES DE ENTREGAR
int	main(int argc, char *argv[])
{
	char	*all_map;
	char	**map_lines;
	int		i;

	i = 0;
	check_input(argc, argv[1]);
	all_map = get_map(argv[1]);
	check_map(&all_map);
	map_lines = ft_split(all_map, '\n');
	read_map(map_lines);
	clear_map(&map_lines);
	map_error("Deu tudo certo até aqui, graças a Deus!\n", &all_map);
}
