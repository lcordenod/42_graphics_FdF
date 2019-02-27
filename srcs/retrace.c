/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <lcordeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 16:03:28 by lcordeno          #+#    #+#             */
/*   Updated: 2019/02/27 17:00:15 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	ft_redraw(t_base *base)
{
	mlx_destroy_image(base->mlx.mlx_ptr, base->img_ptr);
    line_size(base, &(base->margins), &(base->resize));
	center(base, &(base->resize));
	base->img_ptr = mlx_new_image(base->mlx.mlx_ptr, base->xwin, base->ywin);
	base->str = (unsigned int*)mlx_get_data_addr(base->img_ptr,
	&(base->mlx.bits_per_pixels), &(base->mlx.size_line), &(base->mlx.edian));
    trace_x(*base, base->margins);
	trace_y(*base, base->margins);
	trace_c_x(base);
	trace_c_y(base);
	mlx_clear_window(base->mlx.mlx_ptr, base->mlx.win_ptr);
    mlx_put_image_to_window(base->mlx.mlx_ptr, base->mlx.win_ptr,
    base->img_ptr, 0, 0);
}