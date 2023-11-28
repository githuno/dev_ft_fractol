#include "libft.h"

int print_ptr_helper(uintptr_t value, int asc, int print_len, char *hex)
{
	if (value >= 16)
	{
		print_len = print_ptr_helper(value / 16, asc, print_len, hex);
		print_len = print_ptr_helper(value % 16, asc, print_len, hex);
	}
	else
		print_len += print_char(hex[value]);
	return (print_len);
}
int print_multihex_helper(unsigned int value, int asc, int print_len, char *hex)
{
	if (value >= 16)
	{
		print_len = print_multihex_helper(value / 16, asc, print_len, hex);
		print_len = print_multihex_helper(value % 16, asc, print_len, hex);
	}
	else
		print_len += print_char(hex[value]);
	return (print_len);
}

int print_multihex(void *value, int asc)
{
	char *hex;
	int print_len;
	if (asc <= 0)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	print_len = 0;
	if (asc == -1)
	{
		print_len += print_str("0x");
		return (print_ptr_helper((uintptr_t)value, asc, print_len, hex));
	}
	return (print_multihex_helper((unsigned int)(uintptr_t)value, asc, print_len, hex));
}
