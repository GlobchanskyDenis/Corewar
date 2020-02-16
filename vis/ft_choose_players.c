/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_players.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 13:07:03 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/09 13:23:46 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

int		ft_choose_players_hh(t_core *core)
{
	if (ft_point_in_round(core->event.button.x, core->event.button.y, 2))
	{
		if (core->event.button.button == SDL_BUTTON_LEFT)
			core->players_status[2] = 2;
		ft_fill_players_array(core, 0, 10);
		return (0);
	}
	if (ft_point_in_round(core->event.button.x, core->event.button.y, 3))
	{
		if (core->event.button.button == SDL_BUTTON_LEFT)
			core->players_status[3] = 2;
		ft_fill_players_array(core, 0, 1);
		return (0);
	}
	return (1);
}

void	ft_choose_players_h(t_core *core)
{
	if (ft_point_in_round(core->event.motion.x, core->event.motion.y, 0))
	{
		if (core->event.button.button == SDL_BUTTON_LEFT)
			core->players_status[0] = 2;
		ft_fill_players_array(core, 10, 0);
		return ;
	}
	if (ft_point_in_round(core->event.button.x, core->event.button.y, 1))
	{
		if (core->event.button.button == SDL_BUTTON_LEFT)
			core->players_status[1] = 2;
		ft_fill_players_array(core, 1, 0);
		return ;
	}
	if (ft_choose_players_hh(core) == 0)
		return ;
	if (ft_point_in_round(core->event.button.x, core->event.button.y, -1))
		ft_fill_players_array(core, 0, 0);
}

int		ft_choose_players(t_core *core)
{
	static int fl;

	if (fl == 0)
	{
		ft_players_fon(core);
		fl = 1;
	}
	while (1)
	{
		if (SDL_PollEvent(&(core->event)) != 0)
		{
			if ((core->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) ||
				(core->event.type == SDL_QUIT))
				return (1);
			if (ft_right_players_number(core))
			{
				core->status = 2;
				break ;
			}
			ft_choose_players_h(core);
			ft_present_players(core);
		}
	}
	return (0);
}
