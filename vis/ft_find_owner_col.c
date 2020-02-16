/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_owner_col.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:34:03 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/09 15:59:09 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void	ft_find_owner_col_hhh(t_core *core, int a)
{
	if (a == 1)
		ft_eql_col(&core->text_color, core->player_info->pl1_col);
	else if (a == 2)
		ft_eql_col(&core->text_color, core->player_info->pl2_col);
	else if (a == 3)
		ft_eql_col(&core->text_color, core->player_info->pl3_col);
	else if (a == 4)
		ft_eql_col(&core->text_color, core->player_info->pl4_col);
}

void	ft_find_owner_col_help(int pl, int *a)
{
	if (pl == 1)
		*a = 2;
	if (pl == 2)
		*a = 3;
	if (pl == 3)
		*a = 4;
}

void	ft_find_owner_col_hhhh(t_core *core, int *a, int pl)
{
	if (core->players_status[0] && (pl == 1))
		*a = 1;
	else if (!core->players_status[0])
		ft_find_owner_col_help(pl, a);
	else if (core->players_status[1] && pl == 2)
		*a = 2;
	else if (!core->players_status[1])
	{
		if (pl == 2)
			*a = 3;
		if (pl == 3)
			*a = 4;
	}
	else if (pl == 3)
	{
		if (core->players_status[2])
			*a = 3;
		else if (core->players_status[3])
			*a = 4;
	}
}

void	ft_find_owner_col_help_h(t_core *core, int *a)
{
	if (core->players_status[1])
		*a = 2;
	if (core->players_status[2])
		*a = 3;
	if (core->players_status[3])
		*a = 4;
}

int		ft_find_owner_col(t_core *core, short pl, short max_pl)
{
	int a;

	a = 0;
	if (pl == 0)
	{
		ft_get_col(&core->text_color, 0xb5b5b5);
		return (0);
	}
	ft_find_owner_col_hh(core, pl, &a, max_pl);
	if (max_pl == 2)
	{
		if (core->players_status[0] && (pl == 1))
			a = 1;
		else if (!core->players_status[0])
			ft_find_owner_col_h(core, pl, &a);
		else if (pl == 2)
			ft_find_owner_col_help_h(core, &a);
	}
	if (max_pl == 3)
		ft_find_owner_col_hhhh(core, &a, pl);
	ft_find_owner_col_hhh(core, a);
	return (a);
}
