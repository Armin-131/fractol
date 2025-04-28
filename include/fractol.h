/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <abenaven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:24:20 by abenaven          #+#    #+#             */
/*   Updated: 2025/04/28 00:58:21 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <stdbool.h>
# include <math.h>

#define WIDTH  1920
#define HEIGHT 1080

typedef struct s_image //where we wil buffer our pixels that will be pushed to the window
{
	void *img_ptr;//pointer to tthe image
	char *addr;//pointer to the pixels
	int		bpp;
	int		linelength;
	int		endian;
}		t_image;

typedef struct s_data
{
	char  *name;
	void	*mlx; //connection to mlx api
	void	*window; // pointer to the window 
	t_image	img;
	int		x;
	int		y;
}	t_data;

void	checkinput(int	argc, char **argv, t_data fractal);

#endif