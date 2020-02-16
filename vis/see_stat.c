/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   see_stat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:51:40 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/12 09:44:06 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

int		ft_see_stat_h(t_core *core, int x, int y, int num)
{
	if (num == 3 && x >= core->theme->rect2.x + 30 \
			&& x <= core->theme->rect2.x + 150 - 30)
	{
		if (num % 2 != 0 && y >= core->theme->rect2.y + 150 + 5 \
				&& y <= core->theme->rect2.y + 150 + 30 + 5)
			return (1);
	}
	else if (num == 4 && x >= core->theme->rect3.x + 30 \
			&& x <= core->theme->rect3.x + 150 - 30)
	{
		if (num % 2 == 0 && y >= core->theme->rect3.y - 5 - 30 \
				&& y <= core->theme->rect3.y - 5)
			return (1);
	}
	return (0);
}

int		ft_see_stat(t_core *core, int x, int y, int num)
{
	if (num == -1)
		return (0);
	ft_get_col(&core->text_color, 0xf73a18);
	if (num == 1 && x >= core->theme->rect0.x + 30 \
			&& x <= core->theme->rect0.x + 150 - 30)
	{
		if (num % 2 != 0 && y >= core->theme->rect0.y + 150 + 5 \
				&& y <= core->theme->rect0.y + 150 + 30 + 5)
			return (1);
	}
	else if (num == 2 && x >= core->theme->rect1.x + 30 \
			&& x <= core->theme->rect1.x + 150 - 30)
	{
		if (num % 2 == 0 && y >= core->theme->rect1.y - 5 - 30  \
				&& y <= core->theme->rect1.y - 5)
			return (1);
	}
	return (ft_see_stat_h(core, x, y, num));
}

int		ft_fill_status_array(t_core *core, int a, int b)
{
	if (core->status_status[0] != 2)
		core->status_status[0] = a / 10;
	if (core->status_status[1] != 2)
		core->status_status[1] = a % 10;
	if (core->status_status[2] != 2)
		core->status_status[2] = b / 10;
	if (core->status_status[3] != 2)
		core->status_status[3] = b % 10;
	return (0);
}
