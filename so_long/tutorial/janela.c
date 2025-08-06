#include "mlx/mlx.h"
#include <unistd.h>

int pegadinha(void *nada)
{
    write(1, "hah", 3);
}

int main()
{
    void    *janela;//window
    void    *programa; //mlx

    programa = mlx_init();//Depois verifica certo ou errado
    janela = mlx_new_window(programa, 100, 60, "Laid");// poneiro par o programa, largura, altura, nome da janela
    mlx_hook(janela, 17, 1, mlx_loop_end, programa); // janela, codigo do evendo de fechar a janela, numero 1, funcao de encerrar o loop, parametro que sera enviado para a funcao 
    mlx_loop(programa);// criar loop infinito para janela ficar aberta 
}
// esse programa cria uma janela