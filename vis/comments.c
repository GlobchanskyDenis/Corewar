/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comments.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 12:45:36 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/09 17:27:25 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void	ft_load_comments_11(t_core *core)
{
	if (core->players_status[2])
	{
		if (!(core->player_info->pl3_comm =
			(char **)malloc(sizeof(char *) * 3)))
			ft_sim_error(core);
		ft_init_arr(core->player_info->pl3_comm);
		ft_load_i_comment(core, 1, 3);
	}
	if (core->players_status[3])
	{
		if (!(core->player_info->pl4_comm =
			(char **)malloc(sizeof(char *) * 3)))
			ft_sim_error(core);
		ft_init_arr(core->player_info->pl4_comm);
		ft_load_i_comment(core, 1, 4);
	}
}

void	ft_load_comments_1(t_core *core)
{
	if (core->players_status[0])
	{
		if (!(core->player_info->pl1_comm =
			(char **)malloc(sizeof(char *) * 3)))
			ft_sim_error(core);
		ft_init_arr(core->player_info->pl1_comm);
		ft_load_i_comment(core, 1, 1);
	}
	if (core->players_status[1])
	{
		if (!(core->player_info->pl2_comm =
			(char **)malloc(sizeof(char *) * 3)))
			ft_sim_error(core);
		ft_init_arr(core->player_info->pl2_comm);
		ft_load_i_comment(core, 1, 2);
	}
	ft_load_comments_11(core);
}

void	ft_load_comments_2(t_core *core)
{
	if (core->players_status[0])
	{
		if (!(core->player_info->pl1_comm =
			(char **)malloc(sizeof(char *) * 3)))
			ft_sim_error(core);
		ft_init_arr(core->player_info->pl1_comm);
		ft_load_i_comment(core, 2, 1);
	}
	if (core->players_status[1])
	{
		if (!(core->player_info->pl2_comm =
			(char **)malloc(sizeof(char *) * 3)))
			ft_sim_error(core);
		ft_init_arr(core->player_info->pl2_comm);
		ft_load_i_comment(core, 2, 2);
	}
}

void	ft_load_comments_21(t_core *core)
{
	if (core->players_status[2])
	{
		if (!(core->player_info->pl3_comm =
			(char **)malloc(sizeof(char *) * 3)))
			ft_sim_error(core);
		ft_init_arr(core->player_info->pl3_comm);
		ft_load_i_comment(core, 2, 3);
	}
	if (core->players_status[3])
	{
		if (!(core->player_info->pl4_comm =
			(char **)malloc(sizeof(char *) * 3)))
			ft_sim_error(core);
		ft_init_arr(core->player_info->pl4_comm);
		ft_load_i_comment(core, 2, 4);
	}
}

int		ft_load_comments(t_core *core)
{
	if (core->number_theme == 1)
		ft_load_comments_1(core);
	if (core->number_theme == 2)
	{
		ft_load_comments_2(core);
		ft_load_comments_21(core);
	}
	if (core->number_theme == 3)
	{
		ft_load_comments_3(core);
		ft_load_comments_31(core);
	}
	return (0);
}
