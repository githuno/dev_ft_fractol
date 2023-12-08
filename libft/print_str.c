/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: runoki <runoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:27:55 by runoki            #+#    #+#             */
/*   Updated: 2023/12/08 20:29:48 by runoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_str(char *str)
{
	size_t	len;

	if (!str)
		return (print_str("(null)"));
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}
