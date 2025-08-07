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


int tamanho_do_mapa(char *mapa_arquivo)
{
    int fd;
    int tamanho;

    fd = open(mapa_arquivo, O_RDONLY);
    tamanho = 0;
    while (get_next_line(fd))
        tamanho++;
    close(fd);
    return (tamanho);//linhas 
}

int main(int argc, char **argv)
{
    int fd;
    int i;
    char **mapa;
    t_data  my_data;
    
    if (argc != 2)
        return (print_error(1));
    my_data.filename = argv[1];
    check_map(&my_data);
    my_data.height = tamanho_do_mapa(argv[1]);
    if (my_data.height <= 0)
    {
        printf("Erro: mapa vazio ou inválido.\n");
        return (1);
    }

    mapa = calloc(my_data.height, sizeof(char *));
    if (!mapa)
    {
        printf("Erro: malloc falhou.\n");
        return (1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        printf("Erro ao abrir o arquivo.\n");
        return (1);
    }

    i = 0;
    while (i < my_data.height)
    {
        mapa[i] = get_next_line(fd);
        if (!mapa[i])
        {
            printf("Erro ao ler linha %d do mapa.\n", i);
            close(fd);
            return (1);
        }
        i++;
    }
    close(fd);
    my_data.map = mapa;
    my_data.width = ft_strlen(mapa[0]) - 1; // remove o '\n'

    // Remove o '\n' no final de cada linha
    i = 0;
    while (i < my_data.height)
    {
        if (mapa[i][my_data.width] == '\n')
            mapa[i][my_data.width] = '\0';
        i++;
    }

    // Verifica se todas as linhas têm o mesmo comprimento
    i = 0;
    while (i < my_data.height)
    {
        if (ft_strlen(mapa[i]) != my_data.width)
        {
            printf("Erro: linhas de tamanhos diferentes no mapa.\n");
            return (1);
        }
        i++;
    }

    printf("Mapa carregado com sucesso.\n");

    // Libere a memória
    i = 0;
    while (i < my_data.height)
    {
        free(mapa[i]);
        i++;
    }
    free(mapa);

    return (0);
}
