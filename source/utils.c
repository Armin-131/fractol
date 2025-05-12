/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <abenaven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:38:41 by abenaven          #+#    #+#             */
/*   Updated: 2025/05/12 21:02:12 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mlxerror(void *mlx)
{
	if(!mlx)
		ft_putendl_fd("Mlx initialisation error", 2);
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

