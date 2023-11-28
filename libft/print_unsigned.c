#include "libft.h"

unsigned int print_unsigned_helper(unsigned int nb, size_t len)
{
	if (nb > 9)
		len += print_unsigned_helper(nb / 10, len);
	len += print_char((nb % 10) + '0');
	return len;
}

int print_unsigned(unsigned int nb)
{
	size_t len;
	len = 0;
	return print_unsigned_helper(nb, len);
}
