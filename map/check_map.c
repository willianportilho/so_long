/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 00:44:00 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/12 20:44:01 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"

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
			map_error("Map with wrong character(s).\n", all_map);
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
	if (cep.c == 0)
		map_error("Letter 'C' not found. Insert at least one.\n", all_map);
	else if (cep.e == 0)
		map_error("Letter 'E' not found. Insert at least one.\n", all_map);
	else if (cep.p != 1)
		map_error("Insert only one letter 'P' on the map.\n", all_map);
}

static void	check_format_row(char **all_map)
{
	int		i;
	int		i2;
	char	**map_lines;

	map_lines = ft_split(*all_map, '\n');
	i = 0;
	i2 = ft_strlen(map_lines[i]);
	while (map_lines[i])
	{
		if ((int)ft_strlen(map_lines[i]) != i2)
		{
			clear_map(&map_lines);
			map_error("Wrong format. Insert a rectangular map.\n", all_map);
		}
		if ((map_lines[i][i2 - 1] != '1') || (map_lines[i][0] != '1'))
		{
			clear_map(&map_lines);
			map_error("Number 1 is required around the map.\n", all_map);
		}
		i++;
	}
	clear_map(&map_lines);
}

static void	check_format_col(char **all_map)
{
	int		i;
	int		i2;
	char	**map_lines;

	map_lines = ft_split(*all_map, '\n');
	i = 0;
	i2 = 0;
	while (map_lines[i])
		i++;
	while (map_lines[0][i2])
	{
		if ((map_lines[0][i2] != '1') || (map_lines[i - 1][i2] != '1'))
		{
			clear_map(&map_lines);
			map_error("Number 1 is required around the map.\n", all_map);
		}
		i2++;
	}
	clear_map(&map_lines);
}

void	check_map(char **all_map)
{
	check_wrong_c(all_map, "01CEP\n");
	check_cep(all_map, "CEP");
	check_format_row(all_map);
	check_format_col(all_map);
}
