/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_players.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:37:16 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/12 12:50:53 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

int		ft_find_str_players(t_core *core, char **str)
{
	char *str1;
	char *str2;

	if (!(str1 = ft_itoa(core->number_players)))
		ft_sim_error(core);
	if (!(str2 = ft_strjoin("Choose ", str1)))
		ft_sim_error(core);
	ft_strdel(&str1);
	if (!(*str = ft_strjoin(str2, " Avatar(s):")))
		ft_sim_error(core);
	ft_strdel(&str2);
	return (0);
}

int		ft_create_theme_players(t_core *core)
{
	core->theme->rect0.x = 450;
	core->theme->rect0.y = 200;
	core->theme->rect0.w = 150;
	core->theme->rect0.h = 150;
	core->theme->rect1.x = 450;
	core->theme->rect1.y = 600;
	core->theme->rect1.w = 150;
	core->theme->rect1.h = 150;
	core->theme->rect2.x = 1200;
	core->theme->rect2.y = 200;
	core->theme->rect2.w = 150;
	core->theme->rect2.h = 150;
	core->theme->rect3.x = 1200;
	core->theme->rect3.y = 600;
	core->theme->rect3.w = 150;
	core->theme->rect3.h = 150;
	return (0);
}

int		ft_clear_fon(t_core *core)
{
	if (SDL_FillRect(core->screen_surface, &(core->theme->rect0), 0x2f7190))
		ft_error(core);
	if (SDL_FillRect(core->screen_surface, &(core->theme->rect1), 0x2f7190))
		ft_error(core);
	if (SDL_FillRect(core->screen_surface, &(core->theme->rect2), 0x2f7190))
		ft_error(core);
	if (SDL_FillRect(core->screen_surface, &(core->theme->rect3), 0x2f7190))
		ft_error(core);
	return (0);
}

int		ft_present_players_help(t_core *core)
{
	if (core->players_status[2] == 0)
	{
		if (SDL_BlitSurface(core->players->pl3_sh, NULL,
			core->screen_surface, &(core->theme->rect2)))
			ft_error(core);
	}
	else
	{
		if (SDL_BlitSurface(core->players->pl3, NULL,
			core->screen_surface, &(core->theme->rect2)))
			ft_error(core);
	}
	if (core->players_status[3] == 0)
	{
		if (SDL_BlitSurface(core->players->pl4_sh, NULL,
			core->screen_surface, &(core->theme->rect3)))
			ft_error(core);
	}
	else
	{
		if (SDL_BlitSurface(core->players->pl4, NULL,
			core->screen_surface, &(core->theme->rect3)))
			ft_error(core);
	}
	return (0);
}

int		ft_present_players(t_core *core)
{
	ft_clear_fon(core);
	if (core->players_status[0] == 0)
	{
		if (SDL_BlitSurface(core->players->pl1_sh, NULL, core->screen_surface,
		&(core->theme->rect0)))
			ft_error(core);
	}
	else
	{
		if (SDL_BlitSurface(core->players->pl1, NULL,
			core->screen_surface, &(core->theme->rect0)))
			ft_error(core);
	}
	ft_present_players_help_h(core);
	ft_present_players_help(core);
	if (SDL_UpdateWindowSurface(core->window))
		ft_error(core);
	return (0);
}
