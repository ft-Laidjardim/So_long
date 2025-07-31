#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

void    tratar_sinais(int signum)
{
    static unsigned char caractere = 0;
    static int  bits_recebidos = 0;

    caractere <<=1;
    if (signum == SIGUSR2)
        caractere += 1;
    bits_recebidos++;

    if (bits_recebidos == 8)
    {
        if (caractere == '\0')
            write(1, "\n", 1);
        else
            write(1, &caractere, 1);
        caractere = 0;
        bits_recebidos = 0;
    }
}

int main(void)
{
    pid_t pid;

    pid = getpid();
    printf("Servidor iniciado! PID: %d\n", pid);
    fflush(stdout); // <-- Adicione esta linha

    signal(SIGUSR1, tratar_sinais);
    signal(SIGUSR2, tratar_sinais);

    //loop infinito esperando sinais
    while (1)
        pause();
    return (0);
}