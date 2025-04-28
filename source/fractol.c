/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <abenaven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:13:19 by abenaven          #+#    #+#             */
/*   Updated: 2025/04/28 01:15:51 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

void	checkinput(int	argc, char **argv, t_data fractal)
{
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
	{
		fractal.name = argv[1];
		printf("hola\n");	
	}		
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 6))
	{
		fractal.name = argv[1];
		printf("hola\n");
	}
	else 
		exit(1);
		
}

int		main(int argc, char **argv)
{
	t_data	fractal;
	
	checkinput(argc, argv, fractal);
	fractal.mlx = mlx_init();
	if(!fractal.mlx)
		exit(1);
	fractal.window = mlx_new_window(fractal.mlx, WIDTH, HEIGHT, fractal.name);
	if (!fractal.window)//TODO FREE
		mlx_destroy_display(fractal.mlx);
	fractal.img.img_ptr = mlx_new_image(fractal.mlx, WIDTH, HEIGHT);
	if(!fractal.img.img_ptr)
	{
		mlx_destroy_display(fractal.mlx);
		mlx_destroy_window(fractal.mlx, fractal.window);//TODO FREE
	}
	fractal.img.addr = mlx_get_data_addr(fractal.img.img_ptr, &fractal.img.bpp, &fractal.img.linelength, fractal.img.endian); 

	
	mlx_loop(fractal.mlx);
	
}