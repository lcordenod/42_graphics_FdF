/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <lcordeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 12:21:59 by lcordeno          #+#    #+#             */
/*   Updated: 2019/02/27 17:07:53 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	inc_z(t_base *base)
{
	base->z += 1;
	ft_redraw(base);
}

void	dec_z(t_base *base)
{
	base->z -= 1;
	ft_redraw(base);
}

void	change_z(int key, t_base *base)
{
	if (key == 88)
		inc_z(base);
	if (key == 92)
		dec_z(base);
}
