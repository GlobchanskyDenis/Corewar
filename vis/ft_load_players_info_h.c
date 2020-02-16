/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_players_info_h.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 12:56:26 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/09 12:59:22 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void	ft_load_players_info_31(t_core *core, t_vm *vm)
{
	t_pl player;

	if (core->players_status[2])
	{
		player = vm->player[ft_cmp_vm(core, vm, 3)];
		if (!(core->player_info->pl3_name = ft_strdup(player.name)))
			ft_sim_error(core);
		if (!(core->player_info->pl3_slogan = ft_strdup(player.comment)))
			ft_sim_error(core);
	}
	if (core->players_status[3])
	{
		player = vm->player[ft_cmp_vm(core, vm, 4)];
		if (!(core->player_info->pl4_name = ft_strdup(player.name)))
			ft_sim_error(core);
		if (!(core->player_info->pl4_slogan = ft_strdup(player.comment)))
			ft_sim_error(core);
	}
}

void	ft_load_players_info_3(t_core *core, t_vm *vm)
{
	t_pl player;

	if (core->players_status[0])
	{
		player = vm->player[ft_cmp_vm(core, vm, 1)];
		if (!(core->player_info->pl1_name = ft_strdup(player.name)))
			ft_sim_error(core);
		if (!(core->player_info->pl1_slogan = ft_strdup(player.comment)))
			ft_sim_error(core);
	}
	if (core->players_status[1])
	{
		player = vm->player[ft_cmp_vm(core, vm, 2)];
		if (!(core->player_info->pl2_name = ft_strdup(player.name)))
			ft_sim_error(core);
		if (!(core->player_info->pl2_slogan = ft_strdup(player.comment)))
			ft_sim_error(core);
	}
	ft_load_players_info_31(core, vm);
}
