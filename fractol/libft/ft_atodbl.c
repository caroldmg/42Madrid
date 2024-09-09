/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:42:04 by cde-migu          #+#    #+#             */
/*   Updated: 2024/09/09 17:50:47 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	atodbl(char *s)
{
	long	int_part;
	double	fractional;
	double	pow;
	int		sign;

	int_part = 0;
	fractional = 0;
	sign = 0;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	while (*s == '+' || *s == '-')
	{
		if (*s++ == '-')
			sign *= -1;
	}
	while (*s != '.' && *s)
		int_part = (int_part * 10) + (*s++ - '0');
	if (*s == '.')
		s++;
	while (*s)
	{
		pow /= 10;
		fractional = fractional + (*s++ - '0') * pow;
	}
	return ((int_part + fractional) * sign);
}
