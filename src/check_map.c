/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 00:44:00 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/11 19:23:07 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"

static void	map_error(char *message)
{
	printf("Error\n%s", message);
	exit(EXIT_FAILURE);
}

static void	check_wrong_c(char **all_map, char *allow_char)
{
	int		i;
	int		i2;
	int		key;

	i = 0;
	i2 = 0;
	key = 0;
	while ((*all_map)[i])
	{
		while (allow_char[i2])
		{
			if ((*all_map)[i] == allow_char[i2++])
				key = 1;
		}
		if (key == 0)
		{
			clear_map (all_map);
			map_error("Map with wrong character(s)\n");
		}
		i++;
		i2 = 0;
		key = 0;
	}
}

/*static void	check_cep(char **map_lines)
{
	char	*cep;

	cep = ft_strdup("CEP");
	
}*/

void	check_map(char **all_map)
{
	check_wrong_c(all_map, "01CEP\n");
	check_cep(map_lines);
	clear_map (all_map);
}
