/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_players_hh.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 12:28:01 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/12 12:51:56 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

int		ft_cmp_vm(t_core *core, t_vm *vm, int orig)
{
	if (ft_find_owner_col(core, 1, vm->max_pl) == orig)
		return (0);
	else if (ft_find_owner_col(core, 2, vm->max_pl) == orig)
		return (1);
	else if (ft_find_owner_col(core, 3, vm->max_pl) == orig)
		return (2);
	else if (ft_find_owner_col(core, 4, vm->max_pl) == orig)
		return (3);
	return (0);
}

void	ft_get_col(SDL_Color *col, int mycol)
{
	col->r = mycol / 0x10000;
	col->g = (mycol / 0x100) % 0x100;
	col->b = mycol % 0x100;
}

int		ft_fill_players_array(t_core *core, int a, int b)
{
	if (core->players_status[0] != 2)
		core->players_status[0] = a / 10;
	if (core->players_status[1] != 2)
		core->players_status[1] = a % 10;
	if (core->players_status[2] != 2)
		core->players_status[2] = b / 10;
	if (core->players_status[3] != 2)
		core->players_status[3] = b % 10;
	return (0);
}

int		ft_present_players_help_h(t_core *core)
{
	if (core->players_status[1] == 0)
	{
		if (SDL_BlitSurface(core->players->pl2_sh, NULL, core->screen_surface,
		&(core->theme->rect1)))
			ft_error(core);
	}
	else
	{
		if (SDL_BlitSurface(core->players->pl2, NULL,
			core->screen_surface, &(core->theme->rect1)))
			ft_error(core);
	}
	return (0);
}

int		ft_right_players_number(t_core *core)
{
	int i;
	int kol;

	i = 0;
	kol = 0;
	while (i < 4)
	{
		if (core->players_status[i] == 2)
			kol++;
		i++;
	}
	if (kol == core->number_players)
		return (1);
	else
		return (0);
}
