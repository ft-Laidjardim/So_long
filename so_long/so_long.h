/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <ljessica@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:24:17 by ljessica          #+#    #+#             */
/*   Updated: 2025/08/07 12:46:48 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl.h"

typedef struct s_game
{
    void    *mlx;//programa
    void    *window;//janela
    int     width;//largura
    int     height;//altura
    char    *filename;//nome do mapa
    char    **map;
}   t_data;




#endif
