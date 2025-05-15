/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <abenaven@42.student.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:21:49 by abenaven          #+#    #+#             */
/*   Updated: 2025/05/15 17:43:57 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		handlekeys(int symbol, t_data *fractal)
{
	if (symbol == XK_Escape)
		closeall(fractal);
	if (symbol == XK_Left)
		fractal->x = fractal->x + (0.5 * fractal->zoom);
	else if (symbol == XK_Right)
		fractal->x = fractal->x - (0.5 * fractal->zoom);
	else if (symbol == XK_Up)
		fractal->y = fractal->y + (0.5 * fractal->zoom);
	else if (symbol == XK_Down)
		fractal->y = fractal->y - (0.5 * fractal->zoom);
	else if (symbol ==  XK_plus)
		fractal->idef = fractal->idef + 10;
	else if (symbol == XK_minus)
		fractal->idef = fractal->idef - 10;
	render(fractal);
	return(0);
}

int	handlemouse(int button, int x, int y, t_data *fractal)
{
	(void)x;
	(void)y;
	if (button == Button5)
		fractal->zoom = fractal->zoom * 1.1;
	else if (button == Button4)
		fractal->zoom = fractal->zoom * 0.9;
	render(fractal);
	return (0);
}

int	mousetrackjulia(int x, int y, t_data *fractal)
{
	if (ft_strncmp(fractal->name, "julia", 5) == 0)
	{
		fractal->julia_x = (scaling(x, -2, 2, WIDTH) * fractal->zoom) + fractal->x;
		fractal->julia_y = (scaling(y, 2, -2, HEIGHT) * fractal->zoom) + fractal->y;
	}
	render(fractal);
	return (0);
}