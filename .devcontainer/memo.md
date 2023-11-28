# 初期化
/workspace/.devcontainer/init.sh

# --------------------------------------------------

# テストスクリプト実行
./minilibx-linux/test/run_tests.sh

# manを使うには
unminimize
# https://qiita.com/ssc-ynakamura/items/d69307a3d94bf81c363d
man mlx

# 以下、不明箇所
For object files, you could add the following rule to your makefile, 
assuming that you have the mlx 

for linux source in a directory named mlx_linux in the root of your project:

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@


To link with the required internal Linux API:

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


# ./mlx-linux/libmlx.aが省略できる場合とできない場合

# マンデルブロ コンパイル
gcc *.c libft/libft.a -lmlx -lXext -lX11
./a.out mandelbrot

# リークチェック
gcc *.c libft/libft.a -lmlx -lXext -lX11 -fsanitize=address -g
valgrind ./a.out mandelbrot
valgrind --leak-check=full ./a.out mandelbrot