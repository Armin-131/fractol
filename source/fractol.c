/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <abenaven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:13:19 by abenaven          #+#    #+#             */
/*   Updated: 2025/05/14 23:56:40 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

bool	checkinput(int	argc, char **argv, t_data *fractal)
{
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
	{
		fractal->name = argv[1];
		return (true);
	}		
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 6))
	{
		fractal->name = argv[1];
		return (true);
	}
	else 
	{
		exit(1);
		return (false);
	}	
}

int		main(int argc, char **argv)
{
	t_data	fractal;
	
	if (!checkinput(argc, argv, &fractal))
		exit (1);
	if (checkinput(argc, argv, &fractal))
	{
		checkjulia(&fractal, argv, argc);
		initx(&fractal);
		render(&fractal);
		mlx_loop(fractal.mlx);
	}
	else 
		ft_putendl_fd ("Either enter Mandelbrot or Julia and Julia values", 2);
}

