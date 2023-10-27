/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaramire <yaramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:12:31 by polmarti          #+#    #+#             */
/*   Updated: 2023/10/27 19:37:28 by yaramire         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/ft_printf.h"

static int	char_position(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}

	return (-1);
}

int	ft_printf(const char *p, ...)
{
	va_list	ap;
	int		cntchr;
	int		(**operaciones)(va_list, int *);

	operaciones = (int (**)(va_list, int *))set_functions();
	if (operaciones == NULL)
		return (-1);
	cntchr = 0;
	va_start(ap, p);
	while (*p && cntchr != -1)
	{
		if (*p == '%')
		{
			if (*++p == '%')
				ft_putchar('%', &cntchr);
			else
				operaciones[char_position("cspdiuxX", *p)](ap, &cntchr);
		}
		else
			ft_putchar(*p, &cntchr);
		p++;
	}
	va_end(ap);
	free(operaciones);
	return (cntchr);
}
