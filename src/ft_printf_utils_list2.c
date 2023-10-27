#include "../includes/ft_printf.h"

int	ft_putinteger_list(va_list apoint, int *cntchr)
{
	ft_nbase(va_arg(apoint, unsigned int), 10, cntchr, "0123456789");
	return (*cntchr);
}

int	ft_putexa_list(va_list apoint, int *cntchr)
{
	ft_nbase(va_arg(apoint, unsigned int), 16, cntchr, "0123456789abcdef");
	return (*cntchr);
}

int	ft_putexa_caps_list(va_list apoint, int *cntchr)
{
	ft_nbase(va_arg(apoint, unsigned int), 16, cntchr, "0123456789ABCDEF");
	return (*cntchr);
}
