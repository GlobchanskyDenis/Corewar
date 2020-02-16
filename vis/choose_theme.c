/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_theme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:10:20 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/13 19:33:27 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

int		ft_create_theme_rect(t_core *core)
{
	core->theme->rect0.x = 0;
	core->theme->rect0.y = 0;
	core->theme->rect0.w = core->screen_width;
	core->theme->rect0.h = core->screen_height;
	if (SDL_FillRect(core->screen_surface, &(core->theme->rect0), 0x2f7190) < 0)
		ft_error();
	core->theme->rect1.x = 700;
	core->theme->rect1.y = 300;
	core->theme->rect1.w = 600;
	core->theme->rect1.h = 100;
	core->theme->rect2.x = 700;
	core->theme->rect2.y = 500;
	core->theme->rect2.w = 600;
	core->theme->rect2.h = 100;
	core->theme->rect3.x = 700;
	core->theme->rect3.y = 700;
	core->theme->rect3.w = 600;
	core->theme->rect3.h = 100;
	return (0);
}

int		ft_create_theme_text(t_core *core)
{
	if (!(core->font_menu = TTF_OpenFont("./game/fonts/anu.ttf", 288)))
		ft_error_ttf();
	if (!(core->font_field = TTF_OpenFont("./game/fonts/18365.ttf", 288)))
		ft_error_ttf();
	if (!(core->font_name = TTF_OpenFont("./game/fonts/Amatic-Bold.ttf", 288)))
		ft_error_ttf();
	ft_text_theme(core, "Choose Theme:");
	ft_text_fight(core, 0);
	ft_text_inter(core, 0);
	ft_text_disco(core, 0);
	return (0);
}

int		ft_create_instruments(t_core *core)
{
	if (!(core->theme = (t_theme *)malloc(sizeof(t_theme))))
		ft_sim_error(core);
	ft_create_theme_rect(core);
	ft_create_theme_text(core);
	if (SDL_UpdateWindowSurface(core->window))
		ft_error(core);
	return (0);
}
