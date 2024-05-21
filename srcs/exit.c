/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:35:03 by tyavroya          #+#    #+#             */
/*   Updated: 2024/05/20 13:08:47 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	dealloc_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i] != NULL)
		free(map[i]);
	free(map);
}

char	**alloc_map(t_game *game)
{
	char	**c_map;
	int		col;
	int		row;

	c_map = (char **)malloc(sizeof(char *) * (game->map_size->row + 1));
	c_map[game->map_size->row] = 0;
	row = -1;
	while (++row < game->map_size->row)
	{
		col = -1;
		c_map[row] = (char *)malloc(sizeof(char) * game->map_size->col - 1);
		while (++col < game->map_size->col - 1)
			c_map[row][col] = game->map[row][col];
		c_map[row][col] = '\0';
		game->map[row][col] = '\0';
	}
	--(game->map_size->col);
	return (c_map);
}

void	dealloc(t_game *game)
{
	if (game->player)
		free(game->player);
	if (game->exit)
		free(game->exit);
	if (game->map_size)
		free(game->map_size);
	if (game->map)
		dealloc_map(game->map);
}

int	exit_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_coin);
	mlx_destroy_image(game->mlx, game->img_coin_back);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_floor);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_window(game->mlx, game->win);
	dealloc_map(game->map);
	// system("leaks so_long");
	exit(EXIT_SUCCESS);
	return (0);
}

void	_err(t_game *game)
{
	dealloc(game);
	ft_putstr_fd("Error\nInvalid input\n", 2);
	// system("leaks so_long");
	exit(EXIT_FAILURE);
}
