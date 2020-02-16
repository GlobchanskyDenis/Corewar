/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:07:35 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/12 12:52:47 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void	ft_free_game(t_core *core)
{
	if (core->game->field)
		ft_strdel((char **)(&core->game->field));
	if (core->game->prev_field)
		ft_strdel((char **)(&core->game->prev_field));
	if (core->game->prev_owner)
		free(core->game->prev_owner);
	if (core->game->posi)
		ft_list_del(core->game->posi);
}

void	ft_free_font(t_core *core)
{
	if (core->font_menu)
	{
		TTF_CloseFont(core->font_menu);
		core->font_menu = NULL;
	}
	if (core->font_field)
	{
		TTF_CloseFont(core->font_field);
		core->font_field = NULL;
	}
	if (core->font_name)
	{
		TTF_CloseFont(core->font_name);
		core->font_name = NULL;
	}
}

void	ft_free_images(t_core *core)
{
	if (core->strelochka)
		SDL_FreeSurface(core->strelochka);
	if (core->winner_frame)
		SDL_FreeSurface(core->winner_frame);
	if (core->winner)
		SDL_FreeSurface(core->winner);
	ft_free_font(core);
	if (core->window)
		SDL_DestroyWindow(core->window);
	if (core->players)
	{
		ft_delete_players(core);
		free(core->players);
		core->players = NULL;
	}
}

void	ft_free_core(t_core *core)
{
	if (!core)
		return ;
	if (core->text_surface)
		SDL_FreeSurface(core->text_surface);
	if (core->screen_surface)
		SDL_FreeSurface(core->screen_surface);
	ft_free_images(core);
	if (core->theme)
	{
		free(core->theme);
		core->theme = NULL;
	}
	if (core->player_info)
		ft_free_player_info(core);
	if (core->game)
		ft_free_game(core);
	if (core->players_status)
		free(core->players_status);
	if (core->status_status)
		free(core->status_status);
}
