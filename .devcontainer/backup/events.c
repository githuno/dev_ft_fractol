#include "fractol.h"
static void set_mouse_point(int x, int y, t_fractol *fractal)
{
	printf("\n----> mouse\n");//debug
    t_complex   point;

	point = scaled_point(x, y, fractal);
	fractal->mouse_x = point.x; // ディスプレイ基準のマウスポイント
    fractal->mouse_y = point.y; // ディスプレイ基準のマウスポイント
}

int     close_w(t_fractol *fractal)
{
    mlx_destroy_image(fractal->mlx, fractal->img.ptr);
	mlx_destroy_window(fractal->mlx, fractal->win);
    mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
    exit(EXIT_SUCCESS);
    return (EXIT_SUCCESS);
}

int     ctl_key(int keysym, t_fractol *fractal)
{
    if (keysym == XK_Escape)
        close_w(fractal);
    else if (keysym == XK_Left)
        fractal->shift_x -= 0.1;
    else if (keysym == XK_Up)
        fractal->shift_y += 0.1;
    else if (keysym == XK_Right)
        fractal->shift_x += 0.1;
    else if (keysym == XK_Down)
        fractal->shift_y -= 0.1;
    else if (keysym == XK_plus)
        fractal->iterations *= 2; //colorだけの変更は必要？
        // fractal->color_low += 50;
    else if (keysym == XK_minus)
        fractal->iterations /= 2;
    else if (keysym == XK_r)
        // fractal->high_color = rand() % 0xFFFFFF;
        fractal->high_color /= (fractal->mouse_x * fractal->mouse_x);
        // fractal->color_high -= 50;
    // else if (keysym == PLUS)
    //     fractal->color += 100;
    // else if (keysym == MINUS)
    //     fractal->color -= 100;
    else if (keysym == XK_1)
        set_params(fractal, "mandelbrot", WHITE, mandelbrot);
    else if (keysym == XK_2)
        set_params(fractal, "julia", NEON_ORANGE, julia);
    else if (keysym == XK_3)
        set_params(fractal, "mandelbar", LIME_SHOCK, mandelbar);
    else if (keysym == XK_z)
        set_params(fractal, fractal->name, AQUA_DREAM, fractal->algo);
    ft_printf("keysym = %d\n", keysym); //debug
    // ft_printf("fractal->iterations = %d\n", fractal->iterations); //debug 
    rendering(fractal);
    return (0);
}

int     ctl_mouse(int keysym, int x, int y, t_fractol *fractal)
{
    printf("\n----> mouse: %d\n", keysym);//debug
    
    printf("\nzoom前の原点の画面上の座標 = (%lf, %lf)\n" // mandelbrotの原点（0,0）が画面上のどこにあるかを表示
        , -(fractal->shift_x*fractal->zoom)  //debug
        , -(fractal->shift_y*fractal->zoom)); //debug
    
    if (keysym == Button4){ // マウスホイールを上に回したとき
        set_mouse_point(x, y, fractal);
        printf("fractal->mouse_x = %lf -> %lf\n", fractal->mouse_x, fractal->mouse_x / (fractal->zoom *1.1) + fractal->shift_x); //debug
        printf("fractal->mouse_y = %lf -> %lf\n", fractal->mouse_y, fractal->mouse_y / (fractal->zoom *1.1) + fractal->shift_y); //debug
        fractal->shift_x -= fractal->mouse_x / (fractal->zoom *1.1)
                                 + fractal->shift_x - fractal->mouse_x;
        fractal->shift_y -= fractal->mouse_y / (fractal->zoom *1.1)
                                 + fractal->shift_y - fractal->mouse_y;
        // t_complex   zoomed_point;
        // zoomed_point = scaled_point(fractal->mouse_x, fractal->mouse_y, fractal);
        // fractal->shift_x -= (0.9 * zoomed_point.x) / (1.1 * fractal->zoom);
        // fractal->shift_y += (0.9 * zoomed_point.y) / (1.1 * fractal->zoom);
        fractal->zoom *= 1.1;
    }
    else if (keysym == Button5){ // マウスホイールを下に回したとき
        set_mouse_point(x, y, fractal);
        fractal->shift_x -= fractal->mouse_x / (fractal->zoom /1.1)
                                 + fractal->shift_x - fractal->mouse_x;
        fractal->shift_y -= fractal->mouse_y / (fractal->zoom /1.1)
                                 + fractal->shift_y - fractal->mouse_y;
        fractal->zoom /= 1.1;
    }       
    // クリックしたらx,yをコンソールに表示する
    else if (keysym == Button1){   
        // set_mouse_point(x, y, fractal);
        printf("クリックイベント：(x,y) = (%d, %d)\n", x, y); //debug
        printf("クリックイベント：c(x,y) = (%lf, %lf) \n", fractal->mouse_x, fractal->mouse_y); //debug
    }
    else if (keysym == Button3){
        set_mouse_point(x, y, fractal);
        printf("fractol->high_color = %d\n", fractal->high_color); //debug
        if(fractal->high_color == 0)
            fractal->high_color = 0xFFFFFF;
        else
            fractal->high_color /= fractal->mouse_x / fractal->mouse_y;
    }
        

    printf("zoom後の原点の画面上の座標 = (%lf, %lf)\n" // mandelbrotの原点（0,0）が画面上のどこにあるかを表示
        , -(fractal->shift_x*fractal->zoom)  //debug
        , -(fractal->shift_y*fractal->zoom)); //debug
    rendering(fractal);
    return (0);
}

int     ctl_julia(int x, int y, t_fractol *fractal) //macでもサクサク動かないならいらなそう
{
    printf("fractal->name = %s\n", fractal->name); 
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		set_mouse_point(x, y, fractal);
		rendering(fractal);
	}
	return 0;
}