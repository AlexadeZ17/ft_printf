/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrodri2 <alrodri2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:44:34 by alrodri2          #+#    #+#             */
/*   Updated: 2022/10/28 16:32:07 by alrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(va_list args, const char param, int i)
{
	if (param == 'c')
		i = ft_putchar(va_arg(args, int), i);
	else if (param == '%')
		i = ft_putchar('%', i);
	else if (param == 's')
		i = ft_putstr(va_arg(args, char *), i);
	else if (param == 'd' || param == 'i')
		i = ft_putnum(va_arg(args, int),
				"0123456789", i, 10);
	else if (param == 'x')
		i = ft_ptn_uns(va_arg(args, unsigned int),
				"0123456789abcdef", i, 16);
	else if (param == 'X')
		i = ft_ptn_uns(va_arg(args, unsigned int),
				"0123456789ABCDEF", i, 16);
	else if (param == 'u')
		i = ft_ptn_uns(va_arg(args, unsigned int),
				"0123456789", i, 10);
	else if (param == 'p')
		i = ft_putptr(va_arg(args, void *), i);
	return (i);
}

int	ft_formatcheck(int i, va_list args, char const *params)
{
	int	c;

	c = 0;
	while (params[c])
	{
		if (params[c] == '%')
		{
			++c;
			i = ft_type(args, params[c], i);
			if (i < 0)
				return (-1);
		}
		else
		{
			i = ft_putchar(params[c], i);
			if (i < 0)
				return (-1);
		}
		++c;
	}
	return (i);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		i;

	va_start(args, s);
	i = 0;
	i = ft_formatcheck(i, args, s);
	va_end(args);
	return (i);
}

/*
int	main()
{

	if (ft_printf("%d%c%s", -10, 'c', "hola") == printf("%d%c%s", -10, 'c', "hola"))
		printf("SUCCESS");
	return (0);

}*/
