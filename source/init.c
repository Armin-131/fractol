/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <abenaven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:29:58 by abenaven          #+#    #+#             */
/*   Updated: 2025/05/14 23:33:03 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	initdata(t_data *fractal)
{
	fractal->outoflimits = 4;
	fractal->idef = 100;
	fractal->x = 0.0;
	fractal->y = 0.0;
	fractal->zoom = 1.0;
	fractal->colourchange = 0;
}
static void		initevents(t_data *fractal)
{
	mlx_hook(fractal->window, KeyPress, KeyPressMask, handlekeys, fractal);
	mlx_hook(fractal->window, ButtonPress, ButtonPressMask, handlemouse, fractal);
	mlx_hook(fractal->window, DestroyNotify, StructureNotifyMask, closeall, fractal);
	mlx_hook(fractal->window, MotionNotify, PointerMotionMask, trackjulia, fractal);
}

void	initx(t_data *fractal)
{
	fractal->mlx = mlx_init();
	if(!fractal->mlx)
		mlxerror(fractal->mlx);
	fractal->window = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractal->name);
	if (!fractal->window)
		windowerror(fractal);
	fractal->img.img_ptr = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if(!fractal->img.img_ptr)
		imgerror(fractal);
	fractal->img.addr = mlx_get_data_addr(&fractal->img.img_ptr, &fractal->img.bpp, &fractal->img.linelength, &fractal->img.endian);
	initevents(fractal);
	initdata(fractal);
}