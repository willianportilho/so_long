/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 01:06:56 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/09 05:00:40 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static void	input_error(char *message)
{
	printf("Error\n%s", message);
	exit(EXIT_FAILURE);
}

void	check_input(int argc, char *argv)
{
	int		file;

	if (argc == 1)
		input_error("Missing argument *.ber file\n\n");
	if (argc > 2)
		input_error("Too many arguments\n\n");
	if (ft_strncmp(argv + (ft_strlen(argv) - 4), ".ber", 5) != 0)
		input_error("Wrong format file. Enter with a *.ber argument\n");
	file = open(argv, O_RDONLY);
	if (file == -1)
	{
		close(file);
		input_error("File error\n\n");
	}
	close(file);
	// MUDAR O PRINTF POR FT_PRINTF E VER COMO FUNCIONA O EXIT
}
