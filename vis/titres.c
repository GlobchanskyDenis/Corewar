/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   titres.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:14:37 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/12 12:53:20 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

int		ft_timer(int y)
{
	return (y - 10);
}

int		ft_draw_titre(t_core *core, int y, char *aut)
{
	SDL_Rect	rect;

	rect.x = 1300;
	rect.y = y;
	rect.w = 400;
	rect.h = 50;
	ft_get_col(&core->text_color, 0x5f010a);
	if (!(core->text_surface = TTF_RenderText_Blended(core->font_name, \
			(const char *)aut, core->text_color)))
		ft_error_ttf();
	if ((SDL_BlitScaled(core->text_surface, \
			NULL, core->screen_surface, &rect)) < 0)
		ft_error();
	SDL_FreeSurface(core->text_surface);
	core->text_surface = NULL;
	return (0);
}

int		ft_black_titre(t_core *core, int *y)
{
	SDL_Rect	rect;
	int			i;

	i = 0;
	while (i < 4)
	{
		rect.x = 1300;
		rect.y = y[i];
		rect.w = 400;
		rect.h = 50;
		if (y[i] <= 1000 - 50 - 15)
			if (SDL_FillRect(core->screen_surface, &rect, 0x000000) < 0)
				ft_error();
		i++;
	}
	return (0);
}

void	conditions(int *y, t_core *core, const int fin_y)
{
	if (y[0] > fin_y)
		y[0] = ft_timer(y[0]);
	if (y[0] <= 800 && y[1] > fin_y + 100)
		y[1] = ft_timer(y[1]);
	if (y[1] <= 800 && y[2] > fin_y + 200)
		y[2] = ft_timer(y[2]);
	if (y[2] <= 800)
		y[3] = ft_timer(y[3]);
	if (y[0] <= 1000 - 50 - 15)
		ft_draw_titre(core, y[0], "bsabre-c");
	if (y[1] <= 1000 - 50 - 15)
		ft_draw_titre(core, y[1], "jmaynard");
	if (y[2] <= 1000 - 50 - 15)
		ft_draw_titre(core, y[2], "jstokes");
	if (y[3] <= 1000 - 50 - 15)
		ft_draw_titre(core, y[3], "volyvar-");
}

int		ft_titres(t_core *core)
{
	int y[4];
	int fin_y;

	ft_draw_titre(core, 10, "authors:");
	fin_y = 320;
	core->game->status = 10;
	y[0] = 1000 - 50 - 10;
	y[1] = 1000 - 50 - 10;
	y[2] = 1000 - 50 - 10;
	y[3] = 1000 - 50 - 10;
	while (y[3] >= fin_y + 300)
	{
		ft_black_titre(core, y);
		conditions(y, core, fin_y);
		if (SDL_UpdateWindowSurface(core->window) < 0)
			ft_error();
		SDL_Delay(100);
	}
	return (0);
}
