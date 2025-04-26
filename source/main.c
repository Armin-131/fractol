/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <abenaven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:13:19 by abenaven          #+#    #+#             */
/*   Updated: 2025/04/26 17:14:12 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

int		main(void)
{
	void *mlx;
	void *mlx_window;
	
	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 1000, 1000, "Hiii");
	mlx_loop(mlx);
}