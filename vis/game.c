/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:49:37 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/15 19:36:52 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void	ft_init_game(t_core *core, t_vm *vm, t_corewar *cw)
{
	*cw = initialize_variables(vm);
	vm->cw = cw;
	ft_game_fon(core, vm);
	ft_put_field(core, vm);
	ft_draw_field(core, vm, 0);
	ft_draw_carriet(core, vm);
}

void	ft_over(t_core *core, t_vm *vm, t_corewar cw)
{
	if (!vm->car)
	{
		fprint("Contestant %d, \"%s\", has won !\n", cw.last_alive, \
			vm->player[cw.last_alive - 1].name);
		core->status = 3;
	}
}

int		ft_game(t_core *core, t_vm *vm)
{
	static int		fl;
	int				schet;
	t_corewar		cw;
	int				a;

	if (fl == 0)
		ft_init_game(core, vm, &cw);
	fl = 1;
	a = 0;
	schet = 0;
	while (vm->car)
	{
		ft_game_cycle(core, vm, &cw);
		ft_see_defines(core, vm);
		ft_see_field(core, vm);
		ft_see_comment(core, &schet);
		if (SDL_PollEvent(&(core->event)) != 0)
			if (ft_game_event(core, vm, &a))
				return (1);
		if (core->game->status != -1)
			SDL_UpdateWindowSurface(core->window);
	}
	ft_over(core, vm, cw);
	core->l_alive = vm->cw->last_alive;
	return (0);
}
