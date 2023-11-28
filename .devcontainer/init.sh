#!/bin/bash

cd /workspace
tar -xvzf ./.devcontainer/minilibx-linux.tgz -C ./

cd ./minilibx-linux
./configure

# `#include <mlx.h>`` を実行可能にする
cp -i ./mlx.h /usr/local/include/mlx.h
# MinilibX関数をリンク時に使用可能にする（`gcc init.c -lmlx -lXext -lX11`）?
cp -i ./libmlx.a ./libmlx_Linux.a /usr/local/lib/
# `man mlx`を実行可能にする（エラーが出たら`unminimize`が必要）?
cp -i ./man/man3/mlx.3 /usr/local/man/man3/mlx.3

cd ../
# イニシャライズ
# (gcc init.c ./minilibx-linux/libmlx.a -lXext -lX11)
# (gcc init.c -L/usr/local/lib -lmlx -lXext -lX11)
gcc ./.devcontainer/init.c -lmlx -lXext -lX11

./a.out