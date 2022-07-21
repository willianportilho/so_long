/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 01:06:56 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/17 23:04:21 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_input(int argc, char *argv)
{
	int		file;

	if (argc == 1)
		put_error("*.ber argument missing.");
	if (argc > 2)
		put_error("Too many arguments.");
	if (ft_strncmp(argv + (ft_strlen(argv) - 4), ".ber", 5) != 0)
		put_error("Wrong format file. Enter with a *.ber argument.");
	file = open(argv, O_RDONLY);
	if (file == -1)
	{
		close(file);
		put_error("File not found (the file exists?).");
	}
	close(file);
}
