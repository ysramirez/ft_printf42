/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaramire <yaramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:13:57 by polmarti          #+#    #+#             */
/*   Updated: 2023/10/22 08:21:41 by yaramire         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/ft_printf.h"


int	ft_write(int c)
{
	return (write(1, &c, 1));
}

int	ft_putchar(int c, int *cntchr)
{
	int	check;

	check = ft_write(c);
	if (check != -1)
		return ((*cntchr)++);
	else
		return (*cntchr = -1);
}

void	ft_putstr(char *str, int *cntchr)
{
	if (!str)
	{
		ft_putstr("(null)", cntchr);
		return ;
	}
	while (*str)
	{
		ft_putchar(*str, cntchr);
		if (*cntchr == -1)
			return ;
		str++;
	}
}

void	ft_nbase(unsigned long nb, unsigned int base, int *cntchr, char *b)
{
	if (*cntchr == -1)
		return ;
	if (nb < base)
	{
		ft_putchar(b[nb], cntchr);
		if (*cntchr == -1)
			return ;
	}
	else
	{
		ft_nbase(nb / base, base, cntchr, b);
		ft_nbase(nb % base, base, cntchr, b);
	}
}

void	ft_putnbr(int nb, int *cntchr)
{
	if (*cntchr == -1)
		return ;
	if (nb == -2147483648)
		ft_putstr("-2147483648", cntchr);
	else if (nb < 0)
	{
		ft_putchar('-', cntchr);
		if (*cntchr == -1)
			return ;
		ft_putnbr(-nb, cntchr);
	}
	else if (nb < 10)
	{
		ft_putchar(nb + '0', cntchr);
		if (*cntchr == -1)
			return ;
	}
	else
	{
		ft_putnbr(nb / 10, cntchr);
		ft_putnbr(nb % 10, cntchr);
	}
}
