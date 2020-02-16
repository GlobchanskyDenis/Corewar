/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_change.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:32:21 by jmaynard          #+#    #+#             */
/*   Updated: 2020/02/12 12:58:28 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void	ft_render_text(t_core *core, const char *str, SDL_Rect *rect)
{
	if (!(core->text_surface = TTF_RenderText_Blended(core->font_name, \
			str, core->text_color)))
		ft_error_ttf();
	if (SDL_BlitScaled(core->text_surface, \
		NULL, core->screen_surface, rect) < 0)
		ft_error();
}

void	ft_print_status_top(t_core *core, \
			SDL_Rect *rect, SDL_Color col, char *s)
{
	char *str;

	ft_eql_col(&core->text_color, col);
	if (ft_strlen(s) > 23)
	{
		str = (char *)malloc(sizeof(char) * 24);
		ft_strncpy(str, s, 23);
		str[23] = '\0';
		ft_render_text(core, str, rect);
		rect->y += 30;
		ft_render_text(core, s + 23, rect);
		ft_strdel(&str);
	}
	else
		ft_render_text(core, s, rect);
	SDL_FreeSurface(core->text_surface);
	core->text_surface = NULL;
}

void	ft_print_status_down(t_core *core, \
			SDL_Rect *rect, SDL_Color col, char *s)
{
	char *str;

	ft_eql_col(&core->text_color, col);
	if (ft_strlen(s) > 23)
	{
		str = (char *)malloc(sizeof(char) * 24);
		ft_strncpy(str, s, 23);
		str[23] = '\0';
		ft_render_text(core, s + 23, rect);
		rect->y -= 30;
		ft_render_text(core, str, rect);
		ft_strdel(&str);
	}
	else
		ft_render_text(core, s, rect);
	SDL_FreeSurface(core->text_surface);
	core->text_surface = NULL;
}

void	ft_delete_status_top(t_core *core, \
			SDL_Rect *rect, char *slogan, int status)
{
	if (SDL_FillRect(core->screen_surface, rect, core->game_fon) < 0)
		ft_error();
	if (status && ft_strlen(slogan) > 23)
	{
		rect->y += 30;
		if (SDL_FillRect(core->screen_surface, rect, core->game_fon) < 0)
			ft_error();
	}
}

void	ft_delete_status_down(t_core *core, \
			SDL_Rect *rect, char *slogan, int status)
{
	if (SDL_FillRect(core->screen_surface, rect, core->game_fon) < 0)
		ft_error();
	if (status && ft_strlen(slogan) > 23)
	{
		rect->y -= 30;
		if (SDL_FillRect(core->screen_surface, rect, core->game_fon) < 0)
			ft_error();
	}
}
