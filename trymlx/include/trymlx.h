/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trymlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <abenaven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:12:24 by abenaven          #+#    #+#             */
/*   Updated: 2025/04/26 20:20:07 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRYMLX_H
# define TRYMLX_H

# include "mlx.h"
# include "mlx_int.h"
# include <stdbool.h>

typedef struct s_data
{
	void *img;
	char *addr;
	int		bpp;
	int		linelength;
	int		endian;
}		t_data;

#endif