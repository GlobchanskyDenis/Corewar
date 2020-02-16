/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_players.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 12:37:08 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/09 12:45:28 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void	ft_load_players_1(t_core *core)
{
	if (!(core->players->pl1 = SDL_LoadBMP("./game/players_begin/t1_p1.bmp")))
		ft_error(core);
	if (!(core->players->pl1_sh =
		SDL_LoadBMP("/game/players_begin/t1_p1_sh.bmp")))
		ft_error(core);
	if (!(core->players->pl2 = SDL_LoadBMP("/game/players_begin/t1_p2.bmp")))
		ft_error(core);
	if (!(core->players->pl2_sh =
		SDL_LoadBMP("/game/players_begin/t1_p2_sh.bmp")))
		ft_error(core);
	if (!(core->players->pl3 = SDL_LoadBMP("/game/players_begin/t1_p3.bmp")))
		ft_error(core);
	if (!(core->players->pl3_sh =
		SDL_LoadBMP("/game/players_begin/t1_p3_sh.bmp")))
		ft_error(core);
	if (!(core->players->pl4 = SDL_LoadBMP("/game/players_begin/t1_p4.bmp")))
		ft_error(core);
	if (!(core->players->pl4_sh =
		SDL_LoadBMP("/game/players_begin/t1_p4_sh.bmp")))
		ft_error(core);
}

void	ft_load_players_2(t_core *core)
{
	if (!(core->players->pl1 = SDL_LoadBMP("./game/players_begin/t2_p1.bmp")))
		ft_error(core);
	if (!(core->players->pl1_sh =
		SDL_LoadBMP("./game/players_begin/t2_p1_sh.bmp")))
		ft_error(core);
	if (!(core->players->pl2 = SDL_LoadBMP("./game/players_begin/t2_p2.bmp")))
		ft_error(core);
	if (!(core->players->pl2_sh =
		SDL_LoadBMP("./game/players_begin/t2_p2_sh.bmp")))
		ft_error(core);
	if (!(core->players->pl3 = SDL_LoadBMP("./game/players_begin/t2_p3.bmp")))
		ft_error(core);
	if (!(core->players->pl3_sh =
		SDL_LoadBMP("./game/players_begin/t2_p3_sh.bmp")))
		ft_error(core);
	if (!(core->players->pl4 = SDL_LoadBMP("./game/players_begin/t2_p4.bmp")))
		ft_error(core);
	if (!(core->players->pl4_sh =
		SDL_LoadBMP("./game/players_begin/t2_p4_sh.bmp")))
		ft_error(core);
}

void	ft_load_players_3(t_core *core)
{
	if (!(core->players->pl1 = SDL_LoadBMP("./game/players_begin/t3_p1.bmp")))
		ft_error(core);
	if (!(core->players->pl1_sh =
		SDL_LoadBMP("./game/players_begin/t3_p1_sh.bmp")))
		ft_error(core);
	if (!(core->players->pl2 = SDL_LoadBMP("./game/players_begin/t3_p2.bmp")))
		ft_error(core);
	if (!(core->players->pl2_sh =
		SDL_LoadBMP("./game/players_begin/t3_p2_sh.bmp")))
		ft_error(core);
	if (!(core->players->pl3 = SDL_LoadBMP("./game/players_begin/t3_p3.bmp")))
		ft_error(core);
	if (!(core->players->pl3_sh =
		SDL_LoadBMP("./game/players_begin/t3_p3_sh.bmp")))
		ft_error(core);
	if (!(core->players->pl4 = SDL_LoadBMP("./game/players_begin/t3_p4.bmp")))
		ft_error(core);
	if (!(core->players->pl4_sh =
		SDL_LoadBMP("./game/players_begin/t3_p4_sh.bmp")))
		ft_error(core);
}

int		ft_load_players(t_core *core)
{
	if (!(core->players = (t_players *)malloc(sizeof(t_players))))
		ft_sim_error(core);
	ft_init_players(core);
	if (!(core->strelochka = SDL_LoadBMP("./game/winner/strelochka.bmp")))
		ft_error(core);
	if (!(core->winner_frame = SDL_LoadBMP("./game/winner/winner.bmp")))
		ft_error(core);
	if (core->number_theme == 1)
		ft_load_players_1(core);
	if (core->number_theme == 2)
		ft_load_players_2(core);
	if (core->number_theme == 3)
		ft_load_players_3(core);
	return (0);
}
