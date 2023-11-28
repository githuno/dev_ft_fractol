#include "libft.h"

int print_str(char *str)
{
	size_t len;
	if (!str)
		return print_str("(null)");
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}
