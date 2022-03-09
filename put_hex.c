/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:34:13 by amaribel          #+#    #+#             */
/*   Updated: 2021/11/01 16:52:01 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_hex_lower(unsigned int	c, int	*counter)
{
	if (c <= 9)
	{
		c = c + 48;
		write(1, &c, 1);
		(*counter)++;
	}
	else if (c > 9 && c <= 15)
	{
		c = c + 87;
		write(1, &c, 1);
		(*counter)++;
	}
	else
	{
		put_hex_lower((c / 16), counter);
		put_hex_lower((c % 16), counter);
	}
}

void	put_hex_upper(unsigned int	c, int	*counter)
{	
	if (c <= 9)
	{
		c = c + 48;
		write(1, &c, 1);
		(*counter)++;
	}
	else if (c > 9 && c <= 15)
	{
		c = c + 55;
		write(1, &c, 1);
		(*counter)++;
	}
	else
	{
		put_hex_upper((c / 16), counter);
		put_hex_upper((c % 16), counter);
	}
}

void	put_pointer(unsigned long long int	p, int	*counter)
{
	if (p <= 9)
	{
		p = p + 48;
		write(1, &p, 1);
		(*counter)++;
	}
	else if (p > 9 && p <= 15)
	{
		p = p + 87;
		write(1, &p, 1);
		(*counter)++;
	}
	else
	{
		put_pointer((p / 16), counter);
		put_pointer((p % 16), counter);
	}
}
