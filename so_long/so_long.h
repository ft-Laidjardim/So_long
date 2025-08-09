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

// Funções de checks
int     map_exists(const char *map_path);
int     has_ben_extension(const char *map_name);
int     is_rectangle(char **map, int width);
int     check_elements(t_data *data);
int     check_map(t_data *data);
int     print_error(int code);

// Funções utilitárias
int     ft_strcmp(const char *s1, const char *s2);

#endif
