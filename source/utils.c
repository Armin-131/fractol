/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <abenaven@42.student.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:38:41 by abenaven          #+#    #+#             */
/*   Updated: 2025/05/15 17:01:22 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mlxerror(void *mlx)
{
	if(!mlx)
	{
		ft_putstr_fd("Mlx initialisation error", 1);
		exit(EXIT_FAILURE);
	}
}

void	windowerror(t_data *fractal)
{
	if(!fractal->window)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		ft_putendl_fd("Window failed!", 2);
	}
}

void	imgerror(t_data *fractal)
{
	mlx_destroy_window(fractal->mlx, fractal->window);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	ft_putendl_fd("Image failed!", 2);
}
int	closeall(t_data *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img.img_ptr);
	mlx_clear_window(fractal->mlx, fractal->window);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	ft_putstr_fd("Program exited succesfully", 1);
	exit(EXIT_SUCCESS);
	return (0);
}
