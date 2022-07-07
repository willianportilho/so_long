/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:31:27 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/07 04:35:07 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		file;
	int		key;
	char	*partial;
	char	*str;
	char	**map_lines;

	key = 0;
	str = NULL;
	if (argc == 2)
	{
		file = open(argv[1], O_RDONLY);
		while (key == 0)
		{
			partial = get_next_line(file);
			if (partial == NULL)
				key = 1;
			if (partial != NULL)
				str = ft_strjoin_alt(str, partial);
		}
		map_lines = ft_split(str, '\n');
		read_map(map_lines);
	}
	else
		return (0);
	close(file);
	return (0);
}
