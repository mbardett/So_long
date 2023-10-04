/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:07:32 by mbardett          #+#    #+#             */
/*   Updated: 2022/09/17 13:29:19 by mbardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

void	open_enemy_imgs(t_game *game)
{
	game->enemy.frame_count = 0;
	game->enemy.e_frame1 = mlx_xpm_file_to_image(game->mlx, "xpm/Enemy.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
}

void	enemy_anim(t_game *game, int j, int i)
{
	game->enemy_mesh = game->enemy.e_frame1;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->enemy_mesh, j, i);
}

// yeah, now it seems a waste of time but I swear it was longer before
void	draw_enemy(t_game *game, int i, int j, char c)
{
	if (c == 'M')
		enemy_anim(game, j, i);
}
