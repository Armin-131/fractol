/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <abenaven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:01:52 by abenaven          #+#    #+#             */
/*   Updated: 2025/04/26 19:52:31 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trymlx.h"
#include <stdio.h>

void	pixelput(t_data *data, int x, int y, int colour);
void	squa(t_data *img, int y, int x, int colour);
int		main(void)
{
	void *mlx;
	void *win;
	int x;
	int y;
	t_data  img;
	
	y = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "Hi");
	img.img =  mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.linelength, &img.endian
	);
	while (y < 1000)
	{
		x = 0;
		while (x < 1000)
		{
			if ((x + y) % 3 == 1)
			squa(&img, x, y, 0x00FF0000);
		else if ((x + y) % 3 == 2)
			squa(&img, x, y, 0x0000FF00);
		else
			squa(&img, x, y, 0x000000FF);
		x += 100;
		}
		
		
		y = y + 100;
	}
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	//printf("holi esto es x -> %i y esto es y -> %i\n",img.img);
	mlx_loop(mlx);
}

void	pixelput(t_data *data, int x, int y, int colour)
{
	char *dst;
	
	dst = data->addr + (y * data->linelength + x * (data->bpp / 8));
	*(unsigned int*)dst = colour;
}
void	squa(t_data *img, int y, int x, int colour)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < 100)
	{
		j = 0;
		while (j < 100)
		{
			pixelput(img, x + i, y + j, colour);
			j++;
		}
		i++;
	}
}
	