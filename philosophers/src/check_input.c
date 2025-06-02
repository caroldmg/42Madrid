/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:58:00 by cde-migu          #+#    #+#             */
/*   Updated: 2025/06/02 20:05:36 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_valid_nums(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (1); //cambiar a codigo de error
	// funcion para chequear que lo que me pasan son numeros y que no tienen letras ni cosas raras
	// solo aceeptar numeros positivos
	// ¿debo tener un máximo? ¿size_t o long?
	

	// chequear que todos estos numeros sean mayores a 0
	// argv[1] > 200 return error;

	// una vez que esté todo ok, asignar los valores a los elementos de la estructura
}