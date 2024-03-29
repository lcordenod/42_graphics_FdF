/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <lcordeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 19:01:55 by lcordeno          #+#    #+#             */
/*   Updated: 2019/02/27 17:09:02 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	zoom_in(t_base *base)
{
	base->zm += 1;
	if (base->zm >= 10)
		base->zm = 10;
	ft_redraw(base);
}

void	zoom_out(t_base *base)
{
	base->zm -= 1;
	if (base->zm == 0)
		base->zm = 1;
	ft_redraw(base);
}

void	zoom(int key, t_base *base)
{
	if (key == 78)
		zoom_out(base);
	if (key == 69)
		zoom_in(base);
}
