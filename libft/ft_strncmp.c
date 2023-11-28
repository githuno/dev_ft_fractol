/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: runoki <runoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 06:41:45 by runoki            #+#    #+#             */
/*   Updated: 2023/11/17 16:37:05 by runoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	if (s1 == NULL || s2 == NULL)
// 		return (0);
// 	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
// 		i++;
// 	if (i == n)
// 		return (0);
// 	return (s1[i] - s2[i]);
// }
//
// ------------------------------------------------------------
// 以下を追記
// strncmpとの違いは、n文字目までしか比較しないということ
// つまり、n文字目まで同じであれば、その後の文字列は比較しない
// つまり、n文字目まで同じであれば、その後の文字列は比較しない
// ("test\200", "test\0", 6)を渡した時、128になるようにするには以下のように修正する

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0 && *s1 != '\0')
	{
		++s1;
		++s2;
		--n;
	}
	return (*s1 - *s2);
}
// int main(void)
// {
// 	char *s1 = "test\200";
// 	char *s2 = "test\0";
// 	printf("\"test\\200\", \"test\\0\", 6\n");
// 	printf("%d\n", ft_strncmp(s1, s2, 6));
// 	printf("%d\n", strncmp(s1, s2, 6));
// 	return (0);
// }
