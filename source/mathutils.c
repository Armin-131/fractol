/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <abenaven@42.student.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:56:32 by abenaven          #+#    #+#             */
/*   Updated: 2025/05/15 15:53:47 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		scaling(double un, double nmin, double nmax, double omax)
{
	return (nmax - nmin) * (un) / (omax) + nmin;
}

t_complex	sumcomplex(t_complex z1, t_complex z2)
{
	t_complex result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	sqrtcomplex(t_complex z)
{
	t_complex result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}
