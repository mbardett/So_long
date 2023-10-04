/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:54:51 by mbardett          #+#    #+#             */
/*   Updated: 2022/09/21 17:26:50 by mbardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/lib.h"

int	end_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_coordinate	data;
	t_game			game;

	check_arg_ber(argc, argv);
	read_file(argv[1], &data);
	check_map_requirements(&data, &game);
	game.dimensions = &data;
	game_init(&game);
	open_all_sources(&game);
	game.level_init = 1;
	game.time = 1;
	mlx_hook(game.mlx_win, 2, 0, deal_inputs, &game);
	mlx_hook(game.mlx_win, 17, 0, end_game, &game);
	mlx_loop_hook(game.mlx, draw, (void *)&game);
	mlx_loop(game.mlx);
	return (0);
}
