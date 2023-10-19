/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmarti <polmarti@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:12:31 by polmarti          #+#    #+#             */
/*   Updated: 2023/10/14 19:12:32 by polmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_select_format(char type, va_list apoint, int *cntchr)
{
	if (type == '%')
		ft_putchar('%', cntchr);
	else if (type == 'c')
		ft_putchar(va_arg(apoint, int), cntchr);
	else if (type == 's')
		ft_putstr(va_arg(apoint, char *), cntchr);
	else if (type == 'p')
	{
		ft_putstr("0x", cntchr);
		if (*cntchr == -1)
			return (*cntchr);
		ft_nbase((t_ul)va_arg(apoint, void *), 16, cntchr, "0123456789abcdef");
	}
	else if (type == 'd' || type == 'i')
		ft_putnbr(va_arg(apoint, int), cntchr);
	else if (type == 'u')
		ft_nbase(va_arg(apoint, unsigned int), 10, cntchr, "0123456789");
	else if (type == 'x')
		ft_nbase(va_arg(apoint, unsigned int), 16, cntchr, "0123456789abcdef");
	else if (type == 'X')
		ft_nbase(va_arg(apoint, unsigned int), 16, cntchr, "0123456789ABCDEF");
	return (*cntchr);
}

int	ft_printf(const char *p, ...)
{
	va_list	ap;
	int		cntchr;

	cntchr = 0;
	va_start(ap, p);
	while (*p && cntchr != -1)
	{
		if (*p == '%')
		{
			p++;
			ft_select_format(*p, ap, &cntchr);
		}
		else
			ft_putchar(*p, &cntchr);
		p++;
	}
	va_end(ap);
	return (cntchr);
}
