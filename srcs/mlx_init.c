/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:04:15 by tyavroya          #+#    #+#             */
/*   Updated: 2024/05/21 17:27:44 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	put_image(t_game *game, void *img, int row, int col)
{
	mlx_put_image_to_window(game->mlx, game->win, img, col, row);
}

static void	validate_image(t_game *game, int i, int j)
{
	if (game->map[i][j] == WALL)
		put_image(game, game->img_wall, i * IMG_S, j * IMG_S);
	else if (game->map[i][j] == EXIT)
		put_image(game, game->img_exit, i * IMG_S, j * IMG_S);
	else if (game->map[i][j] == PLAYER)
	{
		if (game->on_exit)
			put_image(game, game->img_exit, i * IMG_S, j * IMG_S);
		else
			put_image(game, game->img_floor, i * IMG_S, j * IMG_S);
		put_image(game, game->img_player, i * IMG_S, j * IMG_S);
	}
	else if (game->map[i][j] == COIN)
	{
		put_image(game, game->img_coin_back, i * IMG_S, j * IMG_S);
		put_image(game, game->img_coin, (i * IMG_S) + 15, (j * IMG_S) + 15);
	}
	else if (game->map[i][j] == SPACE)
		put_image(game, game->img_floor, i * IMG_S, j * IMG_S);
	else if (game->map[i][j] == OPPONENT)
		put_image(game, game->img_opponent, i * IMG_S, j * IMG_S);
}

static void	init_images(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"./pictures/Player/Player_0_empty.xpm", &game->img_width,
			&game->img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"./pictures/Wall/Wall_0.xpm", &game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"./pictures/Gate/Gate_0.xpm", &game->img_width, &game->img_height);
	game->img_coin = mlx_xpm_file_to_image(game->mlx,
			"./pictures/Coin/Coin_0.xpm", &game->img_width, &game->img_height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"./pictures/Floor/Floor_0.xpm", &game->img_width,
			&game->img_height);
	game->img_coin_back = mlx_xpm_file_to_image(game->mlx,
			"./pictures/Floor/Floor_0.xpm", &game->img_width,
			&game->img_height);
	game->img_opponent = mlx_xpm_file_to_image(game->mlx,
			"./pictures/Opponent/Opponent_0.xpm", &game->img_width,
			&game->img_height);
}

void	open_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		_err(game);
	game->win_height = game->map_size->row * IMG_S;
	game->win_width = game->map_size->col * IMG_S;
	game->win = mlx_new_window(game->mlx, game->win_width, game->win_height,
			"So_long");
}

int	printing_images(t_game *game)
{
	int	row;
	int	col;

	row = -1;
	init_images(game);
	while (++row < game->map_size->row)
	{
		col = -1;
		while (++col < game->map_size->col)
			validate_image(game, row, col);
	}
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFF00BBFF, "Moves: ");
	mlx_string_put(game->mlx, game->win, 80, 10, 0xFF00BBFF,
		ft_itoa(game->moves_count));
	event_handler(game);
	return (0);
}
