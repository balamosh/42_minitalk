#include "libft.h"

int	ft_print_error(int code, const char *str)
{
	ft_putstr_fd(str, 2);
	return (code);
}
