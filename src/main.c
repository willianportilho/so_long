/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:31:27 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/11 18:54:55 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"

int	main(int argc, char *argv[])
{
	char	*all_map;
	int		i;

	i = 0;
	check_input(argc, argv[1]);
	all_map = get_map(argv[1]);
	//while (map_lines[i])
	//	free (map_lines[i++]);
	//free (map_lines);
	check_map(&all_map);
	//read_map(map_lines);
}
