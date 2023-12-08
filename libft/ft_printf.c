/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: runoki <runoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:23:17 by runoki            #+#    #+#             */
/*   Updated: 2023/12/08 20:26:42 by runoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_by_type(va_list argp, const char c)
{
	if (c == 'c')
		return (print_char(va_arg(argp, int)));
	else if (c == 's')
		return (print_str(va_arg(argp, char *)));
	else if (c == 'p')
		return (print_multihex(va_arg(argp, void *), -1));
	else if (c == 'd' || c == 'i')
		return (print_int(va_arg(argp, int)));
	else if (c == 'u')
		return (print_unsigned(va_arg(argp, unsigned int)));
	else if (c == 'x')
		return (print_multihex(va_arg(argp, void *), 0));
	else if (c == 'X')
		return (print_multihex(va_arg(argp, void *), 1));
	else if (c == '%')
		return (print_char('%'));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	argp;
	int		print_len;

	i = 0;
	print_len = 0;
	va_start(argp, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			print_len += print_by_type(argp, str[i + 1]);
			i++;
		}
		else
			print_len += print_char(str[i]);
		i++;
	}
	va_end(argp);
	return (print_len);
}
