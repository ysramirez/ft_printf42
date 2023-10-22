/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaramire <yaramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:41:35 by polmarti          #+#    #+#             */
/*   Updated: 2023/10/22 06:15:45 by yaramire         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

typedef unsigned long	t_ul;

void	ft_putchar(int c, int *cntchr);

void	ft_putstr(char *str, int *cntchr);

void	ft_nbase(t_ul nb, unsigned int base, int *cntchr, char *basechr);

void	ft_putnbr(int nb, int *cntchr);

int		ft_select_format(char type, va_list apoint, int *cntchr);

int		ft_printf(const char *p, ...);

#endif
