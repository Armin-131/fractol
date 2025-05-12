/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <abenaven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:29:58 by abenaven          #+#    #+#             */
/*   Updated: 2025/05/12 21:11:07 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


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
	fractal->img.addr = mlx_get_data_addr(fractal->img.img_ptr, &fractal->img.bpp, &fractal->img.linelength, fractal->img.endian); 
}

