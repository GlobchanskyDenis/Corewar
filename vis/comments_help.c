/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comments_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 13:59:25 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/15 15:45:45 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

int		ft_is_ok(t_core *core, int i)
{
	if (core->players_status[i / 10 - 1])
		return (1);
	else
		return (0);
}

void	ft_next_comm_h(int *i, int j)
{
	j = 0;
	if (*i / 10 < 4)
	{
		*i = ((*i / 10) + 1) * 10 + *i % 10;
	}
	else
	{
		if (*i % 10 == 3)
		{
			*i = 11;
		}
		else
		{
			*i = 10 + (*i % 10) + 1;
		}
	}
}

int		ft_next_comm(t_core *core)
{
	static int	i;
	int			j;

	j = 0;
	while (j == 0 || ft_is_ok(core, i) == 0)
	{
		j = 1;
		if (i == 0)
		{
			i = 11;
		}
		else
		{
			ft_next_comm_h(&i, j);
		}
	}
	return (i);
}

int		ft_find_rect_sq(t_core *core, SDL_Rect *rect, int pl)
{
	rect->w = 150;
	rect->h = 160;
	if (pl == 1)
	{
		rect->x = core->theme->rect0.x;
		rect->y = core->theme->rect0.y - 10 - 150;
	}
	if (pl == 2)
	{
		rect->x = core->theme->rect1.x;
		rect->y = core->theme->rect1.y + 10 + 150;
	}
	if (pl == 3)
	{
		rect->x = core->theme->rect2.x;
		rect->y = core->theme->rect2.y - 10 - 150;
	}
	if (pl == 4)
	{
		rect->x = core->theme->rect3.x;
		rect->y = core->theme->rect3.y + 10 + 150;
	}
	return (0);
}

int		ft_find_rect_com(t_core *core, SDL_Rect *rect, int pl)
{
	rect->w = 140;
	rect->h = 120;
	if (pl == 1)
	{
		rect->x = core->theme->rect0.x;
		rect->y = core->theme->rect0.y - 5 - 100;
	}
	if (pl == 2)
	{
		rect->x = core->theme->rect1.x;
		rect->y = core->theme->rect1.y + 5 + 150 + 100;
	}
	if (pl == 3)
	{
		rect->x = core->theme->rect2.x;
		rect->y = core->theme->rect2.y - 5 - 100;
	}
	if (pl == 4)
	{
		rect->x = core->theme->rect3.x;
		rect->y = core->theme->rect3.y + 5 + 150 + 100;
	}
	return (0);
}
