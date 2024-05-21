/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:51:56 by tyavroya          #+#    #+#             */
/*   Updated: 2024/05/21 17:25:03 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	init_game(t_game *game)
{
	game->player = (t_point *)malloc(sizeof(t_point));
	game->exit = (t_point *)malloc(sizeof(t_point));
	game->map_size = (t_point *)malloc(sizeof(t_point));
	game->map = NULL;
	game->mlx = NULL;
	game->img_coin = NULL;
	game->img_coin_back = NULL;
	game->img_player = NULL;
	game->img_exit = NULL;
	game->img_floor = NULL;
	game->img_wall = NULL;
	game->img_opponent = NULL;
	game->on_exit = 0;
	game->map_size->row = 0;
	game->map_size->col = 0;
	game->coins_count = 0;
	game->moves_count = 0;
	game->endgame = 0;
	game->img_height = 0;
	game->img_width = 0;
	game->win_height = 0;
	game->win_width = 0;
}

int	t_main(int ac, char **av)
{
	t_game	game;

	init_game(&game);
	if (ac != 2 || file_checker(av[1]))
		_err(&game);
	game.map = save_file(av[1], &game);
	is_valid_map(&game);
	open_window(&game);
	printing_images(&game);
	mlx_loop(game.mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_main(ac, av);
	// system("leaks so_long");
}
