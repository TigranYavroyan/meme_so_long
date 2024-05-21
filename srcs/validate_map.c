/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:51:29 by tyavroya          #+#    #+#             */
/*   Updated: 2024/05/20 14:09:11 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static int	is_valid_char(char ch)
{
	return (ch == '1' || ch == '0' || ch == 'P' || ch == 'C' || ch == 'E'
		|| ch == 'O');
}

static void	adder(char ch, t_for_check *for_ch, t_game *game)
{
	if (ch == PLAYER)
	{
		++(for_ch->player);
		game->player->row = for_ch->i;
		game->player->col = for_ch->j;
	}
	else if (ch == EXIT)
	{
		++(for_ch->exit);
		game->exit->row = for_ch->i;
		game->exit->col = for_ch->j;
	}
	else if (ch == COIN)
		++(game->coins_count);
}

void	check_map_size(t_game *game)
{
	int	i;

	i = 1;
	game->map_size->col = ft_strlen(game->map[0]);
	while ((game->map)[i] != NULL)
	{
		if (game->map_size->col != (int)ft_strlen((game->map)[i]))
			_err(game);
		++i;
	}
	if (i < MIN_MAP_SIZE)
		_err(game);
}

static void	init_for_check(t_for_check *for_check)
{
	for_check->i = -1;
	for_check->player = 0;
	for_check->exit = 0;
}

void	check_maps_elements(t_game *game)
{
	t_for_check	for_ch;

	init_for_check(&for_ch);
	while ((game->map)[++for_ch.i] != NULL)
	{
		for_ch.j = -1;
		while (++for_ch.j < game->map_size->col - 1)
		{
			if (is_valid_char((game->map)[for_ch.i][for_ch.j]))
				adder((game->map)[for_ch.i][for_ch.j], &for_ch, game);
			else
				_err(game);
		}
	}
	if (for_ch.player != 1 || for_ch.exit != 1 || game->coins_count < 1)
		_err(game);
}
