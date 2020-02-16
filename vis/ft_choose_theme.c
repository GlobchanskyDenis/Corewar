/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_theme.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 13:40:33 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/09 13:58:03 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

int		ft_choose_theme_1(t_core *core)
{
	if ((core->event.button.x >= 700 && core->event.button.x <= 1300) &&
		(core->event.button.y >= 300 && core->event.button.y <= 400))
	{
		ft_text_fight(core, 1);
		ft_text_inter(core, 2);
		ft_text_disco(core, 2);
		if (SDL_UpdateWindowSurface(core->window))
			ft_error(core);
		core->game_fon = 0x0b2852;
		core->number_theme = 1;
		core->status = 1;
		return (0);
	}
	return (1);
}

int		ft_choose_theme_2(t_core *core)
{
	if ((core->event.button.x >= 700 && core->event.button.x <= 1300) &&
		(core->event.button.y >= 500 && core->event.button.y <= 600))
	{
		ft_text_fight(core, 2);
		ft_text_inter(core, 1);
		ft_text_disco(core, 2);
		if (SDL_UpdateWindowSurface(core->window))
			ft_error(core);
		core->game_fon = 0xb079b0;
		core->number_theme = 2;
		core->status = 1;
		return (0);
	}
	return (1);
}

int		ft_choose_theme_3(t_core *core)
{
	if ((core->event.button.x >= 700 && core->event.button.x <= 1300) &&
		(core->event.button.y >= 700 && core->event.button.y <= 800))
	{
		ft_text_fight(core, 2);
		ft_text_inter(core, 2);
		ft_text_disco(core, 1);
		if (SDL_UpdateWindowSurface(core->window))
			ft_error(core);
		core->game_fon = 0xbabaff;
		core->number_theme = 3;
		core->status = 1;
		return (0);
	}
	return (1);
}

int		ft_choose_theme(t_core *core)
{
	while (1)
	{
		if ((SDL_PollEvent(&(core->event)) != 0))
		{
			if ((core->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) ||
				(core->event.type == SDL_QUIT))
				return (1);
			if (core->event.button.button == SDL_BUTTON_LEFT)
			{
				if (ft_choose_theme_1(core) == 0)
					return (0);
				if (ft_choose_theme_2(core) == 0)
					return (0);
				if (ft_choose_theme_3(core) == 0)
					return (0);
			}
		}
	}
	return (0);
}
