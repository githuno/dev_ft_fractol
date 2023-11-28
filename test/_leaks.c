#include <stdlib.h>

int main() {
   int *p = (int*)malloc(sizeof(int)); // メモリを割り当てる
   *p = 10; // メモリに値を書き込む
   return 0; // メモリを解放しないでプログラムを終了する
}

// 1
// gcc *.c -lmlx -lXext -lX11 -fsanitize=address -g

// 2
// valgrind ./a.out
// valgrind --leak-check=full ./a.out