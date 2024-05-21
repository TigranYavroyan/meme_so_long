/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:47:07 by tyavroya          #+#    #+#             */
/*   Updated: 2024/05/19 15:26:57 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

// add all validating functions for map here to call from main only this
void	is_valid_map(t_game *game)
{
	char	**c_map;

	check_map_size(game);
	check_maps_elements(game);
	is_map_open(game);
	c_map = alloc_map(game);
	if (!check_path(c_map, (t_point){game->player->row, game->player->col},
		game->coins_count + 1))
	{
		dealloc_map(c_map);
		_err(game);
	}
	dealloc_map(c_map);
}

void	is_map_open(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while ((game->map)[++i] != NULL)
	{
		if (i == 0 || i == game->map_size->row - 1)
		{
			j = -1;
			while (++j < game->map_size->col - 1)
			{
				if ((game->map)[i][j] != WALL)
					_err(game);
			}
		}
		else
		{
			if ((game->map)[i][0] != WALL || (game->map)[i][game->map_size->col
				- 2] != WALL)
				_err(game);
		}
	}
}

int	check_path(char **map, t_point from, int count_e_c)
{
	static int	is_zero_count;
	static int	counter;

	if (!counter)
		counter = count_e_c;
	if (map[from.row][from.col] == WALL)
		return (0);
	if (map[from.row][from.col] == COIN || map[from.row][from.col] == EXIT)
		--counter;
	if (counter == 0)
	{
		is_zero_count = 1;
		return (1);
	}
	map[from.row][from.col] = WALL;
	if (map[from.row + 1][from.col] != WALL)
		check_path(map, (t_point){from.row + 1, from.col}, count_e_c);
	if (map[from.row - 1][from.col] != WALL)
		check_path(map, (t_point){from.row - 1, from.col}, count_e_c);
	if (map[from.row][from.col + 1] != WALL)
		check_path(map, (t_point){from.row, from.col + 1}, count_e_c);
	if (map[from.row][from.col - 1] != WALL)
		check_path(map, (t_point){from.row, from.col - 1}, count_e_c);
	return (is_zero_count);
}
