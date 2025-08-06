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
    int chars_por_linha;
    int qtd_linha_mapa;
    char **mapa;


    if (argc != 2)
        return (1); //problema
    qtd_linha_mapa = tamanho_do_mapa(argv[1]);
    fd = open(argv[1], O_RDONLY);
    i = 0;
    mapa = calloc(qtd_linha_mapa, sizeof(char *));
    while(i < qtd_linha_mapa)
    {
        mapa[i] = get_next_line(fd);
        i++;
    }
    close(fd);
    chars_por_linha = ft_strlen(mapa[0]) - 1;
    i = 0;
    while (i < qtd_linha_mapa)
    {
        mapa[i][chars_por_linha] = '\0';
        i++;
    }
    i = 0;
    while (i < qtd_linha_mapa)
    {
        if (ft_strlen(mapa[i] != chars_por_linha))
            return (0);
    }
}