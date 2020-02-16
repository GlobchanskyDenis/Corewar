/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:22:18 by jmaynard          #+#    #+#             */
/*   Updated: 2020/02/12 12:27:09 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void	ft_status_event(t_core *core)
{
	if (core->game->status == 1)
	{
		if (ft_see_stat(core, core->event.button.x, core->event.button.y, 1))
			ft_fill_status_array(core, 10, 0);
		else if (ft_see_stat(core, core->event.button.x, \
			core->event.button.y, 2))
			ft_fill_status_array(core, 1, 0);
		else if (ft_see_stat(core, core->event.button.x, \
			core->event.button.y, 3))
			ft_fill_status_array(core, 0, 10);
		else if (ft_see_stat(core, core->event.button.x, \
			core->event.button.y, 4))
			ft_fill_status_array(core, 0, 1);
		else
			ft_fill_status_array(core, 0, 0);
		ft_present_status(core);
	}
}

int		ft_game_event(t_core *core, t_vm *vm, int *a)
{
	if ((core->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) \
		|| (core->event.type == SDL_QUIT))
		return (1);
	if (core->event.key.keysym.scancode == SDL_SCANCODE_F)
		*a = 1;
	if ((core->event.key.keysym.scancode == SDL_SCANCODE_U) && (*a == 1))
		*a = 2;
	if ((core->event.key.keysym.scancode == SDL_SCANCODE_N) && (*a == 2))
		core->game->status = -1;
	ft_status_event(core);
	if ((core->event.key.keysym.scancode == SDL_SCANCODE_SPACE \
		&& core->game->status == 1) && (core->game->status != -1))
	{
		ft_draw_pause(core);
		core->game->status = 0;
	}
	if ((core->event.key.keysym.scancode == SDL_SCANCODE_RETURN \
		&& core->game->status == 0) && (core->game->status != -1))
	{
		ft_redraw_pause(core, vm);
		core->game->status = 1;
	}
	return (0);
}
