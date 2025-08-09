#include <stdio.h>

int print_error(int code)
{
    if (code == 1)
        perror("Error:\nCorrect use -> ./so_long <map.ber>\n");
    else if (code == 2)
        perror("Error:\nThe file does not have a .ber extension\n");
    else if (code == 3)
        perror("Error:\nMap file does not exist or cannot be opened\n");
    else if (code == 6)
        perror("Error:\nMap is not rectangular\n");
    else if (code == 5)
        perror("Error:\nMap must have 1 player, 1 exit, and at least 1 collectible\n");
    else if (code == 4)
        perror("Error:\nMap is not surrounded by walls\n");
    else if (code == 7)
        perror("Error:\nMap contains invalid characters\n");
    else if (code == 8)
    perror("Error:\nNo valid path from player to exit collecting all coins\n");
    return (0);
}