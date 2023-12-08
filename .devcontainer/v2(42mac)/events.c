#include "fractol.h"

int     close_w(t_fractol *fractal)
{
    mlx_destroy_image(fractal->mlx, fractal->img.ptr);
	mlx_destroy_window(fractal->mlx, fractal->win);
    // mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
    exit(EXIT_SUCCESS);
    return (EXIT_SUCCESS);
}

int     ctl_key(int keysym, t_fractol *fractal)
{
    printf("keysym = %d\n", keysym);
    if (keysym == 53)
        close_w(fractal);
    else if (keysym == 123)
        fractal->shift_x -= 0.1;
    else if (keysym == 126)
        fractal->shift_y += 0.1;
    else if (keysym == 124)
        fractal->shift_x += 0.1;
    else if (keysym == 125)
        fractal->shift_y -= 0.1;
    else if (keysym == 24)
        fractal->iterations *= 1.1; //colorだけの変更は必要？
        // fractal->color_low += 50;
    else if (keysym == 27)
        fractal->iterations /= 1.1;
    // else if (keysym == 15)
    // // else if (keysym == PLUS)
    // //     fractal->color += 100;
    // // else if (keysym == MINUS)
    // //     fractal->color -= 100;
    else if (keysym == 18)
        set_params(fractal, "mandelbrot", WHITE, mandelbrot);
    else if (keysym == 19)
        set_params(fractal, "julia", NEON_ORANGE, julia);
    else if (keysym == 20)
        set_params(fractal, "mandelbar", LIME_SHOCK, mandelbar);
    else if (keysym == 6)
        set_params(fractal, fractal->name, AQUA_DREAM, fractal->algo);
    // ft_printf("keysym = %d\n", keysym); //debug
    // ft_printf("fractal->iterations = %d\n", fractal->iterations); //debug
    rendering(fractal);
    return (0);
}

int     ctl_mouse(int keysym, int x, int y, t_fractol *fractal)
{
    // set_mouse_point(x, y, fractal);

    printf("\nzoom前の原点の画面上の座標 = (%lf, %lf)\n" // mandelbrotの原点（0,0）が画面上のどこにあるかを表示
        , -(fractal->shift_x*fractal->zoom)  //debug
        , -(fractal->shift_y*fractal->zoom)); //debug
    printf("keysym = %d\n", keysym);

    if (keysym == 4){ // マウスホイールを上に回したとき
        fractal->mouse_x = scaling(x, y, fractal, 1).x;
        fractal->mouse_y = scaling(x, y, fractal, 1).y;
        printf("(mouse_x,mouse_y) = (%lf,%lf), (zoomed_x,zoomed_y) = (%lf,%lf)\n"
            ,fractal->mouse_x,fractal->mouse_y
            ,fractal->mouse_x * 1.1
            ,fractal->mouse_y * 1.1);

        // printf("(shift_x,shift_y) = (%lf, %lf), (zoomed_x,zoomed_y) = (%lf,%lf)\n",
        //     fractal->shift_x,fractal->shift_y
        //     ,fractal->shift_x - ((fractal->mouse_x / fractal->zoom *1.1) + fractal->shift_x - fractal->mouse_x)
        //     ,fractal->shift_y - ((fractal->mouse_y / fractal->zoom *1.1) + fractal->shift_y - fractal->mouse_y));

        fractal->shift_x += ((fractal->mouse_x * 1.1)  - fractal->mouse_x);
        fractal->shift_y += ((fractal->mouse_y * 1.1)  - fractal->mouse_y);
        // fractal->shift_x -= fractal->mouse_x / (fractal->zoom *1.1)
        //                          + fractal->shift_x - fractal->mouse_x;
        // fractal->shift_y -= fractal->mouse_y / (fractal->zoom *1.1)
        //                          + fractal->shift_y - fractal->mouse_y;
        fractal->zoom *= 1.1;
        // fractal->iterations++;
    }
    else if (keysym == 5){ // マウスホイールを下に回したとき

        fractal->mouse_x = scaling(x, y, fractal, 1).x;
        fractal->mouse_y = scaling(x, y, fractal, 1).y;

        // fractal->shift_x -= ((fractal->mouse_x / fractal->zoom /1.1)  - fractal->mouse_x);
        // fractal->shift_y -= ((fractal->mouse_y / fractal->zoom /1.1)  - fractal->mouse_y);

        // fractal->shift_x -= fractal->mouse_x / (fractal->zoom /1.1)
        //                          + fractal->shift_x - fractal->mouse_x;
        // fractal->shift_y -= fractal->mouse_y / (fractal->zoom /1.1)
        //                          + fractal->shift_y - fractal->mouse_y;
        fractal->shift_x += ((fractal->mouse_x / 1.1)  - fractal->mouse_x);
        fractal->shift_y += ((fractal->mouse_y / 1.1)  - fractal->mouse_y);
        fractal->zoom /= 1.1;
        // fractal->iterations--;
    }
    // クリックしたらx,yをコンソールに表示する
    else if (keysym == 1){

        printf("クリックイベント：(x,y) = (%d, %d)\n", x, y); //debug
        fractal->mouse_x = scaling(x, y, fractal, 0).x;
        fractal->mouse_y = scaling(x, y, fractal, 0).y;
        printf("クリックイベント：c(x,y) = (%lf, %lf) \n", fractal->mouse_x, fractal->mouse_y); //debug
        printf("クリックイベント：(shift_x,shift_y) = (%lf, %lf)\n", fractal->shift_x,fractal->shift_y); //debug
        fractal->mouse_x = scaling(x, y, fractal, 1).x;
        fractal->mouse_y = scaling(x, y, fractal, 1).y;
        printf("クリックイベント：shif_c(x,y) = (%lf, %lf) \n", fractal->mouse_x, fractal->mouse_y); //debug
    }
    else if (keysym == 2){
        fractal->mouse_x = scaling(x, y, fractal, 0).x;
        fractal->mouse_y = scaling(x, y, fractal, 0).y;
        printf("high_color%d\n", fractal->high_color);
        if(fractal->high_color == 0)
            fractal->high_color = 0xFFFFFF;
        else
            fractal->high_color /= (fractal->mouse_x / fractal->mouse_y);
        // fractal->high_color /= (fractal->mouse_x * fractal->mouse_x);
    }

    printf("zoom後の原点の画面上の座標 = (%lf, %lf)\n" // mandelbrotの原点（0,0）が画面上のどこにあるかを表示
        , -(fractal->shift_x*fractal->zoom)  //debug
        , -(fractal->shift_y*fractal->zoom)); //debug
    rendering(fractal);
    return (0);
}

int     ctl_julia(int x, int y, t_fractol *fractal) //macでもサクサク動かないならいらなそう
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->mouse_x = scaling(x, y, fractal, 0).x;
        fractal->mouse_y = scaling(x, y, fractal, 0).y;
		rendering(fractal);
	}
	return 0;
}

//  macはマウス逆かも　要件確認すべし
