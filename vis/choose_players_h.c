/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_players_h.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 12:08:41 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/12 12:51:55 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

int		ft_players_fon(t_core *core)
{
	char *str;

	if (!(core->players_status = (int *)malloc(sizeof(int) * 4)))
		ft_sim_error(core);
	core->players_status[0] = 0;
	core->players_status[1] = 0;
	core->players_status[2] = 0;
	core->players_status[3] = 0;
	if (SDL_FillRect(core->screen_surface, &(core->theme->rect0), 0x2f7190))
		ft_error();
	str = NULL;
	ft_find_str_players(core, &str);
	ft_text_theme(core, str);
	ft_strdel(&str);
	ft_create_theme_players(core);
	ft_load_players(core);
	ft_present_players(core);
	if (SDL_UpdateWindowSurface(core->window))
		ft_error(core);
	return (0);
}

int		ft_point_in_round_h(int x, int y, int r)
{
	if (r == 2)
	{
		if (((float)x - 1362.5) * ((float)x - 1362.5) + ((float)y - 362.5)
			* ((float)y - 362.5) <= 162.5 * 162.5)
			return (1);
		else
			return (0);
	}
	if (r == 3)
	{
		if (((float)x - 1362.5) * ((float)x - 1362.5) + ((float)y - 762.5)
			* ((float)y - 762.5) <= 162.5 * 162.5)
			return (1);
		else
			return (0);
	}
	return (2);
}

int		ft_point_in_round(int x, int y, int r)
{
	int a;

	if (r == 0)
	{
		if (((float)x - 612.5) * ((float)x - 612.5) + ((float)y - 362.5)
			* ((float)y - 362.5) <= 162.5 * 162.5)
			return (1);
		else
			return (0);
	}
	if (r == 1)
	{
		if (((float)x - 612.5) * ((float)x - 612.5) + ((float)y - 762.5)
			* ((float)y - 762.5) <= 162.5 * 162.5)
			return (1);
		else
			return (0);
	}
	a = ft_point_in_round_h(x, y, r);
	if (a != 2)
		return (a);
	if (r == -1)
		return (1);
	return (0);
}
