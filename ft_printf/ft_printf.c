/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:24:45 by cde-migu          #+#    #+#             */
/*   Updated: 2024/04/23 20:22:22 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_value(va_list args, char c)
{
	int	result;

	result = 0;
	if (c == 'c')
		result = ft_putchar(va_arg(args, int));
	else if (c == 'd' || c == 'i')
		result = ft_putnbr(va_arg(args, int));
	else if (c == 's')
		result = ft_putstr(va_arg(args, char *));
	else if (c == 'u')
		result = ft_putnbrbase(va_arg(args, unsigned int), "0123456789", 10);
	else if (c == 'x')
		result = ft_putnbrbase(va_arg(args, unsigned int),
				"0123456789abcdef", 16);
	else if (c == 'X')
		result = ft_putnbrbase(va_arg(args, unsigned int),
				"0123456789ABCDEF", 16);
	else if (c == '%')
		result = ft_putchar('%');
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
		else if (str[i] == '%' && str[i + 1] == '\0')
			return (result);
		else
			result += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (result);
}

/* int main(void)
{
	int res1 = ft_printf("1 --> %");
	int res2 = printf("2 --> %");
	
	ft_printf("res1 = %i \n res2 = %i \n", res1, res2);
	return (0);	
} */
