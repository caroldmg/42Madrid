/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:24:45 by cde-migu          #+#    #+#             */
/*   Updated: 2024/03/28 12:12:19 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	//it should return the number of chars it read
	va_list	args;
	int		result;
	int		i;
	
	va_start( args, str);
	/* va_start must be called before any use of va_arg - the second parameter marks the start of the list*/
	result = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
			result += ft_get_value(str[++i]);
		else
			result += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (result);
}

int	print_format(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i - 1] == '%')
			ft_check_value(str[i]);
		ft_putchar(str[i], 1);
	}
	return (i);
}

int ft_check_value(va_list args, char c)
{
	int result;

	result = 0;
	if (c == 'd' || c == 'i')
		result = ft_putnbr_fd(va_arg(args, int), 1);
	/* Each time va_arg is called, you move to the next argument. */
	else if (c == 's')
		result = ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
	{
		result += ft_putstr_fd("0x")
		
	}
}