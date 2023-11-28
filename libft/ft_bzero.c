/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: runoki <runoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 06:31:11 by runoki            #+#    #+#             */
/*   Updated: 2023/06/17 14:09:13 by runoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// パラメータがNULLの場合は何もしないように修正
	// if (!s)
	// 	return;

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

// int	main(void)
// {
// 	char	str[10];

// 	str[0] = 'H';
// 	str[1] = 'e';
// 	printf("Before: %s\n", str);
// 	ft_bzero(str, 1);
// 	printf("After: %s\n", str);
// 	printf("After: %c\n", str[1]);
// 	return (0);
// }
