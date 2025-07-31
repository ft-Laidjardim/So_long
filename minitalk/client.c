#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

void    enviar_caractere(pid_t pid, unsigned char c)
{
    int i = 7;

    while (i >= 0)
    {
        if ((c >> i) & 1)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        usleep(1000);
        i--;
    }
}

int main(int argc, char **argv)
{
    pid_t pid;
    char *mensagem;
    int i;

    if (argc != 3)
    {
        write(1, "Uso: ./client <PID> <mensagem>\n", 32);
        return (1);
    }

    pid = atoi(argv[1]);
    mensagem = argv[2];
    i = 0;

    while (mensagem[i] != '\0')
    {
        enviar_caractere(pid, mensagem[i]);
        i++;
    }

    // Envia o caractere nulo '\0' para indicar fim da string
    enviar_caractere(pid, '\0');

    return (0);
}
