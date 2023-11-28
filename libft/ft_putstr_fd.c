/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: runoki <runoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 09:02:47 by runoki            #+#    #+#             */
/*   Updated: 2023/06/17 13:58:02 by runoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Outputs the string ’s’ to the given file descriptor.
// sがNULLの場合は何もしないよう修正

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

// write（出力先、出力データ、出力データの長さ）

// #include <fcntl.h>
// int main() {
//     int fd = open("output.txt", O_WRONLY | O_CREAT, 0644); // ファイルディスクリプタを開く

//     if (fd == -1) {
//         // エラーハンドリング
//         return (1);
//     }

//     char *message = "Hello, world!\n";
//     ft_putstr_fd(message, fd); // 指定したファイルディスクリプタに出力

//     close(fd); // ファイルディスクリプタを閉じる

//     return (0);
// }
