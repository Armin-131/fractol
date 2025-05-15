/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <abenaven@42.student.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:13:19 by abenaven          #+#    #+#             */
/*   Updated: 2025/05/15 17:53:52 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

bool	checkinput(int	argc, char **argv, t_data *fractal)
{
	if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0)
	{
		fractal->name = argv[1];
		return (true);
	}		
	else if (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0)
	{
		fractal->name = argv[1];
		return (true);
	}
	else 
	{
		return (false);
	}	
}

bool	checkjulia(t_data *fractal, char **argv, int argc)
{
	double first;
	
	first = ft_atodbl(argv[2]);
	if (argc != 4 || ft_strncmp(argv[1], "julia", 5) != 0)
	{
        return (false);
		ft_putstr_fd("Invalid arguments for julia\n", 2);
		exit(EXIT_FAILURE);
	}
	if (first < -2 || first > 2)
	{
		ft_putstr_fd("Invalid arguments for julia! First parameter must be between -2 and 2\n", 2);
		exit(EXIT_FAILURE);
	}
	
	fractal->julia_x = first;
	fractal->julia_y = ft_atodbl(argv[3]);
	return (true);
}


int		main(int argc, char **argv)
{
	t_data	fractal;
	
	if (checkinput(argc, argv, &fractal))
	{
		checkjulia(&fractal, argv, argc);
		initx(&fractal);
		render(&fractal);
		mlx_loop(fractal.mlx);
	}
	else 
		ft_putendl_fd ("Either enter mandelbrot or julia with julia values", 2);
}

