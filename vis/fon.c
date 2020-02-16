/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fon.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:06:09 by jmaynard          #+#    #+#             */
/*   Updated: 2020/02/12 12:51:58 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

int		ft_draw_lines(t_core *core)
{
	SDL_Rect rect;

	rect.x = 220;
	rect.y = 0;
	rect.w = 2;
	rect.h = core->screen_height;
	if (SDL_FillRect(core->screen_surface, &rect, 0x060b0d) < 0)
		ft_error();
	rect.x = 1780;
	if (SDL_FillRect(core->screen_surface, &rect, 0x060b0d) < 0)
		ft_error();
	rect.x = 220;
	rect.y = 960;
	rect.w = core->screen_width - 440;
	rect.h = 2;
	if (SDL_FillRect(core->screen_surface, &rect, 0x060b0d) < 0)
		ft_error();
	return (0);
}

void	ft_init_fon(t_core *core)
{
	if (!(core->status_status = (int *)malloc(sizeof(int) * 4)))
		ft_sim_error();
	core->status_status[0] = 0;
	core->status_status[1] = 0;
	core->status_status[2] = 0;
	core->status_status[3] = 0;
	core->theme->rect0.x = 0;
	core->theme->rect0.y = 0;
	core->theme->rect0.w = core->screen_width;
	core->theme->rect0.h = core->screen_height;
	if (SDL_FillRect(core->screen_surface, \
		&(core->theme->rect0), core->game_fon) < 0)
		ft_error();
	core->game = (t_game *)malloc(sizeof(t_game));
	core->game->field = NULL;
	core->game->prev_field = NULL;
	core->game->posi = NULL;
	core->game->prev_owner = NULL;
}

int		ft_game_fon(t_core *core, t_vm *vm)
{
	ft_init_fon(core);
	ft_load_players_info(core, vm);
	ft_draw_lines(core);
	ft_reload_players(core);
	ft_put_players(core);
	ft_put_defines(core, vm);
	ft_draw_defines(core);
	ft_load_comments(core);
	ft_load_pic_com(core);
	if (SDL_UpdateWindowSurface(core->window) < 0)
		ft_error();
	return (0);
}
