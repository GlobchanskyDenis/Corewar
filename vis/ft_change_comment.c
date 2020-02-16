/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_comment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:36:55 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/15 15:47:34 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void	ft_change_comment_h(t_core *core, int i)
{
	SDL_Rect	rect;
	SDL_Rect	rect_text;

	if (i / 10 == 3)
	{
		ft_find_rect_sq(core, &rect, 3);
		ft_eql_col(&core->text_color, core->player_info->pl3_col);
		if (SDL_BlitSurface(core->player_info->pic_com3,
			NULL, core->screen_surface, &(rect)))
			ft_error(core);
		ft_rect_for_text(&rect_text, rect, i / 10);
		ft_new_hope(core, rect_text, core->player_info->pl3_comm[(i % 10) - 1]);
	}
	if (i / 10 == 4)
	{
		ft_find_rect_sq(core, &rect, 4);
		if (SDL_BlitSurface(core->player_info->pic_com4,
			NULL, core->screen_surface, &(rect)))
			ft_error(core);
		ft_eql_col(&core->text_color, core->player_info->pl4_col);
		ft_rect_for_text(&rect_text, rect, i / 10);
		ft_new_hope(core, rect_text, core->player_info->pl4_comm[(i % 10) - 1]);
	}
}

void	ft_change_comment_hh(t_core *core, int i)
{
	SDL_Rect	rect;
	SDL_Rect	rect_text;

	if (i / 10 == 1)
	{
		ft_find_rect_sq(core, &rect, 1);
		if (SDL_BlitSurface(core->player_info->pic_com1,
			NULL, core->screen_surface, &(rect)))
			ft_error(core);
		ft_eql_col(&core->text_color, core->player_info->pl1_col);
		ft_rect_for_text(&rect_text, rect, i / 10);
		ft_new_hope(core, rect_text, core->player_info->pl1_comm[(i % 10) - 1]);
	}
	if (i / 10 == 2)
	{
		ft_find_rect_sq(core, &rect, 2);
		if (SDL_BlitSurface(core->player_info->pic_com2,
			NULL, core->screen_surface, &(rect)))
			ft_error(core);
		ft_eql_col(&core->text_color, core->player_info->pl2_col);
		ft_rect_for_text(&rect_text, rect, i / 10);
		ft_new_hope(core, rect_text, core->player_info->pl2_comm[(i % 10) - 1]);
	}
}

int		ft_change_comment(t_core *core)
{
	int			i;
	int			j;

	core->text_color.r = 0xf7;
	core->text_color.g = 0x3a;
	core->text_color.b = 0x18;
	i = ft_next_comm(core);
	j = ft_prev_comm(i, core);
	ft_delete_prev_comm(core, j);
	ft_change_comment_hh(core, i);
	ft_change_comment_h(core, i);
	return (0);
}
