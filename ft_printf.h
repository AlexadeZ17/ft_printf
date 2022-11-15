/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrodri2 <alrodri2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:14:08 by alrodri2          #+#    #+#             */
/*   Updated: 2022/10/28 16:33:59 by alrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(char const *s, ...);
int	ft_type(va_list args, const char param, int i);
int	ft_fomratcheck(int i, va_list args, char const *params);
int	ft_putchar(int c, int i);
int	ft_putstr(const char *str, int i);
int	ft_putnum(int num, char *base, int i, int baselen);
int	ft_ptn_uns(unsigned int num, char *base, int i, unsigned int baselen);
int	ft_putptr(void *ptr, int i);
int	ft_pn_us_lg(unsigned long int num, char *base, int i, unsigned int baselen);
#endif
