/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:24:45 by cde-migu          #+#    #+#             */
/*   Updated: 2024/04/04 12:14:58 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr(unsigned long ptr)
{
	int	result;

	result = 0;
	result += ft_putstr_fd("0x", 1);
	result += ft_putnbrbase_fd(ptr, "0123456789abcdef", 1);
	return (result);
}

static int	ft_check_value(va_list args, char c)
{
	int	result;

	result = 0;
	if (c == 'c')
		result = ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 'd' || c == 'i')
		result = ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 's')
		result = ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'u')
		result = ft_putnbrbase_fd(va_arg(args, unsigned int), "0123456789", 1);
	else if (c == 'x')
		result = ft_putnbrbase_fd(va_arg(args, unsigned int),
				"0123456789abcdef", 1);
	else if (c == 'X')
		result = ft_putnbrbase_fd(va_arg(args, unsigned int),
				"0123456789ABCDEF", 1);
	else if (c == '%')
		result = ft_putchar_fd('%', 1);
	else if (c == 'p')
		result = ft_putptr(va_arg(args, unsigned long));
	return (result);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		result;
	int		i;

	va_start(args, str);
	result = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
			result += ft_check_value(args, str[++i]);
		else
			result += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (result);
}

/* int main(void)
{
	int res1 = ft_printf("1 --> ");
	int res2 = printf("2 --> ");
	
	ft_printf("res1 = %i \n res2 = %i \n", res1, res2);
	return (0);	
} */