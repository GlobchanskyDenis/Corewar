/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_field_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:34:49 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/09 15:58:49 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

int		ft_get_rect(SDL_Rect *rect, int flag)
{
	static int i;

	if (flag == 1)
	{
		i = 0;
		return (0);
	}
	if (i == 192)
	{
		i = 0;
		rect->y += 15;
		rect->x = 228;
	}
	rect->x += 8;
	i++;
	return (0);
}

int		ft_get_symb(t_core *core, char **str, int flag)
{
	static int i;

	if (flag == 1)
	{
		i = 0;
		return (0);
	}
	if (!(*str))
		ft_strdel(str);
	if (!(*str = (char *)malloc(sizeof(char) * 2)))
		ft_sim_error(core);
	(*str)[0] = (core->game->field)[i];
	(*str)[1] = '\0';
	i++;
	return (0);
}

void	ft_eql_col(SDL_Color *col1, SDL_Color col2)
{
	col1->r = col2.r;
	col1->g = col2.g;
	col1->b = col2.b;
}

void	ft_find_owner_col_h(t_core *core, short pl, int *a)
{
	if (core->players_status[1] && (pl == 1))
		*a = 2;
	else if (!core->players_status[1])
	{
		if (pl == 1)
			*a = 3;
		if (pl == 2)
			*a = 4;
	}
	else if (pl == 2)
	{
		if (core->players_status[2])
			*a = 3;
		if (core->players_status[3])
			*a = 4;
	}
}

void	ft_find_owner_col_hh(t_core *core, short pl, int *a, short max_pl)
{
	if (max_pl == 4)
	{
		if (pl == 1)
			*a = 1;
		if (pl == 2)
			*a = 2;
		if (pl == 3)
			*a = 3;
		if (pl == 4)
			*a = 4;
	}
	if (max_pl == 1)
	{
		if (core->players_status[0])
			*a = 1;
		if (core->players_status[1])
			*a = 2;
		if (core->players_status[2])
			*a = 3;
		if (core->players_status[3])
			*a = 4;
	}
}
