/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 05:01:18 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/14 22:13:32 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/libft.h"

int	handle_input(int keysym, t_mlx *init)
{
	if (keysym == KEY_ESCAPE)
		mlx_destroy_window(init->mlx, init->win);
	return (0);
}

int	handle_keyrelease(int keysym, void *data)
{
	ft_printf("Keyrelease: %c\n", keysym);
	return (0);
}

int	close_game(t_mlx *init)
{
	mlx_destroy_window(init->mlx, init->win);
	return (0);
}

int	handle_no_event(void *init)
{
	return (0);
}

void	read_map(char	**all_map)
{
	t_mlx	init;

	init.count = 0;
	init.map_lines = ft_split(*all_map, '\n');
	init.mlx = mlx_init();
	if(init.mlx == NULL)
		return ;
	init.win = mlx_new_window(init.mlx, 500, 500, "so_long");
	if(init.win == NULL)
	{
		free (init.win);
		return ;
	}
	insert_map(&init);
	mlx_loop_hook(init.mlx, &handle_no_event, &init);
	mlx_hook(init.win, KeyPress, KeyPressMask, &handle_input, &init);
	mlx_hook(init.win, DestroyNotify, NoEventMask, &close_game, &init);
	mlx_loop(init.mlx);
	mlx_destroy_image(init.mlx, init.wall);
	mlx_destroy_image(init.mlx, init.hero);
	mlx_destroy_display(init.mlx);
	free (init.mlx);
	while (init.map_lines[init.count])
		free(init.map_lines[init.count++]);
	free(init.map_lines);
}
