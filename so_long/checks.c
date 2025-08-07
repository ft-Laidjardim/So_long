#include "so_long.h"
#include "mlx/mlx.h"
#include <unistd.h>
#include <fcntl.h>

int map_exists(const char *map_path)//Nome do caminho do arquivo que quero verificar
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

    if(len < 4)
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

int check_map(t_data *data)
{
    if (!has_ben_extension(data->filename))
        return (print_error(2));
    if (!map_exists(data->filename))
        return (print_error(3));
    if (is_rectangle(data->map, data->width))
        return (print_error(4));  
}