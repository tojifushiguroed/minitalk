/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egolboyu <egolboyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:07:32 by egolboyu          #+#    #+#             */
/*   Updated: 2024/03/02 17:31:57 by egolboyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include "minitalk.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!(str))
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	while (str[i])
	{
		count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	long	num;
	int		count;

	count = 0;
	num = n;
	if (num < 0)
	{
		count += ft_putchar('-');
		num *= -1;
	}
	if (num < 10)
		count += ft_putchar(num + '0');
	else
	{
		count += ft_putnbr(num / 10);
		count += ft_putnbr(num % 10);
	}
	return (count);
}

int	type(char c, va_list list)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(list, int));
	else if (c == 's')
		len += ft_putstr(va_arg(list, char *));
	else if (c == 'd')
		len += ft_putnbr(va_arg(list, int));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			type(str[i + 1], list);
			i += 2;
		}
		else
		{
			len += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(list);
	return (len);
}
