#include "libft.h"

int print_int(int n)
{
    unsigned int	abs_nb;
    size_t			len;

    ft_putnbr_fd(n, 1);
    len = 1;
    if (n < 0)
    {
        len++;
        abs_nb = -n;
    }
	else
		abs_nb = n;
    while (abs_nb > 9)
    {
        abs_nb = abs_nb / 10;
        len++;
    }
    return (len);
}
