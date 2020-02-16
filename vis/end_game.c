/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:23:19 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/12 12:52:42 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

int		ft_game_over(t_core *core)
{
	SDL_Rect	rect;
	SDL_Color	col;

	rect.x = 0;
	rect.y = 50;
	rect.h = 900;
	rect.w = 1900;
	ft_get_col(&col, 0x5f010a);
	col.a = 20;
	if (!(core->text_surface = TTF_RenderText_Blended(core->font_menu,
		("game over"), col)))
		ft_error_ttf();
	if (SDL_BlitScaled(core->text_surface, NULL, core->screen_surface, &rect))
		ft_error(core);
	SDL_FreeSurface(core->text_surface);
	core->text_surface = NULL;
	return (0);
}

int		ft_funal_screen(t_core *core, t_vm *vm)
{
	if (SDL_PollEvent(&(core->event)) != 0)
	{
		if ((core->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			|| (core->event.type == SDL_QUIT))
			return (1);
	}
	if (core->game->status == 9)
	{
		ft_present_winner(core, vm);
		ft_titres(core);
	}
	if (SDL_UpdateWindowSurface(core->window))
		ft_error(core);
	return (0);
}

int		ft_strelochka(t_core *core, SDL_Rect rect)
{
	if ((core->event.button.button == SDL_BUTTON_LEFT) &&
	((core->event.button.x >= 930 && core->event.button.x <= 1070) &&
	(core->event.button.y >= 900 && core->event.button.y <= 950)))
	{
		if (SDL_FillRect(core->screen_surface, &rect, 0x2f7190))
			ft_error(core);
		rect.x = 1000;
		if (SDL_FillRect(core->screen_surface, &rect, 0x000000))
			ft_error(core);
		if (SDL_UpdateWindowSurface(core->window))
			ft_error(core);
		core->game->status = 9;
		return (0);
	}
	return (1);
}

int		ft_end_game_help(t_core *core, SDL_Rect rect)
{
	int i;

	i = 0;
	while (i < 1000)
	{
		if (SDL_PollEvent(&(core->event)) != 0)
		{
			if ((core->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				|| (core->event.type == SDL_QUIT))
				return (1);
			if (ft_strelochka(core, rect) == 0)
				return (0);
		}
		ft_game_over(core);
		i += 10;
		if (SDL_UpdateWindowSurface(core->window))
			ft_error(core);
	}
	return (2);
}

int		ft_end_game(t_core *core, t_vm *vm)
{
	SDL_Rect	rect;
	int			a;

	rect.x = 0;
	rect.y = 0;
	rect.w = 1000;
	rect.h = 1000;
	if (core->game->status == 8)
	{
		a = ft_end_game_help(core, rect);
		if (a != 2)
			return (a);
		ft_other(core);
	}
	if (core->game->status >= 9)
	{
		if (ft_funal_screen(core, vm))
			return (1);
	}
	return (0);
}
