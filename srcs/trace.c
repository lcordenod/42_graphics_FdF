/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 10:15:41 by lcordeno          #+#    #+#             */
/*   Updated: 2019/02/26 16:20:50 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	trace_rd(t_pos p, t_base base)
{
	int e;
	int dx;
	int dy;
	int yy;

	dy = p.y2 - p.y1;
	dx = p.x2 - p.x1;
	yy = dy > 0 ? 1 : -1;
	dy = abs(dy);
	e = 2 * dy - dx;
	while (p.x1 <= p.x2)
	{
		if ((p.x1 + base.center_x > 0 && p.x1 + base.center_x < base.xwin &&
		p.y1 + base.center_y > 0 && p.y1 + base.center_y < base.ywin))
			base.str[(p.x1 + base.center_x) + ((p.y1 + base.center_y) *
			base.xwin)] = color(base);
		p.y1 = e > 0 ? p.y1 + yy : p.y1;
		e = e > 0 ? e - 2 * dx : e;
		e = e + 2 * dy;
		p.x1++;
	}
}

void	trace_ur(t_pos p, t_base base)
{
	int e;
	int dx;
	int dy;
	int	xx;

	dy = p.y2 - p.y1;
	dx = p.x2 - p.x1;
	xx = dx > 0 ? 1 : -1;
	dx = abs(dx);
	e = 2 * dx - dy;
	while (p.y1 <= p.y2)
	{
		if ((p.x1 + base.center_x > 0 && p.x1 + base.center_x < base.xwin &&
		p.y1 + base.center_y > 0 && p.y1 + base.center_y < base.ywin))
			base.str[(p.x1 + base.center_x) + ((p.y1 + base.center_y) *
			base.xwin)] = color(base);
		p.x1 = e > 0 ? p.x1 + xx : p.x1;
		e = e > 0 ? e - 2 * dy : e;
		e = e + 2 * dx;
		p.y1++;
	}
}

void	trace_ld(t_pos p, t_base base)
{
	int e;
	int dx;
	int dy;
	int	yy;

	dy = p.y1 - p.y2;
	dx = p.x1 - p.x2;
	yy = dy > 0 ? 1 : -1;
	dy = abs(dy);
	e = 2 * dy - dx;
	while (p.x2 <= p.x1)
	{
		if ((p.x2 + base.center_x > 0 && p.x2 + base.center_x < base.xwin &&
		p.y2 + base.center_y > 0 && p.y2 + base.center_y < base.ywin))
			base.str[(p.x2 + base.center_x) + ((base.center_y + p.y2) *
			base.xwin)] = color(base);
		p.y2 = e > 0 ? p.y2 + yy : p.y2;
		e = e > 0 ? e - 2 * dx : e;
		e = e + 2 * dy;
		p.x2++;
	}
}

void	trace_ul(t_pos p, t_base base)
{
	int e;
	int dx;
	int dy;
	int	xx;

	dy = p.y2 - p.y1;
	dx = p.x2 - p.x1;
	xx = dx > 0 ? 1 : -1;
	dx = abs(dx);
	e = 2 * dx - dy;
	while (p.y1 <= p.y2)
	{
		if ((p.x1 + base.center_x > 0 && p.x1 + base.center_x < base.xwin &&
		p.y1 + base.center_y > 0 && p.y1 + base.center_y < base.ywin))
			base.str[(p.x1 + base.center_x) + ((p.y1 + base.center_y) *
			base.xwin)] = color(base);
		p.x1 = e > 0 ? p.x1 + xx : p.x1;
		e = e > 0 ? e - 2 * dy : e;
		e = e + 2 * dx;
		p.y1++;
	}
}

void	trace_line(t_base base, t_trace *lines)
{
	t_pos	p;

	p.x1 = lines->x1;
	p.y1 = lines->y1;
	p.x2 = lines->x2;
	p.y2 = lines->y2;
	trace_selector(&p, base);
	lines->dx = p.x2 - p.x1;
	lines->dy = p.y2 - p.y1;
	if (abs(p.y2 - p.y1) < abs(p.x2 - p.x1))
	{
		if (p.x1 > p.x2)
			trace_ld(p, base);
		else
			trace_rd(p, base);
	}
	else
	{
		if (p.y1 > p.y2)
			trace_ul(p, base);
		else
			trace_ur(p, base);
	}
}
