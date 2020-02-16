/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present_status.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:41:11 by jmaynard          #+#    #+#             */
/*   Updated: 2020/02/12 11:36:43 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

int		ft_present_status_h(t_core *core)
{
	SDL_Rect rect;

	rect.w = 220;
	rect.h = 30;
	rect.x = core->theme->rect1.x - 35;
	rect.y = core->theme->rect1.y - 30 - 30 - 5 - 5;
	if (core->status_status[1] && core->players_status[1] \
			&& core->player_info->pl2_slogan[0] != '\0')
		ft_print_status_down(core, &rect, \
				core->player_info->pl2_col, core->player_info->pl2_slogan);
	else if (!core->status_status[1] && core->players_status[1])
		ft_delete_status_down(core, &rect, \
				core->player_info->pl2_slogan, core->players_status[1]);
	rect.x = core->theme->rect3.x - 33;
	rect.y = core->theme->rect3.y - 30 - 30 - 5 - 5;
	if (core->status_status[3] && core->players_status[3] \
			&& core->player_info->pl4_slogan[0] != '\0')
		ft_print_status_down(core, &rect, \
				core->player_info->pl4_col, core->player_info->pl4_slogan);
	else if (!core->status_status[3] && core->players_status[3])
		ft_delete_status_down(core, &rect, \
				core->player_info->pl4_slogan, core->players_status[3]);
	return (0);
}

int		ft_present_status(t_core *core)
{
	SDL_Rect	rect;

	rect.x = core->theme->rect0.x - 35;
	rect.y = core->theme->rect0.y + 150 + 30 + 5 + 5;
	rect.w = 220;
	rect.h = 30;
	if (core->status_status[0] && core->players_status[0] \
			&& core->player_info->pl1_slogan[0] != '\0')
		ft_print_status_top(core, &rect, \
				core->player_info->pl1_col, core->player_info->pl1_slogan);
	else if (!core->status_status[0] && core->players_status[0])
		ft_delete_status_top(core, &rect, \
			core->player_info->pl1_slogan, core->players_status[0]);
	rect.x = core->theme->rect2.x - 33;
	rect.y = core->theme->rect2.y + 150 + 30 + 5 + 5;
	if (core->status_status[2] && core->players_status[2] \
			&& core->player_info->pl3_slogan[0] != '\0')
		ft_print_status_top(core, &rect, \
				core->player_info->pl3_col, core->player_info->pl3_slogan);
	else if (!core->status_status[2] && core->players_status[2])
		ft_delete_status_top(core, &rect, \
			core->player_info->pl3_slogan, core->players_status[2]);
	return (ft_present_status_h(core));
}
