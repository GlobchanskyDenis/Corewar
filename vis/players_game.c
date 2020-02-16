/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:38:37 by jmaynard          #+#    #+#             */
/*   Updated: 2020/02/12 12:53:07 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void	ft_put_players_name(t_core *core, SDL_Rect rect, int num, char *str)
{
	SDL_Rect new_rect;

	new_rect.x = rect.x - 35;
	if (num % 2 != 0)
		new_rect.y = rect.y + 5 + 150;
	else
		new_rect.y = rect.y - 35;
	new_rect.w = 220;
	new_rect.h = 30;
	if (num == 1)
		ft_eql_col(&core->text_color, core->player_info->pl1_col);
	if (num == 2)
		ft_eql_col(&core->text_color, core->player_info->pl2_col);
	if (num == 3)
		ft_eql_col(&core->text_color, core->player_info->pl3_col);
	if (num == 4)
		ft_eql_col(&core->text_color, core->player_info->pl4_col);
	if (!(core->text_surface = TTF_RenderText_Blended(core->font_name, \
		(const char *)str, core->text_color)))
		ft_error_ttf();
	if (SDL_BlitScaled(core->text_surface, NULL, \
		core->screen_surface, &new_rect) < 0)
		ft_error();
	SDL_FreeSurface(core->text_surface);
	core->text_surface = NULL;
}

void	ft_def_rects(t_core *core)
{
	core->theme->rect0.x = 35;
	core->theme->rect0.y = 200;
	core->theme->rect0.w = 150;
	core->theme->rect0.h = 150;
	core->theme->rect1.x = 35;
	core->theme->rect1.y = 600;
	core->theme->rect1.w = 150;
	core->theme->rect1.h = 150;
	core->theme->rect2.x = 1815;
	core->theme->rect2.y = 200;
	core->theme->rect2.w = 150;
	core->theme->rect2.h = 150;
	core->theme->rect3.x = 1815;
	core->theme->rect3.y = 600;
	core->theme->rect3.w = 150;
	core->theme->rect3.h = 150;
}

int		ft_put_players_h(t_core *core)
{
	if (core->players_status[2])
	{
		if (SDL_BlitSurface(core->players->pl3, NULL, \
				core->screen_surface, &(core->theme->rect2)) < 0)
			ft_error();
		ft_put_players_name(core, core->theme->rect2, \
			3, core->player_info->pl3_name);
	}
	if (core->players_status[3])
	{
		if (SDL_BlitSurface(core->players->pl4, NULL, \
				core->screen_surface, &(core->theme->rect3)) < 0)
			ft_error();
		ft_put_players_name(core, core->theme->rect3, \
			4, core->player_info->pl4_name);
	}
	return (0);
}

int		ft_put_players(t_core *core)
{
	ft_def_rects(core);
	if (core->players_status[0])
	{
		if (SDL_BlitSurface(core->players->pl1, NULL, \
				core->screen_surface, &(core->theme->rect0)) < 0)
			ft_error();
		ft_put_players_name(core, core->theme->rect0, \
			1, core->player_info->pl1_name);
	}
	if (core->players_status[1])
	{
		if (SDL_BlitSurface(core->players->pl2, NULL, \
				core->screen_surface, &(core->theme->rect1)) < 0)
			ft_error();
		ft_put_players_name(core, core->theme->rect1, \
			2, core->player_info->pl2_name);
	}
	return (ft_put_players_h(core));
}

int		ft_reload_players(t_core *core)
{
	if (core->number_theme == 1)
	{
		core->players->pl1 = SDL_LoadBMP("./game/players_game/t1_p1.bmp");
		core->players->pl2 = SDL_LoadBMP("./game/players_game/t1_p2.bmp");
		core->players->pl3 = SDL_LoadBMP("./game/players_game/t1_p3.bmp");
		core->players->pl4 = SDL_LoadBMP("./game/players_game/t1_p4.bmp");
	}
	if (core->number_theme == 2)
	{
		core->players->pl1 = SDL_LoadBMP("./game/players_game/t2_p1.bmp");
		core->players->pl2 = SDL_LoadBMP("./game/players_game/t2_p2.bmp");
		core->players->pl3 = SDL_LoadBMP("./game/players_game/t2_p3.bmp");
		core->players->pl4 = SDL_LoadBMP("./game/players_game/t2_p4.bmp");
	}
	if (core->number_theme == 3)
	{
		core->players->pl1 = SDL_LoadBMP("./game/players_game/t3_p1.bmp");
		core->players->pl2 = SDL_LoadBMP("./game/players_game/t3_p2.bmp");
		core->players->pl3 = SDL_LoadBMP("./game/players_game/t3_p3.bmp");
		core->players->pl4 = SDL_LoadBMP("./game/players_game/t3_p4.bmp");
	}
	if (!core->players->pl1 || !core->players->pl2 \
		|| !core->players->pl3 || !core->players->pl4)
		ft_error();
	return (0);
}
