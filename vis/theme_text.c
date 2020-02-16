/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   theme_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:20:31 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/12 12:51:59 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

int		ft_text_theme(t_core *core, char *str)
{
	SDL_Rect rect0;

	core->text_color.a = 0x00;
	rect0.x = 700;
	rect0.y = 100;
	rect0.w = 600;
	rect0.h = 100;
	core->text_color.r = 0xac;
	core->text_color.g = 0x75;
	core->text_color.b = 0x4c;
	if (!(core->text_surface = TTF_RenderText_Blended(core->font_menu, \
			(const char *)str, core->text_color)))
		ft_error_ttf();
	if (SDL_BlitScaled(core->text_surface, \
			NULL, core->screen_surface, &rect0) < 0)
		ft_error();
	SDL_FreeSurface(core->text_surface);
	core->text_surface = NULL;
	return (0);
}

int		ft_text_fight(t_core *core, int fl)
{
	core->text_color.a = 0x00;
	if (fl == 0 || fl == 2)
	{
		ft_get_col(&core->text_color, 0xd7b5a1);
		if (fl == 2)
			core->text_color.a = 0x50;
	}
	if (fl == 1)
		ft_get_col(&core->text_color, 0x5f010a);
	if (SDL_FillRect(core->screen_surface, &(core->theme->rect1), 0x2f7190) < 0)
		ft_error();
	if (!(core->text_surface = TTF_RenderText_Blended(core->font_menu, \
			("Cavalier Fight"), core->text_color)))
		ft_error_ttf();
	if (SDL_BlitScaled(core->text_surface, NULL,\
			core->screen_surface, &(core->theme->rect1)) < 0)
		ft_error();
	SDL_FreeSurface(core->text_surface);
	core->text_surface = NULL;
	return (0);
}

int		ft_text_inter(t_core *core, int fl)
{
	core->text_color.a = 0x00;
	if ((fl == 0) || (fl == 2))
	{
		ft_get_col(&core->text_color, 0xd7b5a1);
		if (fl == 2)
			core->text_color.a = 0x50;
	}
	if (fl == 1)
		ft_get_col(&core->text_color, 0x5f010a);
	if (SDL_FillRect(core->screen_surface, &(core->theme->rect2), 0x2f7190) < 0)
		ft_error();
	if (!(core->text_surface = TTF_RenderText_Blended(core->font_menu, \
			("International"), core->text_color)))
		ft_error_ttf();
	if (SDL_BlitScaled(core->text_surface, \
			NULL, core->screen_surface, &(core->theme->rect2)) < 0)
		ft_error();
	SDL_FreeSurface(core->text_surface);
	core->text_surface = NULL;
	return (0);
}

int		ft_text_disco(t_core *core, int fl)
{
	core->text_color.a = 0x00;
	if (fl == 0 || fl == 2)
	{
		ft_get_col(&core->text_color, 0xd7b5a1);
		if (fl == 2)
			core->text_color.a = 0x50;
	}
	if (fl == 1)
		ft_get_col(&core->text_color, 0x5f010a);
	if (SDL_FillRect(core->screen_surface, &(core->theme->rect3), 0x2f7190) < 0)
		ft_error();
	if (!(core->text_surface = TTF_RenderText_Blended(core->font_menu, \
			("Default"), core->text_color)))
		ft_error_ttf();
	if (SDL_BlitScaled(core->text_surface, \
			NULL, core->screen_surface, &(core->theme->rect3)) < 0)
		ft_error();
	SDL_FreeSurface(core->text_surface);
	core->text_surface = NULL;
	return (0);
}
