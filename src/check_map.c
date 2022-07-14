/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 00:44:00 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/14 22:54:50 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"

static void	check_wrong_c(t_mlx *init, char *allow_char)
{
	int		i;
	int		i2;
	int		key;

	i = 0;
	i2 = 0;
	key = 0;
	while (init->all_map[i])
	{
		while (allow_char[i2])
		{
			if (init->all_map[i] == allow_char[i2++])
				key = 1;
		}
		if (key == 0)
			map_error("Map with wrong character(s).\n", init);
		i++;
		i2 = 0;
		key = 0;
	}
}

static void	check_cep(t_mlx *init, char *cep_chars)
{
	t_cep	cep;

	cep.i = 0;
	cep.c = 0;
	cep.e = 0;
	cep.p = 0;
	while (init->all_map[cep.i])
	{
		if (init->all_map[cep.i] == cep_chars[0])
			cep.c++;
		if (init->all_map[cep.i] == cep_chars[1])
			cep.e++;
		if (init->all_map[cep.i] == cep_chars[2])
			cep.p++;
		cep.i++;
	}
	if (cep.c == 0)
		map_error("Letter 'C' not found. Insert at least one.\n", init);
	else if (cep.e == 0)
		map_error("Letter 'E' not found. Insert at least one.\n", init);
	else if (cep.p != 1)
		map_error("Insert only one letter 'P' on the map.\n", init);
}

static void	check_format_row(t_mlx *init)
{
	int		i;
	int		i2;
	char	**map_lines;

	map_lines = ft_split(init->all_map, '\n');
	i = 0;
	i2 = ft_strlen(map_lines[i]);
	while (map_lines[i])
	{
		if ((int)ft_strlen(map_lines[i]) != i2)
		{
			clear_map(&map_lines);
			map_error("Wrong format. Insert a rectangular map.\n", init);
		}
		if ((map_lines[i][i2 - 1] != '1') || (map_lines[i][0] != '1'))
		{
			clear_map(&map_lines);
			map_error("Number 1 is required around the map.\n", init);
		}
		i++;
	}
	clear_map(&map_lines);
}

static void	check_format_col(t_mlx *init)
{
	int		i;
	int		i2;
	char	**map_lines;

	map_lines = ft_split(init->all_map, '\n');
	i = 0;
	i2 = 0;
	while (map_lines[i])
		i++;
	while (map_lines[0][i2])
	{
		if ((map_lines[0][i2] != '1') || (map_lines[i - 1][i2] != '1'))
		{
			clear_map(&map_lines);
			map_error("Number 1 is required around the map.\n", init);
		}
		i2++;
	}
	clear_map(&map_lines);
}

void	check_map(t_mlx *init)
{
	check_wrong_c(init, "01CEP\n");
	check_cep(init, "CEP");
	check_format_row(init);
	check_format_col(init);
}
