/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <abenaven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 21:55:47 by abenaven          #+#    #+#             */
/*   Updated: 2025/05/14 22:57:57 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atodbl(char *str)
{
	long	entero;
	double  decimales;
	double pow;
	int		sign;

	entero = 0;
	decimales = 0;
	sign = 1;
	pow = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32 )
		++str;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -sign;
	while (*str != '.' && *str)
		entero = (entero * 10) + (*str++ - '0');
	if (*str == '.')
		++str;
	while (*str)
	{
		pow = pow / 10;
		decimales = decimales + (*str++ - '0') * pow;
	}
	return ((entero + decimales) * sign);
}