#include "so_long.h"
#include "mlx/mlx.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int map_exists(const char *map_path) // Nome do caminho do arquivo que quero verificar
{
    int fd;

    fd = open(map_path, O_RDONLY);
    if (fd < 0)
        return (0);
    close(fd);
    return (1);
}

int has_ben_extension(const char *map_name)
{
    int len = ft_strlen(map_name);

    if (len < 4)
        return (0);
    return (ft_strcmp(map_name + len - 4, ".ber") == 0);
}

int is_rectangle(char **map, int width)
{
    int i;

    i = 0;
    while (map[i])
    {
        if (ft_strlen(map[i]) != width)
            return (0);
        i++;
    }
    return (1);
}

int check_elements(t_data *data)
{
    int i;
    int j;
    int player = 0;
    int exit = 0;
    int coin = 0;

    i = 0;
    while (i < data->height)
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == 'P')
                player++;
            else if (data->map[i][j] == 'E')
                exit++;
            else if (data->map[i][j] == 'C')
                coin++;
            j++;
        }
        i++;
    }
    if (player != 1)
        return (0);
    if (exit != 1)
        return (0);
    if (coin < 1)
        return (0);
    return (1);
}

int check_walls(t_data *data)
{
    int i;

    // Verifica a primeira linha
    i = 0;
    while (i < data->width)
    {
        if (data->map[0][i] != '1')
            return (0);
        i++;
    }

    // Verifica as paredes laterais das linhas do meio
    i = 1;
    while (i < data->height - 1)
    {
        if (data->map[i][0] != '1' || data->map[i][data->width - 1] != '1')
            return (0);
        i++;
    }

    // Verifica a última linha
    i = 0;
    while (i < data->width)
    {
        if (data->map[data->height - 1][i] != '1')
            return (0);
        i++;
    }

    return (1);
}

int check_valid_chars(t_data *data)
{
    int i;
    int j;

    i = 0;

    while (i < data->height)
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] != '0' && data->map[i][j] != '1' && data->map[i][j] != 'C' && data->map[i][j] != 'E' && data->map[i][j] != 'P')\
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int check_map(t_data *data)
{
    if (!has_ben_extension(data->filename))
        return (print_error(2));
    if (!map_exists(data->filename))
        return (print_error(3));
    if (!check_walls(data))
        return (print_error(4));
    if (!check_elements(data))
        return (print_error(5));
     if (!is_rectangle(data->map, data->width))
        return (print_error(6));
    if (!check_valid_chars(data))
        return (print_error(7));
    if (!check_path_validity(data))
        return (print_error(8));
    return (1);
}
