#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
// # include "minilibx-linux/mlx.h"

# include "mlx/mlx.h"
# include <math.h>
// # include "minilibx-linux/mlx_int.h" //XStoreName
// # include <X11/X.h> // マウスイベント
// # include <X11/keysym.h> // キーイベント

# define ARG_ERROR_MSG "Wrong args...This program requires only one argument, \n \
										\'julia\', \'mandelbrot\' or \'burning\'\n"

// windows size
#define WIDTH	800
#define	HEIGHT	800
// coordinate size
#define RADIUS	2.0

// COLORS
#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)
#define RED         0xFF0000  // RGB(255, 0, 0)
#define GREEN       0x00FF00  // RGB(0, 255, 0)
#define BLUE        0x0000FF  // RGB(0, 0, 255)
#define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
#define LIME_SHOCK      0xCCFF00  // A blinding lime
#define NEON_ORANGE     0xFF6600  // A blazing neon orange
#define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
#define AQUA_DREAM      0x33CCCC  // A bright turquoise
#define HOT_PINK        0xFF66B2  // As the name suggests!
#define ELECTRIC_BLUE   0x0066FF  // A radiant blue
#define LAVA_RED        0xFF3300  // A bright, molten red

typedef struct {
	void	*ptr;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct {
	double	x;
	double	y;
	int 	color;
}			t_complex;

t_complex	sqr(t_complex a);
t_complex	add(t_complex a, t_complex b);
t_complex	cnj(t_complex a);
double		map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);

typedef struct {
	char 		*name;
	int			(*algo)();
	void		*mlx;

	void		*win; //アドレス渡しに変更する
	double		w_width;
	double		w_height;
	double		w_aspect;

	t_image		img; //アドレス渡しに変更する❌ → x,yに応じて非同期にメモリを動かしてるのか、img.addrが動的に替わりput_pixelで失敗した
	t_complex	complex; //アドレス渡しに変更する❌ → 閉じた後メモリ解放がうまくいかなかった
	double		c_radius;
	double		zoom;
	int			iterations;
	double		mouse_x;
	double		mouse_y;
	double		shift_x;
	double		shift_y;
	int 		high_color;
}				t_fractol;

void		xdisplay_init(t_fractol *fractal);
void		set_params(t_fractol *fractal, char *name, int color, int (*algo)(double, double, t_fractol *));

t_complex	scaling(int x, int y, t_fractol *fractal, int isShift);
void		rendering(t_fractol *fractal);

// int test_algo(double x, double y, t_fractol *fractal);//debug
int			mandelbrot(double x, double y, t_fractol *fractal);
int			julia(double x, double y, t_fractol *fractal);
int			mandelbar(double x, double y, t_fractol *fractal);

int			close_w(t_fractol *fractal);
int			ctl_key(int keysym, t_fractol *fractal);
int			ctl_mouse(int keysym, int x, int y, t_fractol *fractal);
int			ctl_julia(int x, int y, t_fractol *fractal); //マックでもサクサク動かないなら消す

void makeLog(); //debug
void writeToLogfile(const char *format, ...); //debug

#endif
