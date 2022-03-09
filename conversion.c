/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:04:20 by amaribel          #+#    #+#             */
/*   Updated: 2021/11/01 16:51:59 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion(char *s, va_list ap, int *counter)
{
	if (*s == 'd' || *s == 'i')
		ft_putnbr((va_arg(ap, int)), counter);
	else if (*s == 'c')
		ft_putchar((va_arg(ap, int)), counter);
	else if (*s == 's')
		ft_putstr((va_arg(ap, char *)), counter);
	else if (*s == 'x')
		put_hex_lower((va_arg(ap, unsigned int)), counter);
	else if (*s == 'X')
		put_hex_upper((va_arg(ap, unsigned int)), counter);
	else if (*s == 'u')
		ft_put_unbr((va_arg(ap, unsigned int)), counter);
	else if (*s == 'p')
	{
		write(1, "0x", 2);
		(*counter) += 2;
		put_pointer((va_arg(ap, unsigned long long int)), counter);
	}
	else if (*s == '%')
	{
		write(1, s, 1);
		(*counter)++;
	}
}
