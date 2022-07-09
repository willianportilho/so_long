/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 00:44:00 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/09 06:08:08 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"

static void	map_error(char *message)
{
	printf("Error\n%s", message);
	exit(EXIT_FAILURE);
}

static void	check_wrong_c(char *line)
{
	char	*allow_char;
	int		i;
	int		i2;
	int		key;

	i = 0;
	i2 = 0;
	key = 0;
	allow_char = ft_strdup("01CEP");
	while (line[i])
	{
		while (allow_char[i2])
		{
			if (line[i] == allow_char[i2++])
				key = 1;
		}
		if (key == 0)
			map_error("Map with wrong character(s)\n");
		i++;
		i2 = 0;
		key = 0;
	}
}

void	check_map(char **map_lines)
{
	int		i;

	i = 0;
	while (map_lines[i])
		check_wrong_c(map_lines[i++]);
}
