/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_carriet.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 12:01:32 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/12 12:52:26 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void	ft_reget_col(SDL_Color col, int *mycol)
{
	*mycol = col.r * 0x10000 + col.g * 0x100 + col.b;
}

int		ft_delete_list(t_lis *list, t_core *core, t_vm *vm)
{
	t_lis *tmp;

	tmp = list;
	while (list)
	{
		ft_get_col(&core->text_color, core->game_fon);
		ft_reget_col(core->text_color, &core->col);
		ft_draw_wall(core, tmp->posi * 2);
		ft_find_owner_col(core, vm->arena_owner[tmp->posi], vm->max_pl);
		ft_draw_letter(core, tmp->posi * 2, vm);
		tmp = list->next;
		free(list);
		list = tmp;
	}
	list = NULL;
	return (0);
}

void	ft_draw_carriet_h(t_core *core)
{
	if (core->number_theme == 1)
		ft_get_col(&core->text_color, 0x000000);
	if (core->number_theme == 2)
		ft_get_col(&core->text_color, 0x989a9d);
}

int		ft_draw_carriet(t_core *core, t_vm *vm)
{
	t_car *car;
	t_lis *tmp;

	if (core->game->posi)
	{
		ft_delete_list(core->game->posi, core, vm);
		core->game->posi = NULL;
	}
	car = vm->car;
	while (car)
	{
		if (!(tmp = (t_lis *)malloc(sizeof(t_lis))))
			ft_sim_error(core);
		tmp->posi = car->position;
		tmp->next = core->game->posi;
		core->game->posi = tmp;
		ft_find_owner_col(core, vm->arena_owner[car->position], vm->max_pl);
		ft_reget_col(core->text_color, &core->col);
		ft_draw_wall(core, car->position * 2);
		ft_draw_carriet_h(core);
		ft_draw_letter(core, car->position * 2, vm);
		car = car->next;
	}
	return (0);
}

void	ft_draw_field_h(t_core *core, t_vm *vm, int num, SDL_Rect *rect)
{
	char *str;

	ft_get_symb(core, &str, 0);
	if (vm->arena_owner[num / 2] == 0)
		core->text_color.a = 60;
	if (SDL_FillRect(core->screen_surface, rect, core->game_fon))
		ft_error();
	if (!(core->text_surface = TTF_RenderText_Blended(core->font_field,
		(const char *)str, core->text_color)))
		ft_error_ttf();
	if (SDL_BlitScaled(core->text_surface, NULL, core->screen_surface, rect))
		ft_error();
	SDL_FreeSurface(core->text_surface);
	core->text_surface = NULL;
	ft_strdel(&str);
}
