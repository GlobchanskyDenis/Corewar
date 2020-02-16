/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:06:23 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/11 21:12:33 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void	ft_frst_while(t_core *core, int *quit)
{
	while ((*quit) && core->status == 0)
	{
		if ((core->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			|| (core->event.type == SDL_QUIT))
		{
			*quit = 0;
			break ;
		}
		if (ft_choose_theme(core) == 1)
			*quit = 0;
	}
	if (*quit)
		SDL_Delay(1000);
}

void	ft_scnd_while(t_core *core, int *quit)
{
	while ((*quit) && core->status == 1)
	{
		if ((core->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			|| (core->event.type == SDL_QUIT))
		{
			*quit = 0;
			break ;
		}
		if (ft_choose_players(core) == 1)
			*quit = 0;
	}
	ft_delete_players(core);
	if (*quit)
		SDL_Delay(1000);
}

void	ft_trd_while(t_core *core, t_vm *vm, int *quit)
{
	while ((*quit) && core->status == 2)
	{
		if ((core->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			|| (core->event.type == SDL_QUIT))
		{
			*quit = 0;
			break ;
		}
		if (ft_game(core, vm) == 1)
			*quit = 0;
	}
	if ((*quit) && core->game)
		core->game->status = 8;
}

void	ft_last_while(t_core *core, t_vm *vm, int *quit)
{
	while ((*quit) && core->status == 3)
	{
		if ((core->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			|| (core->event.type == SDL_QUIT))
		{
			*quit = 0;
			break ;
		}
		if (ft_end_game(core, vm) == 1)
			*quit = 0;
	}
}

int		main_vis(t_vm *vm)
{
	t_core	*core;
	int		quit;

	if (!(core = (t_core *)malloc(sizeof(t_core))))
		ft_sim_error();
	ft_empty_core(core);
	ft_init_core(core, vm);
	quit = 1;
	ft_create_instruments(core);
	ft_frst_while(core, &quit);
	ft_scnd_while(core, &quit);
	ft_trd_while(core, vm, &quit);
	ft_last_while(core, vm, &quit);
	ft_free_core(core);
	SDL_Quit();
	TTF_Quit();
	return (0);
}
