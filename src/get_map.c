/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 00:45:03 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/14 22:43:33 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char	*get_map(char *argv)
{
	int		file;
	int		key;
	char	*partial;
	char	*all_map;

	key = 0;
	all_map = NULL;
	file = open(argv, O_RDONLY);
	while (key == 0)
	{
		partial = get_next_line(file);
		if (partial == NULL)
			key = 1;
		if (partial != NULL)
			all_map = ft_strjoin_alt(all_map, partial);
		free (partial);
	}
	close(file);
	return (all_map);
}
