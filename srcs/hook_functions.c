/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <ljessica@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:26:56 by ljessica          #+#    #+#             */
/*   Updated: 2025/09/08 15:26:58 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_window(t_game *game)
{
	free_structs(game);
	exit (0);
}

int	key_input(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		close_window(game);
	if (keysym == XK_A || keysym == XK_a || keysym == XK_Left)
		press_left(game);
	if (keysym == XK_D || keysym == XK_d || keysym == XK_Right)
		press_right(game);
	if (keysym == XK_W || keysym == XK_w || keysym == XK_Up)
		press_up(game);
	if (keysym == XK_S || keysym == XK_s || keysym == XK_Down)
		press_down(game);
	return (0);
}
