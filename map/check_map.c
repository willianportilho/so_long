/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 00:44:00 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/11 22:15:44 by wportilh         ###   ########.fr       */
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

static void	check_cep(char **all_map, char *cep_chars)
{
	t_cep	cep;

	cep.i = 0;
	cep.c = 0;
	cep.e = 0;
	cep.p = 0;
	while ((*all_map)[cep.i])
	{
		if ((*all_map)[cep.i] == cep_chars[0])
			cep.c++;
		if ((*all_map)[cep.i] == cep_chars[1])
			cep.e++;
		if ((*all_map)[cep.i] == cep_chars[2])
			cep.p++;
		cep.i++;
	}
	if ((cep.c == 0) || (cep.e == 0) || (cep.p != 1))
		clear_map (all_map);
	if (cep.c == 0)
		map_error("Letter 'C' not found. Inside 'C' at least one time\n");
	else if (cep.e == 0)
		map_error("Letter 'E' not found. Inside 'E' at least one time\n");
	else if (cep.p != 1)
		map_error("Please, inside only one letter 'P' on the map\n");
}

static void	check_rectangle(char **all_map)
{
	int		i;
	int		i2;
	char	**map_lines;

	i = 0;
	i2 = 0;
	map_lines = ft_split(*all_map, "\n");
	
}

void	check_map(char **all_map)
{
	check_wrong_c(all_map, "01CEP\n");
	check_cep(all_map, "CEP");
	//check_rectangle(all_map);
	clear_map (all_map);
}
