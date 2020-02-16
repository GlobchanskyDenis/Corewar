/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 21:15:20 by jmaynard          #+#    #+#             */
/*   Updated: 2020/02/11 21:17:36 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void	ft_delete_players_sh(t_core *core)
{
	if (core->players->pl1_sh)
	{
		SDL_FreeSurface(core->players->pl1_sh);
		core->players->pl1_sh = NULL;
	}
	if (core->players->pl2_sh)
	{
		SDL_FreeSurface(core->players->pl2_sh);
		core->players->pl2_sh = NULL;
	}
	if (core->players->pl3_sh)
	{
		SDL_FreeSurface(core->players->pl3_sh);
		core->players->pl3_sh = NULL;
	}
	if (core->players->pl4_sh)
	{
		SDL_FreeSurface(core->players->pl4_sh);
		core->players->pl4_sh = NULL;
	}
}

void	ft_delete_players(t_core *core)
{
	if (!core->players)
		return ;
	if (core->players->pl1)
	{
		SDL_FreeSurface(core->players->pl1);
		core->players->pl1 = NULL;
	}
	if (core->players->pl2)
	{
		SDL_FreeSurface(core->players->pl2);
		core->players->pl2 = NULL;
	}
	if (core->players->pl3)
	{
		SDL_FreeSurface(core->players->pl3);
		core->players->pl3 = NULL;
	}
	if (core->players->pl4)
	{
		SDL_FreeSurface(core->players->pl4);
		core->players->pl4 = NULL;
	}
	ft_delete_players_sh(core);
}

void	ft_free_arr(char **arr)
{
	int i;

	i = 0;
	while (i < 3)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
}

void	ft_list_del(t_lis *list)
{
	t_lis *tmp;

	tmp = list;
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	list = NULL;
}
