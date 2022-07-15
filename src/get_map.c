/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 00:45:03 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/15 04:14:53 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static void	check_bl(t_mlx *init)
{
	int	i;

	i = 0;
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
}

void	get_map(t_mlx *init, char *argv)
{
	int		file;
	int		key;
	char	*partial;

	key = 0;
	init->all_map = NULL;
	file = open(argv, O_RDONLY);
	while (key == 0)
	{
		partial = get_next_line(file);
		if (partial == NULL)
			key = 1;
		if (partial != NULL)
			init->all_map = ft_strjoin_alt(init->all_map, partial);
		free (partial);
	}
	close(file);
	check_bl(init);
}
