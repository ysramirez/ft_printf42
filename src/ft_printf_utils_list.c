#include "../includes/ft_printf.h"

void	**set_functions(void)
{
	int	(**operaciones)(va_list, int *);

	operaciones = (int (**)(va_list, int *)) \
	malloc(10 * sizeof(int (*)(va_list, int *)));
	if (operaciones == NULL)
		return (NULL);
	operaciones[0] = ft_putchar_list;
	operaciones[1] = ft_putstr_list;
	operaciones[2] = ft_putpointer_list;
	operaciones[3] = ft_putnbr_list;
	operaciones[4] = ft_putnbr_list;
	operaciones[5] = ft_putinteger_list;
	operaciones[6] = ft_putexa_list;
	operaciones[7] = ft_putexa_caps_list;

	return ((void **)operaciones);
}



int	ft_putchar_list(va_list apoint, int *cntchr)
{
	ft_putchar(va_arg(apoint, int), cntchr);
	return (*cntchr);
}

int	ft_putstr_list(va_list apoint, int *cntchr)
{
	ft_putstr(va_arg(apoint, char *), cntchr);
	return (*cntchr);
}

int	ft_putpointer_list(va_list apoint, int *cntchr)
{
	ft_putstr("0x", cntchr);
	ft_nbase((t_ul)va_arg(apoint, void *), 16, cntchr, "0123456789abcdef");
	return (*cntchr);
}

int	ft_putnbr_list(va_list apoint, int *cntchr)
{
	ft_putnbr(va_arg(apoint, int), cntchr);
	return (*cntchr);
}
