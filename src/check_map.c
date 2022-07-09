/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 00:44:00 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/09 05:01:09 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"

void	check_map(char **map_lines)
{
	char	*allow_char;
	int		i;
	int		i2;
	int		i3;
	int		key;

	allow_char = ft_strdup("01CEP");
	i = 0;
	i2 = 0;
	i3 = 0;
	key = 0;
	while (map_lines[i])
	{
		while (map_lines[i][i2])
		{
			while (allow_char[i3])
			{
				if (map_lines[i][i2] == allow_char[i3])
					key = 1;
				i3++;
			}
			if (key == 0)
			{
				printf("ERROR\nMap with wrong character(s)\n");
				exit(EXIT_FAILURE);
			}
			i2++;
			i3 = 0;
			key = 0;
		}
		i++;
		i2 = 0;
	}
}
