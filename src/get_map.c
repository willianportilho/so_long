/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 00:45:03 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/26 21:06:06 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	get_map(t_game *game, char *argv)
{
	int		file;
	int		key;
	char	*partial;

	key = 0;
	game->txt.all_map = NULL;
	file = open(argv, O_RDONLY);
	while (key == 0)
	{
		partial = get_next_line(file);
		if (partial == NULL)
			key = 1;
		if (partial != NULL)
			game->txt.all_map = ft_strjoin_alt(game->txt.all_map, partial);
		free (partial);
	}
	close(file);
}
