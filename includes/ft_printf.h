/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaramire <yaramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:41:35 by polmarti          #+#    #+#             */
/*   Updated: 2023/10/27 18:46:25 by yaramire         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef unsigned long	t_ul;

int		ft_write(int c);

void	**set_functions(void);

int		ft_putchar_list(va_list apoint, int *cntchr);
int		ft_putstr_list(va_list apoint, int *cntchr);
int		ft_putpointer_list(va_list apoint, int *cntchr);
int		ft_putnbr_list(va_list apoint, int *cntchr);
int		ft_putinteger_list(va_list apoint, int *cntchr);
int		ft_putexa_list(va_list apoint, int *cntchr);
int		ft_putexa_caps_list(va_list apoint, int *cntchr);

int		ft_putchar(int c, int *cntchr);
void	ft_putstr(char *str, int *cntchr);
void	ft_nbase(t_ul nb, unsigned int base, int *cntchr, char *basechr);
void	ft_putnbr(int nb, int *cntchr);
int		ft_select_format(char type, va_list apoint, int *cntchr);
int		ft_printf(const char *p, ...);

#endif
