/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 00:44:00 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/18 22:18:48 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"
#include "../inc/libft.h"

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
	int	i;
	int	c;
	int	e;
	int	p;

	i = 0;
	c = 0;
	e = 0;
	p = 0;
	while (game->txt.all_map[i])
	{
		if (game->txt.all_map[i] == cep_chars[0])
			c++;
		if (game->txt.all_map[i] == cep_chars[1])
			e++;
		if (game->txt.all_map[i] == cep_chars[2])
			p++;
		i++;
	}
	if (c == 0)
		map_error("Letter 'C' not found. Insert at least one.\n", game);
	else if (e == 0)
		map_error("Letter 'E' not found. Insert at least one.\n", game);
	else if (p != 1)
		map_error("Insert one (only) letter 'P' on the map.\n", game);
}

static void	check_format_row(t_game *game)
{
	int		i;
	int		i2;

	i = 0;
	i2 = ft_strlen(game->txt.map_lines[i]);
	game->num.rows = i2;
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
	game->num.cols = i;
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
