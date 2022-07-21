/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 00:44:00 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/20 03:05:18 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static void	check_wrong_c(t_game *game, char *allow_char)
{
	int		i;
	int		i2;
	int		key;

	i = 0;
	i2 = 0;
	key = 0;
	while (game->txt.all_map[i])
	{
		while (allow_char[i2])
		{
			if (game->txt.all_map[i] == allow_char[i2++])
				key = 1;
		}
		if (key == 0)
			map_error("Map with wrong character(s).\n", game);
		i++;
		i2 = 0;
		key = 0;
	}
}

static void	check_cep(t_game *game, char *cep_chars)
{
	game->num.index = 0;
	game->num.c = 0;
	game->num.e = 0;
	game->num.p = 0;
	game->num.m = 0;
	while (game->txt.all_map[game->num.index])
	{
		if (game->txt.all_map[game->num.index] == cep_chars[0])
			game->num.c++;
		if (game->txt.all_map[game->num.index] == cep_chars[1])
			game->num.e++;
		if (game->txt.all_map[game->num.index] == cep_chars[2])
			game->num.p++;
		if (game->txt.all_map[game->num.index] == cep_chars[3])
			game->num.m++;
		game->num.index++;
	}
	if (game->num.c == 0)
		map_error("Letter 'C' not found. Insert at least one.\n", game);
	else if (game->num.e == 0)
		map_error("Letter 'E' not found. Insert at least one.\n", game);
	else if (game->num.m == 0)
		map_error("Letter 'M' not found. Insert at least one.\n", game);
	else if (game->num.p != 1)
		map_error("Insert one (only) letter 'P' on the map.\n", game);
}

static void	check_format_row(t_game *game)
{
	int		i;
	int		i2;

	i = 0;
	i2 = ft_strlen(game->txt.map_lines[i]);
	game->num.cols = i2;
	while (game->txt.map_lines[i])
	{
		if ((int)ft_strlen(game->txt.map_lines[i]) != i2)
			map_error("Wrong format. Insert a rectangular map.\n", game);
		if ((game->txt.map_lines[i][i2 - 1] != '1')
		|| (game->txt.map_lines[i][0] != '1'))
			map_error("Number 1 is required around the map.\n", game);
		i++;
	}
}

static void	check_format_col(t_game *game)
{
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	while (game->txt.map_lines[i])
		i++;
	game->num.rows = i;
	while (game->txt.map_lines[0][i2])
	{
		if ((game->txt.map_lines[0][i2] != '1')
		|| (game->txt.map_lines[i - 1][i2] != '1'))
			map_error("Number 1 is required around the map.\n", game);
		i2++;
	}
}

void	check_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->txt.all_map)
		game->txt.map_lines = ft_split(game->txt.all_map, '\n');
	else
		put_error("Empty file.");
	if (game->txt.all_map[0] == '\n')
		map_error("Empty line in the first (or more) line(s).\n", game);
	while (game->txt.all_map[i])
	{
		if (game->txt.all_map[i] == '\n' && game->txt.all_map[i + 1] == '\n')
			map_error("Empty line(s) in file.\n", game);
		i++;
	}
	if (game->txt.all_map[i - 1] == '\n')
		map_error("Empty line in the last (or more) line(s).\n", game);
	check_wrong_c(game, "01CEPM\n");
	check_cep(game, "CEPM");
	check_format_row(game);
	check_format_col(game);
}
