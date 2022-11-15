/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrodri2 <alrodri2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:59:16 by alrodri2          #+#    #+#             */
/*   Updated: 2022/10/28 16:30:57 by alrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c, int i)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	++i;
	return (i);
}

int	ft_putstr(const char *str, int i)
{
	int	c;

	c = 0;
	if (!str)
		str = "(null)";
	while (str[c])
	{
		i = ft_putchar(str[c], i);
		if (i < 0)
			return (-1);
		++c;
	}
	return (i);
}
