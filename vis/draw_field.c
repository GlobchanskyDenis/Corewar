/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:32:03 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/12 12:52:31 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void	ft_draw_field_hh(t_core *core, t_vm *vm, int num, SDL_Rect *rect)
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

void	ft_draw_field_init(char **str, SDL_Rect *rect, int *num, int *pr)
{
	*str = NULL;
	(*rect).x = 228;
	(*rect).y = 2;
	(*rect).w = 6;
	(*rect).h = 13;
	*num = 0;
	*pr = 0;
}

int		ft_draw_field_if(t_core *core, t_vm *vm, int num, int flag)
{
	if ((core->game->prev_owner && (vm->arena_owner[num / 2]
		!= core->game->prev_owner[num / 2])) || (flag == 1) ||
		(!core->game->prev_field || (core->game->prev_field &&
		core->game->field[num] != core->game->prev_field[num])))
		return (1);
	return (0);
}

int		ft_draw_field_if1(t_core *core, t_vm *vm, int num, int flag)
{
	if ((core->game->prev_owner && (vm->arena_owner[num / 2]
		!= core->game->prev_owner[num / 2])) || (flag == 1) ||
		(!core->game->prev_field || (core->game->prev_field &&
		core->game->field[num + 1] != core->game->prev_field[num + 1])))
		return (1);
	return (0);
}

int		ft_draw_field(t_core *core, t_vm *vm, int flag)
{
	SDL_Rect	rect;
	char		*str;
	int			num;
	int			pr;

	ft_draw_field_init(&str, &rect, &num, &pr);
	while (num < MEM_SIZE * 2)
	{
		core->text_color.a = 0;
		ft_find_owner_col(core, vm->arena_owner[num / 2], vm->max_pl);
		ft_get_rect(&rect, 0);
		if (ft_draw_field_if(core, vm, num, flag))
			ft_draw_field_h(core, vm, num, &rect);
		core->text_color.a = 0;
		ft_get_rect(&rect, 0);
		if (ft_draw_field_if1(core, vm, num, flag))
			ft_draw_field_hh(core, vm, num, &rect);
		core->text_color.a = 0;
		num += 2;
		ft_get_rect(&rect, 0);
	}
	ft_get_symb(core, &str, 1);
	ft_get_rect(&rect, 1);
	return (0);
}
