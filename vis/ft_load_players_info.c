/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_players_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 12:48:06 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/09 13:01:18 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void	ft_load_players_info_11(t_core *core)
{
	if (core->players_status[3])
	{
		if (!(core->player_info->pl4_name = ft_strdup("  i-go-go  ")))
			ft_sim_error(core);
		if (!(core->player_info->pl4_slogan = ft_strdup("i-go-go..shen'ki")))
			ft_sim_error(core);
	}
	ft_get_col(&core->player_info->pl1_col, 0xff335c);
	ft_get_col(&core->player_info->pl2_col, 0xb57900);
	ft_get_col(&core->player_info->pl3_col, 0xba66ff);
	ft_get_col(&core->player_info->pl4_col, 0x2effaf);
}

void	ft_load_players_info_1(t_core *core)
{
	if (core->players_status[0])
	{
		if (!(core->player_info->pl1_name = ft_strdup("    Knife    ")))
			ft_sim_error(core);
		if (!(core->player_info->pl1_slogan = ft_strdup("Wish to kill you <3")))
			ft_sim_error(core);
	}
	if (core->players_status[1])
	{
		if (!(core->player_info->pl2_name = ft_strdup("    BUD    ")))
			ft_sim_error(core);
		if (!(core->player_info->pl2_slogan = ft_strdup("I LOVE BUD!!!")))
			ft_sim_error(core);
	}
	if (core->players_status[2])
	{
		if (!(core->player_info->pl3_name = ft_strdup("    HEAD    ")))
			ft_sim_error(core);
		if (!(core->player_info->pl3_slogan = ft_strdup("where is my head?")))
			ft_sim_error(core);
	}
	ft_load_players_info_11(core);
}

void	ft_load_players_info_21(t_core *core)
{
	if (core->players_status[3])
	{
		if (!(core->player_info->pl4_name = ft_strdup("    Homer    ")))
			ft_sim_error(core);
		if (!(core->player_info->pl4_slogan = ft_strdup("    D'oh    ")))
			ft_sim_error(core);
	}
	ft_get_col(&core->player_info->pl1_col, 0x4649bd);
	ft_get_col(&core->player_info->pl2_col, 0x5526659);
	ft_get_col(&core->player_info->pl3_col, 0x521c59);
	ft_get_col(&core->player_info->pl4_col, 0x993366);
}

void	ft_load_players_info_2(t_core *core)
{
	if (core->players_status[0])
	{
		if (!(core->player_info->pl1_name = ft_strdup("     Don     ")))
			ft_sim_error(core);
		if (!(core->player_info->pl1_slogan = ft_strdup("Let's build a wall!")))
			ft_sim_error(core);
	}
	if (core->players_status[1])
	{
		if (!(core->player_info->pl2_name = ft_strdup("    Vovan    ")))
			ft_sim_error(core);
		if (!(core->player_info->pl2_slogan = ft_strdup("Ona ytonyla")))
			ft_sim_error(core);
	}
	if (core->players_status[2])
	{
		if (!(core->player_info->pl3_name = ft_strdup("    Kim 5+    ")))
			ft_sim_error(core);
		if (!(core->player_info->pl3_slogan = ft_strdup("I love CoreWar")))
			ft_sim_error(core);
	}
	ft_load_players_info_21(core);
}

int		ft_load_players_info(t_core *core, t_vm *vm)
{
	if (!(core->player_info = (t_player_info *)malloc(sizeof(t_player_info))))
		ft_sim_error(core);
	ft_init_players_info(core);
	if (core->number_theme == 1)
	{
		ft_load_players_info_1(core);
	}
	if (core->number_theme == 2)
	{
		ft_load_players_info_2(core);
	}
	if (core->number_theme == 3)
	{
		ft_load_players_info_3(core, vm);
		ft_get_col(&core->player_info->pl1_col, 0xe6e5e3);
		ft_get_col(&core->player_info->pl2_col, 0x89a9a9);
		ft_get_col(&core->player_info->pl3_col, 0x956249);
		ft_get_col(&core->player_info->pl4_col, 0x6885be);
	}
	return (0);
}
