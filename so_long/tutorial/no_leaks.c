#include "mlx/mlx.h"
#include <stdlib.h>
int main()
{
    void *janela;
    void *programa;
    void *imagem;
    int largura, altura;

    programa = mlx_init();
    if(!programa)
        return(0);
    janela = mlx_new_window(programa, 64, 64, "bichinho");
    if (!janela)
        return (1);
    imagem = mlx_xpm_file_to_image(programa, "imagem.xpm", &largura, &altura);
    if (!imagem)
        return (2);
    mlx_put_image_to_window(programa, janela, imagem, 0, 0);
    mlx_hook(janela, 17, 1, mlx_loop_end, programa);
    mlx_loop(programa);
    if (imagem && programa)// se existir programa e janela 
        mlx_destroy_image(programa, imagem);//funcao que limpa imagem para nao ter vazamento de memoria
    if (janela && programa)
        mlx_destroy_window(programa, janela);
    if (programa)
    {
        mlx_destroy_display(programa);
        free(programa);// depois de usar o destroy display tem sempre que usar o free pq fica 1 sobrando
    }
}