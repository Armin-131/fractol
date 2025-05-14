/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <abenaven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:21:49 by abenaven          #+#    #+#             */
/*   Updated: 2025/05/14 22:55:36 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		handlekeys(int symbol, t_data *fractal)
{
	if (symbol == XK_Escape)
		closeall(fractal);
	if (symbol == XK_Left)
		fractal->x = fractal->x + (0.5 * fractal->zoom);
	else if (symbol == XK_Right)
		fractal->x = fractal->x - (0.5 * fractal->zoom);
	else if (symbol == XK_Up)
		fractal->y = fractal->y + (0.5 * fractal->zoom);
	else if (symbol == XK_Down)
		fractal->y = fractal->y - (0.5 * fractal->zoom);
	else if (symbol ==  XK_plus)
		fractal->idef = fractal->idef + 10;
	else if (symbol == XK_minus)
		fractal->idef = fractal->idef - 10;
	else if (XK_c)
		fractal->colourchange = (fractal->colourchange + 1) % 2;
	render(fractal);
	return(0);
}

int	handlemouse(int button, int x, int y, t_data *fractal)
{
	(void)x;
	(void)y;
	if (button == Button4)
		fractal->zoom = fractal->zoom * 1.1;
	else if (button == Button5)
		fractal->zoom = fractal->zoom * 0.9;
	return (0);
}

int	trackjulia(int x, int y, t_data *fractal)
{
	if (ft_strncmp(fractal->name, "julia", 5) == 0)
	{
		fractal->julia_x = (mapping(x, -2, 2, 0, WIDTH) * fractal->zoom) + fractal->x;
		fractal->julia_y = (mapping(y, 2, -2, 0, HEIGHT) * fractal->zoom) + fractal->y;
		render(fractal);
	}
	return (0);
}

int	checkjulia(t_data *fractal, char **argv, int argc)
{
	int		i;

	i = 0;
	fractal->name = argv[1];
	if((argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0))
	{
		while (argv[2][i] && argv[3][i])
		{
			if (((argv[2][i] >= '0' && argv[2][i] <= '9')
				|| argv[2][i] == '.' || argv[2][i] == '-' || argv[2][i] == '+')
				&& ((argv[3][i] >= '0' && argv[3][i] <= '9')
				|| argv[3][i] == '.' || argv[3][i] == '-' || argv[3][i] == '+'))
			{
				fractal->julia_x = ft_atodbl(argv[2]);
				fractal->julia_y = ft_atodbl(argv[3]);
			}
			else
				ft_putendl_fd("Please enter values within range(-2 to 2)", 2);
			i++;
		}
	}
	return (0);
}
