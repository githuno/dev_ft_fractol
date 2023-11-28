#include "libft.h"

int print_by_type(va_list argp, const char c)
{
	if (c == 'c')
		return (print_char(va_arg(argp, int)));
	else if (c == 's')
		return (print_str(va_arg(argp, char *)));
	else if (c == 'p')
		// return (print_pointer(va_arg(argp, void *), 0));
		return (print_multihex(va_arg(argp, void *), -1));
	else if (c == 'd' || c == 'i')
		return (print_int(va_arg(argp, int)));
	else if (c == 'u')
		return (print_unsigned(va_arg(argp, unsigned int)));
	else if (c == 'x')
		// return (print_hex(va_arg(argp, int), 0));
		return (print_multihex(va_arg(argp, void *), 0));
	else if (c == 'X')
		// return (print_hex(va_arg(argp, int), 1));
		return (print_multihex(va_arg(argp, void *), 1));
	else if (c == '%')
		return (print_char('%'));
	else
		return (0);
}

int ft_printf(const char *str, ...)
{
	int i; // int型がよくない
	va_list argp;
	int print_len; // int型がよくない

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

// int main(void)
// {
// 	// 	// printf("printf: %d\n", "Hello", 1, 1.025); //error
// 	// 	// printf("printf:\n	%s\n	%i\n	%f\n", "Hello", 1, 1.025); //success

// 	// // [u]
// 	// printf("	return: %d\n", printf("(std)print: %u ", INT_MAX));
// 	// ft_printf("	return: %d\n\n", ft_printf("(ft_)print: %u ", INT_MAX));

// 	// [p] 0のとき本家は型エラー
// 	// printf("	return: %d\n", printf("(std)print: %p ", (void *)100));
// 	// ft_printf("	return: %d\n\n", ft_printf("(ft_)print: %p ", (void *)100));
// 	// printf("	return: %d\n", printf("(std)print: %p %p ", 0, 0));
// 	// ft_printf("	return: %d\n\n", ft_printf("(ft_)print: %p %p ", 0, 0));
// 	// printf("	return: %d\n", printf("(std)print: %p ", (void *)0));
// 	// ft_printf("	return: %d\n\n", ft_printf("(ft_)print: %p ", (void *)0));

// 	// [s] NULLのとき本家は型エラー
// 	printf("	return: %d\n", printf("(std)print: %s NULL ", (char *)NULL));
// 	ft_printf("	return: %d\n\n", ft_printf("(ft_)print: %s NULL ", (char *)NULL));

// 	// printf("	return: %d\n", printf("(std)print: %x ", 18446744073709551516));
// 	// ft_printf("	return: %d\n\n", ft_printf("(ft_)print: %x ", 18446744073709551516));
// 	// printf("	return: %d\n", printf("(std)print:  %d ", INT_MAX));
// 	// ft_printf("	return: %d\n\n", ft_printf("(ft_)print:  %d ", INT_MAX));
// 	// printf("	return: %d\n", printf("(std)print: %d ", INT_MIN));
// 	// ft_printf("	return: %d\n\n", ft_printf("(ft_)print: %d ", INT_MIN));
// 	// printf("	return: %d\n", printf("(std)print: %d ", LONG_MIN));
// 	// ft_printf("	return: %d\n\n", ft_printf("(ft_)print: %d ", LONG_MIN));
// }

// int func(int count, ...)
// {
// 	va_list ap;

// 	va_start(ap, count);

// 	printf("%d\n", va_arg(ap, int));
// 	printf("%s\n", va_arg(ap, char*));

// 	return (0);
// }

// int main(void)
// {
// 	func(2, 1, "A"); //success
// 	// func(2, "A", 1); //error

// }
