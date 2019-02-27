/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <lcordeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 18:15:30 by lcordeno          #+#    #+#             */
/*   Updated: 2019/02/27 17:08:33 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	mv_right(t_base *base)
{
	base->mvx -= 50 * base->zm;
	ft_redraw(base);
}

void	mv_left(t_base *base)
{
	base->mvx += 50 * base->zm;
	ft_redraw(base);
}

void	mv_up(t_base *base)
{
	base->mvy += 50 * base->zm;
	ft_redraw(base);
}

void	mv_down(t_base *base)
{
	base->mvy -= 50 * base->zm;
	ft_redraw(base);
}

void	move(int key, t_base *base)
{
	if (key == 126)
		mv_up(base);
	if (key == 125)
		mv_down(base);
	if (key == 123)
		mv_left(base);
	if (key == 124)
		mv_right(base);
}
