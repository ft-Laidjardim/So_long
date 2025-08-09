/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <ljessica@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:21:35 by ljessica          #+#    #+#             */
/*   Updated: 2025/08/07 12:57:01 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"
#include "mlx/mlx.h"
#include <fcntl.h>
#include <stdlib.h>
#include "gnl.h"
#include <stdio.h>


int tamanho_do_mapa(char *mapa_arquivo)
{
    int fd;
    int tamanho;
    char *line;

    fd = open(mapa_arquivo, O_RDONLY);
    if (fd < 0)
        return 0;

    tamanho = 0;
    line = get_next_line(fd);
    while (line)
    {
        free(line);  // LIBERA A LINHA LIDA ANTES DE PEGAR A PRÓXIMA
        tamanho++;
        line = get_next_line(fd);
    }
    close(fd);
    return tamanho;
}

int main(int argc, char **argv)
{
    int fd;
    int i;
    t_data my_data;

    if (argc != 2)
        return (print_error(1));

    my_data.filename = argv[1];

    // Primeiro, validar extensão e existência
    if (!has_ben_extension(my_data.filename))
        return (print_error(2));
    if (!map_exists(my_data.filename))
        return (print_error(3));

    // Ler mapa
    my_data.height = tamanho_do_mapa(argv[1]);
    if (my_data.height <= 0)
        return (print_error(3));

    my_data.map = calloc(my_data.height + 1, sizeof(char *));
    if (!my_data.map)
        return (1);

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return (print_error(3));

    i = 0;
    while (i < my_data.height)
    {
        my_data.map[i] = get_next_line(fd);
        if (!my_data.map[i])
        {
            free_map(my_data.map, i);
            close (fd);
            return (1);
        }
        // Remove o '\n' se houver
        int len = ft_strlen(my_data.map[i]);
        if (len > 0 && my_data.map[i][len - 1] == '\n')
            my_data.map[i][len - 1] = '\0';
        i++;
    }
    close(fd);

    my_data.width = ft_strlen(my_data.map[0]);

    // Agora valida retângulo e elementos
    if (!check_map(&my_data))
        return (1);

    printf("Mapa carregado e verificado com sucesso.\n");

    // Libera memória
    i = 0;
    while (i < my_data.height)
        free(my_data.map[i++]);
    free(my_data.map);

    return (0);
}

