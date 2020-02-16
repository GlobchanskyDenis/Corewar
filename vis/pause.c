/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:53:30 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/12 12:53:03 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

int		ft_draw_pause(t_core *core)
{
	SDL_Rect	rect;
	SDL_Color	col;

	rect.x = 250;
	rect.y = 0;
	rect.h = 960;
	rect.w = 1500;
	ft_get_col(&col, 0xffffff);
	col.a = 60;
	if (!(core->text_surface = TTF_RenderText_Blended(core->font_menu, \
			"pause", col)))
		ft_error_ttf();
	if (SDL_BlitScaled(core->text_surface, \
			NULL, core->screen_surface, &rect) < 0)
		ft_error();
	SDL_FreeSurface(core->text_surface);
	core->text_surface = NULL;
	return (0);
}

int		ft_redraw_pause(t_core *core, t_vm *vm)
{
	SDL_Rect rect;

	rect.x = 250;
	rect.y = 0;
	rect.h = 960;
	rect.w = 1500;
	if (SDL_FillRect(core->screen_surface, &rect, core->game_fon) < 0)
		ft_error();
	ft_draw_field(core, vm, 1);
	ft_draw_carriet(core, vm);
	return (0);
}
