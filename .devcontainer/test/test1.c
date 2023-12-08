#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int main(void)
{
	void *mlx;
	void *mlx_win;
	t_data img;
	int i;
	int j;
	int k;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1280, 720, "Hello world!");
	img.img = mlx_new_image(mlx, 1280, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	for (i = 200, k = 99; i < 300; i++, k -= 1)
	{
		for (j = 150 + k; j < 250; j++)
			my_mlx_pixel_put(&img, i, j, 0x00FFFF00);
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 150, 150);

	// リレンダリングするとノイズ
	i = 0;
	while(i < 100000){
		printf("i = %d\n", i);
		i++;
	}
	
	mlx_destroy_image(mlx, img.img);
	void *tmp_mlx;
	void *tmp_win;
	tmp_win = mlx_win;
	tmp_mlx = mlx;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1280, 720, "Hello world!2");
	img.img = mlx_new_image(mlx, 1280, 720);
	
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	for (i = 200, k = 99; i < 300; i++, k -= 1)
	{
		for (j = 150 + k; j < 250; j++)
			my_mlx_pixel_put(&img, i, j, 0x00FFFF00);
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 150, 150);
	mlx_destroy_window(tmp_mlx, tmp_win);
	mlx_destroy_display(tmp_mlx);
	printf("ok\n");
	// リレンダリングするとノイズ
	mlx_loop(mlx);

	// i = 0;
	// while(i < 1000000){
	// 	printf("i = %d\n", i);
	// 	i++;
	// }
// 	mlx_destroy_image(mlx, img.img);
// 	mlx_destroy_window(mlx, mlx_win);
// 	mlx_destroy_display(mlx);
// 	free(mlx);
// 	printf("ok\n");
//     exit(EXIT_SUCCESS);
//     return (EXIT_SUCCESS);
}