#include "so_long.h"

int count_coins(t_data *data)
{
    int i = 0;
    int j;
    int total = 0;

    while (i < data->height)
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == 'C')
                total++;
            j++;
        }
        i++;
    }
    return total;
}

void find_player_position(t_data *data, int *px, int *py)
{
    int i = 0;
    int j;

    while (i < data->height)
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == 'P')
            {
                *px = i;
                *py = j;
                return;
            }
            j++;
        }
        i++;
    }
    *px = -1;
    *py = -1;
}

void flood_fill(t_data *data, int x, int y, int **visited, int *found_exit, int *collected_coins)
{
    if (x < 0 || y < 0 || x >= data->height || y >= data->width)
        return;
    if (data->map[x][y] == '1' || visited[x][y] == 1)
        return;

    visited[x][y] = 1;

    if (data->map[x][y] == 'E')
        *found_exit = 1;
    else if (data->map[x][y] == 'C')
        (*collected_coins)++;

    flood_fill(data, x - 1, y, visited, found_exit, collected_coins);
    flood_fill(data, x + 1, y, visited, found_exit, collected_coins);
    flood_fill(data, x, y - 1, visited, found_exit, collected_coins);
    flood_fill(data, x, y + 1, visited, found_exit, collected_coins);
}

int **create_visited_matrix(int height, int width)
{
    int **visited;
    int i = 0;

    visited = malloc(sizeof(int *) * height);
    if (!visited)
        return NULL;

    while (i < height)
    {
        visited[i] = calloc(width, sizeof(int));
        if (!visited[i])
        {
            while (--i >= 0)
                free(visited[i]);
            free(visited);
            return NULL;
        }
        i++;
    }
    return visited;
}

void free_visited_matrix(int **visited, int height)
{
    int i = 0;
    while (i < height)
    {
        free(visited[i]);
        i++;
    }
    free(visited);
}

int check_path_validity(t_data *data)
{
    int **visited;
    int player_x, player_y;
    int found_exit = 0;
    int collected_coins = 0;
    int total_coins;

    find_player_position(data, &player_x, &player_y);
    if (player_x == -1 || player_y == -1)
        return 0;

    visited = create_visited_matrix(data->height, data->width);
    if (!visited)
        return 0;

    total_coins = count_coins(data);

    flood_fill(data, player_x, player_y, visited, &found_exit, &collected_coins);

    free_visited_matrix(visited, data->height);

    if (found_exit == 1 && collected_coins == total_coins)
        return 1;
    return 0;
}
