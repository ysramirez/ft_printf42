/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaramire <yaramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:12:31 by polmarti          #+#    #+#             */
/*   Updated: 2023/10/27 17:54:45 by yaramire         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/ft_printf.h"

int	ft_select_format(char type, va_list apoint, int *cntchr)
{
	int	(**operaciones)(va_list, int *);

	operaciones = (int (**)(va_list, int *))set_functions();
	if (operaciones == NULL)
		return (*cntchr = -1);
	if (type == 'c')
		operaciones[0](apoint, cntchr);
	if (type == 's')
		operaciones[1](apoint, cntchr);
	if (type == 'p')
		operaciones[2](apoint, cntchr);
	if (type == 'd')
		operaciones[3](apoint, cntchr);
	if (type == 'i')
		operaciones[4](apoint, cntchr);
	if (type == 'u')
		operaciones[5](apoint, cntchr);
	if (type == 'x')
		operaciones[6](apoint, cntchr);
	if (type == 'X')
		operaciones[7](apoint, cntchr);
	free(operaciones);
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
			if (*p == '%')
				ft_putchar('%', &cntchr);
			else
				ft_select_format(*p, ap, &cntchr);
		}
		else
			ft_putchar(*p, &cntchr);
		p++;
	}
	va_end(ap);
	return (cntchr);
}
