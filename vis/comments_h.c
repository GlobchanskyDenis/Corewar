/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comments_h.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:49:19 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/12 12:52:14 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void	ft_load_comments_3(t_core *core)
{
	if (core->players_status[0])
	{
		if (!(core->player_info->pl1_comm =
			(char **)malloc(sizeof(char *) * 3)))
			ft_sim_error(core);
		ft_init_arr(core->player_info->pl1_comm);
		ft_load_i_comment(core, 3, 1);
	}
	if (core->players_status[1])
	{
		if (!(core->player_info->pl2_comm =
			(char **)malloc(sizeof(char *) * 3)))
			ft_sim_error(core);
		ft_init_arr(core->player_info->pl2_comm);
		ft_load_i_comment(core, 3, 2);
	}
}

void	ft_load_comments_31(t_core *core)
{
	if (core->players_status[2])
	{
		if (!(core->player_info->pl3_comm =
			(char **)malloc(sizeof(char *) * 3)))
			ft_sim_error(core);
		ft_init_arr(core->player_info->pl3_comm);
		ft_load_i_comment(core, 3, 3);
	}
	if (core->players_status[3])
	{
		if (!(core->player_info->pl4_comm =
			(char **)malloc(sizeof(char *) * 3)))
			ft_sim_error(core);
		ft_init_arr(core->player_info->pl4_comm);
		ft_load_i_comment(core, 3, 4);
	}
}

int		ft_other(t_core *core)
{
	SDL_Rect rect;
	SDL_Rect rect1;

	rect.x = 0;
	rect.y = 0;
	rect.w = 2000;
	rect.h = 1000;
	if (SDL_FillRect(core->screen_surface, &rect, 0x000000))
		ft_error(core);
	rect1.x = 930;
	rect1.y = 900;
	rect1.w = 140;
	rect1.h = 50;
	if (SDL_BlitSurface(core->strelochka, NULL, core->screen_surface,
		&rect1))
		ft_error(core);
	return (0);
}
