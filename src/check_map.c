/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 00:44:00 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/17 22:51:51 by wportilh         ###   ########.fr       */
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
	int	i;
	int	c;
	int	e;
	int	p;

	i = 0;
	c = 0;
	e = 0;
	p = 0;
	while (init->all_map[i])
	{
		if (init->all_map[i] == cep_chars[0])
			c++;
		if (init->all_map[i] == cep_chars[1])
			e++;
		if (init->all_map[i] == cep_chars[2])
			p++;
		i++;
	}
	if (c == 0)
		map_error("Letter 'C' not found. Insert at least one.\n", init);
	else if (e == 0)
		map_error("Letter 'E' not found. Insert at least one.\n", init);
	else if (p != 1)
		map_error("Insert one (only) letter 'P' on the map.\n", init);
}

static void	check_format_row(t_mlx *init)
{
	int		i;
	int		i2;

	i = 0;
	i2 = ft_strlen(init->map_lines[i]);
	init->rows = i2;
	while (init->map_lines[i])
	{
		if ((int)ft_strlen(init->map_lines[i]) != i2)
			map_error("Wrong format. Insert a rectangular map.\n", init);
		if ((init->map_lines[i][i2 - 1] != '1')
		|| (init->map_lines[i][0] != '1'))
			map_error("Number 1 is required around the map.\n", init);
		i++;
	}
}

static void	check_format_col(t_mlx *init)
{
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	while (init->map_lines[i])
		i++;
	init->cols = i;
	while (init->map_lines[0][i2])
	{
		if ((init->map_lines[0][i2] != '1')
		|| (init->map_lines[i - 1][i2] != '1'))
			map_error("Number 1 is required around the map.\n", init);
		i2++;
	}
}

void	check_map(t_mlx *init)
{
	int	i;

	i = 0;
	if (init->all_map)
		init->map_lines = ft_split(init->all_map, '\n');
	else
		input_error("Empty file.");
	if (init->all_map[0] == '\n')
		map_error("Empty line in the first (or more) line(s).\n", init);
	while (init->all_map[i])
	{
		if (init->all_map[i] == '\n' && init->all_map[i + 1] == '\n')
			map_error("Empty line(s) in file.\n", init);
		i++;
	}
	if (init->all_map[i - 1] == '\n')
		map_error("Empty line in the last (or more) line(s).\n", init);
	check_wrong_c(init, "01CEP\n");
	check_cep(init, "CEP");
	check_format_row(init);
	check_format_col(init);
}
