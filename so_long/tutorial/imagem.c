#include "mlx/mlx.h"

int main()
{
    void *janela;
    void *programa;
    void *imagem;
    int largura, altura;

    programa = mlx_init();
    if (!programa)
        return (1);//mesagem futuramente
    janela = mlx_new_window(programa, 64, 64, "bichinho");
    if (!janela)
        return (2);//messagem futuramente
    imagem = mlx_xpm_file_to_image(programa, "imagem.xpm", &largura, &altura);// puxa o arquivo imagem xpm para o programa
    if (!imagem)
        return (3);
    mlx_put_image_to_window(programa, janela, imagem, 0, 0); // e essa coloca a imagem na janela 
    mlx_hook(janela, 17, 1, mlx_loop_end, programa);
    mlx_loop(programa);
}