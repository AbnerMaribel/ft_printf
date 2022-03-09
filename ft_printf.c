/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:49:45 by amaribel          #+#    #+#             */
/*   Updated: 2021/11/08 13:53:20 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int	n, int	*counter)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*counter) += 11;
	}
	else
	{
		if (n < 0)
		{
			n = (-1) * n;
			write(1, "-", 1);
			(*counter)++;
		}
		if (n <= 9)
		{
			n = n + '0';
			write(1, &n, 1);
			(*counter)++;
		}
		else
		{
			ft_putnbr((n / 10), counter);
			ft_putnbr((n % 10), counter);
		}
	}
}

void	ft_putchar(char	c, int	*counter)
{
	write(1, &c, 1);
	(*counter)++;
}

void	ft_putstr(char	*s, int	*counter)
{
	if (!s)
	{
		write(1, "(null)", 6);
		(*counter) += 6;
		return ;
	}
	while (*s)
	{
		write(1, s++, 1);
		(*counter)++;
	}
}

void	ft_put_unbr(unsigned int	u, int	*counter)
{
	if (u <= 9)
	{
		u = u + '0';
		write(1, &u, 1);
		(*counter)++;
	}
	else
	{
		ft_put_unbr((u / 10), counter);
		ft_put_unbr((u % 10), counter);
	}
}

int	ft_printf(const char	*s, ...)
{
	int		counter;
	va_list	ap;

	va_start(ap, s);
	counter = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s && *s != '%')
		{
			write(1, s, 1);
			counter++;
		}
		if (*s == '%')
		{
			s++;
			conversion((char *)s, ap, &counter);
		}
		s++;
	}
	va_end(ap);
	return (counter);
}
