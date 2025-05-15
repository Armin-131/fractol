/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <abenaven@42.student.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:24:20 by abenaven          #+#    #+#             */
/*   Updated: 2025/05/15 17:55:07 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <stdbool.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>

# define WIDTH  800
# define HEIGHT 800

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define RED 0x0FF0000

# define CYAN  0x0AF0EC
# define BPINK 0xD10D5B
# define BGREEN 0x27f507
# define WINE 0x8C0404
# define LILAC 0xB674E8
# define BBLUE 0x220FF2
# define BORGANGE 0xF27D0F
# define BPURPLE 0x870ACF
# define BABYPINK 0xEB6EBD
# define BROWN 0x7B3F00

typedef struct s_image //where we wil buffer our pixels that will be pushed to the window
{
	void *img_ptr;//pointer to the image
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
	double		x;
	double		y;
	double	outoflimits;
	int		idef;
	double  zoom;
	double  julia_x;
	double  julia_y;
	
}	t_data;

typedef struct s_complex
{
	double x; // real axis
	double y; // imaginary axis
}		t_complex;
//init
void	initx(t_data *fractal);
//error handling
bool	checkinput(int	argc, char **argv, t_data *fractal);
void		mlxerror(void *mlx);
void	windowerror(t_data *fractal);
void	imgerror(t_data *fractal);

int	closeall(t_data *fractal);
//render
void	render(t_data *fractal);
int		handlekeys(int symbol, t_data *fractal);
int	handlemouse(int button, int x, int y, t_data *fractal);
int	mousetrackjulia(int x, int y, t_data *fractal);
bool	checkjulia(t_data *fractal, char **argv, int argc);
//math
double		scaling(double un, double nmin, double nmax, double omax);
t_complex	sumcomplex(t_complex z1, t_complex z2);
t_complex	sqrtcomplex(t_complex z);

#endif