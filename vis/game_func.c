/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:34:03 by jmaynard          #+#    #+#             */
/*   Updated: 2020/02/12 12:37:37 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

int		ft_copy(short **mas1, short *mas2)
{
	int i;

	*mas1 = (short *)malloc(sizeof(short) * MEM_SIZE);
	i = 0;
	while (i < MEM_SIZE)
	{
		(*mas1)[i] = mas2[i];
		i++;
	}
	return (0);
}

void	ft_game_cycle(t_core *core, t_vm *vm, t_corewar *cw)
{
	if ((core->game->status == 1) || (core->game->status == -1))
	{
		if (core->game->status == 1)
		{
			if (core->game->prev_owner)
				free(core->game->prev_owner);
			ft_copy(&core->game->prev_owner, vm->arena_owner);
		}
		if (vm->flag & FLAG_DUMP && vm->dump <= cw->cycle)
			dump(vm);
		cw->cycle++;
		if (vm->flag & FLAG_LOG)
			fprint("It is now cycle %d\n", (int)cw->cycle);
		exe_carriages(vm);
		if (cw->cycle == cw->next_check || cw->cycles_to_die <= 0)
			cycles_to_die_check(vm);
	}
}

void	ft_see_defines(t_core *core, t_vm *vm)
{
	if (core->game->status == 1)
	{
		ft_put_defines(core, vm);
		ft_draw_defines(core);
	}
}

void	ft_see_field(t_core *core, t_vm *vm)
{
	if (core->game->status == 1)
	{
		ft_put_field(core, vm);
		ft_draw_field(core, vm, 0);
		ft_draw_carriet(core, vm);
	}
}

void	ft_see_comment(t_core *core, int *schet)
{
	if (core->game->status == 1)
	{
		(*schet)++;
		if (*schet == 350)
		{
			ft_change_comment(core);
			*schet = 0;
		}
	}
}
