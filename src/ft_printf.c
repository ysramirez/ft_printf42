/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaramire <yaramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:12:31 by polmarti          #+#    #+#             */
/*   Updated: 2023/10/22 06:04:16 by yaramire         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/ft_printf.h"

int	ft_select_format(char type, va_list apoint, int *cntchr)
{
	if (type == '%')
		ft_putchar('%', cntchr);
	if (type == 'c')
		ft_putchar(va_arg(apoint, int), cntchr);
	if (type == 's')
		ft_putstr(va_arg(apoint, char *), cntchr);
	if (type == 'p')
	{
		ft_putstr("0x", cntchr);
		ft_nbase((t_ul)va_arg(apoint, void *), 16, cntchr, "0123456789abcdef");
	}
	if (type == 'd' || type == 'i')
		ft_putnbr(va_arg(apoint, int), cntchr);
	if (type == 'u')
		ft_nbase(va_arg(apoint, unsigned int), 10, cntchr, "0123456789");
	if (type == 'x')
		ft_nbase(va_arg(apoint, unsigned int), 16, cntchr, "0123456789abcdef");
	if (type == 'X')
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
