/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_player_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 21:19:42 by jmaynard          #+#    #+#             */
/*   Updated: 2020/02/11 21:26:07 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void	ft_free_str(t_core *core)
{
	if (core->player_info->pl1_name)
		ft_strdel(&core->player_info->pl1_name);
	if (core->player_info->pl2_name)
		ft_strdel(&core->player_info->pl2_name);
	if (core->player_info->pl3_name)
		ft_strdel(&core->player_info->pl3_name);
	if (core->player_info->pl4_name)
		ft_strdel(&core->player_info->pl4_name);
	if (core->player_info->pl1_slogan)
		ft_strdel(&core->player_info->pl1_slogan);
	if (core->player_info->pl2_slogan)
		ft_strdel(&core->player_info->pl2_slogan);
	if (core->player_info->pl3_slogan)
		ft_strdel(&core->player_info->pl3_slogan);
	if (core->player_info->pl4_slogan)
		ft_strdel(&core->player_info->pl4_slogan);
}

void	ft_free_com(t_core *core)
{
	if (core->player_info->pl1_comm)
	{
		ft_free_arr(core->player_info->pl1_comm);
		free(core->player_info->pl1_comm);
	}
	if (core->player_info->pl2_comm)
	{
		ft_free_arr(core->player_info->pl2_comm);
		free(core->player_info->pl2_comm);
	}
	if (core->player_info->pl3_comm)
	{
		ft_free_arr(core->player_info->pl3_comm);
		free(core->player_info->pl3_comm);
	}
	if (core->player_info->pl4_comm)
	{
		ft_free_arr(core->player_info->pl4_comm);
		free(core->player_info->pl4_comm);
	}
}

void	ft_free_player_info(t_core *core)
{
	ft_free_str(core);
	if (core->player_info->pic_com1)
		SDL_FreeSurface(core->player_info->pic_com1);
	if (core->player_info->pic_com2)
		SDL_FreeSurface(core->player_info->pic_com2);
	if (core->player_info->pic_com3)
		SDL_FreeSurface(core->player_info->pic_com3);
	if (core->player_info->pic_com4)
		SDL_FreeSurface(core->player_info->pic_com4);
	ft_free_com(core);
	free(core->player_info);
	core->player_info = NULL;
}
