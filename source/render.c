/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <abenaven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:29:41 by abenaven          #+#    #+#             */
/*   Updated: 2025/05/14 23:36:54 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixelput(int x, int y, t_image *img, int colour)
{
	int offset;

	offset = (y * img->linelength) + (x * (img->bpp /  8));
	*(unsigned int *)(img->addr + offset) = colour;
}
void	pixelhandle(int x, int y, t_data *fractal)
{
	t_complex	c;
	t_complex 	z;
	int		i;
	int		colour;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = mapping(x, -2, 2, 0, WIDTH);
	c.y = mapping(y, 2, -2, 0, HEIGHT);
	
	while(i < fractal->idef)
	{
		z = sumcomplex(sqrtcomplex(z), c);
		if((z.x * z.x) + (z.y * z.y) > fractal->outoflimits)
		{
			colour = mapping(i,BABYPINK, WHITE, 0, fractal->idef);
			mlx_pixel_put(fractal->mlx, fractal->window, x, y, colour);
			//pixelput(x, y, &fractal->img, colour);
			return;
		}
		i++;
	}
	//pixelput(x, y, &fractal->img, BPURPLE);
	mlx_pixel_put(fractal->mlx, fractal->window, x, y, BPURPLE);
}

void	pixelhandle2(int x, int y, t_data *fractal)
{
	t_complex	c;
	t_complex 	z;
	int		i;
	int		colour;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = mapping(x, -2, 2, 0, WIDTH);
	c.y = mapping(y, 2, -2, 0, HEIGHT);
	
	while(i < fractal->idef)
	{
		z = sumcomplex(sqrtcomplex(z), c);
		if((z.x * z.x) + (z.y * z.y) > fractal->outoflimits)
		{
			colour = mapping(i,WHITE, BABYPINK, 0, fractal->idef);
			mlx_pixel_put(fractal->mlx, fractal->window, x, y, colour);
			//pixelput(x, y, &fractal->img, colour);
			return;
		}
		i++;
	}
	mlx_pixel_put(fractal->mlx, fractal->window, x, y, BPURPLE);
	//pixelput(x, y, &fractal->img, BPURPLE);
}

void		mandlorjulia(t_complex *z, t_complex *c, t_data *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 6))
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
			if(fractal->colourchange == 1)
				pixelhandle(x, y, fractal);
			else
				pixelhandle2(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->img.img_ptr, 0, 0);	
}