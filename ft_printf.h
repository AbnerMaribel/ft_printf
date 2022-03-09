/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:18:27 by amaribel          #+#    #+#             */
/*   Updated: 2021/11/01 16:42:02 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

void	ft_putnbr(int	n, int	*counter);
void	ft_putchar(char	c, int	*counter);
void	ft_putstr(char	*s, int	*counter);
void	ft_put_unbr(unsigned int	u, int	*counter);
int		ft_printf(const char	*s, ...);
void	put_hex_lower(unsigned int	c, int	*counter);
void	put_hex_upper(unsigned int	c, int	*counter);
void	put_pointer(unsigned long long int	p, int	*counter);
void	conversion(char *s, va_list ap, int *counter);

#endif