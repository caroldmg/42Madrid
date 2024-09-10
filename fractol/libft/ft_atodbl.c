/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:42:04 by cde-migu          #+#    #+#             */
/*   Updated: 2024/09/10 16:13:16 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_atodbl(char *s)
{
	long	int_part;
	double	fractional;
	double	pow;
	int		sign;
	double	res;

	int_part = 0;
	fractional = 0;
	sign = 1;
	pow = 0.1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s++ == '-')
			sign *= -1;
	}
	while (*s != '.' && *s && (*s >= '0' && *s <= '9'))
		int_part = (int_part * 10) + (*s++ - '0');
	if (*s == '.')
		s++;
	while (*s && (*s >= '0' && *s <= '9'))
	{
		fractional += (*s++ - '0') * pow;
		pow /= 10;
	}
	res = (double)(int_part + fractional) * sign;
	return (res);
}

// #include <stdio.h>
// int main (void)
// {
// 	char *str = "--2";
	
// 	printf("res atodbl --> %f \n", ft_atodbl(str));
// }