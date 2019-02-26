/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:12:47 by lcordeno          #+#    #+#             */
/*   Updated: 2019/02/26 16:15:25 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	color(t_base base)
{
	unsigned int	color;
	int				z;

	color = 0xFFFFFF;
	z = base.map[base.y][base.x] > base.map[base.ty][base.tx] ?
		base.map[base.y][base.x] : base.map[base.ty][base.tx];
	if (z < 3)
		color = 0x0000FF;
	else if (z < 100)
		color = 0x22780F;
	else if (z <= 500)
		color = 0xFFDEAD;
	return (color);
}
