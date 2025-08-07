#include <stdio.h>

int print_error(int code)
{
    if (code == 1)
        perror("Error:\nCorrect use -> ./so_long <map.ber>\n");
    else if (code == 2)
        perror("Error:\nThe file does not have a .ber extension\n");
    else if (code == 3)
        perror("ERROR:\n");
}