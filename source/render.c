/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <abenaven@42.student.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:29:41 by abenaven          #+#    #+#             */
/*   Updated: 2025/05/15 17:43:23 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	pixelput(int x, int y, t_image *img, int colour)
{
	int offset;

	offset = (y * img->linelength) + (x * (img->bpp /  8));
	*(unsigned int *)(img->addr + offset) = colour;
}

static void		mandlorjulia(t_complex *z, t_complex *c, t_data *fractal)
{
	if (ft_strncmp(fractal->name, "julia", 5) == 0)
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_x;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	pixelhandle(int x, int y, t_data *fractal)
{
	t_complex	z;
	t_complex 	c;
	int		i;
	int		colour;

	i = 0;
	//pixel coordinates
	z.x = (scaling(x, -2, +2, WIDTH) * fractal->zoom) + fractal->x;
	z.y = (scaling(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->y;
	mandlorjulia(&z, &c, fractal);
	while(i < fractal->idef)
	{
		z = sumcomplex(sqrtcomplex(z), c);
		if((z.x * z.x) + (z.y * z.y) > fractal->outoflimits)
		{
			colour = scaling(i, BABYPINK, WHITE, fractal->idef);
			pixelput(x, y, &fractal->img, colour);
			return;
		}
		++i;
	}
	pixelput(x, y, &fractal->img, BPURPLE);
}

void	render(t_data *fractal)
{
	int x;
	int y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pixelhandle(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->img.img_ptr, 0, 0);	
}