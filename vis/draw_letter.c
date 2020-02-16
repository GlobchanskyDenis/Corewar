/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_letter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:29:53 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/15 15:44:29 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

int		ft_get_symb_n(t_core *core, char **str, int n)
{
	if (!(*str))
		ft_strdel(str);
	if (!(*str = (char *)malloc(sizeof(char) * 2)))
		ft_sim_error(core);
	(*str)[0] = (core->game->field)[n];
	(*str)[1] = '\0';
	return (0);
}

void	ft_draw_letter_h(SDL_Rect *rect, t_core *core, int n, t_vm *vm)
{
	int new_n;
	int x;
	int y;

	new_n = (n / 2) * 3 + (n % 2) + 1;
	y = 2 + (15) * (new_n / 192);
	x = 228 + 8 * (new_n % 192);
	(*rect).x = x;
	(*rect).y = y;
	(*rect).w = 6;
	(*rect).h = 13;
	core->text_color.a = 0;
	if (vm->arena_owner[n / 2] == 0)
		core->text_color.a = 60;
}

void	ft_draw_letter_hh(t_core *core, int n, SDL_Rect rect)
{
	char *str;

	ft_get_symb_n(core, &str, n);
	if (!(core->text_surface = TTF_RenderText_Blended(core->font_field,
		(const char *)str, core->text_color)))
		ft_error_ttf();
	if (SDL_BlitScaled(core->text_surface, NULL, core->screen_surface, &rect))
		ft_error(core);
	SDL_FreeSurface(core->text_surface);
	core->text_surface = NULL;
	ft_strdel(&str);
}

int		ft_draw_letter(t_core *core, int n, t_vm *vm)
{
	char		*str;
	SDL_Rect	rect;

	ft_draw_letter_h(&rect, core, n, vm);
	ft_draw_letter_hh(core, n, rect);
	core->text_color.a = 0;
	if (vm->arena_owner[n / 2] == 0)
		core->text_color.a = 60;
	rect.x += 8;
	ft_get_symb_n(core, &str, n + 1);
	if (!(core->text_surface = TTF_RenderText_Blended(core->font_field,
		(const char *)str, core->text_color)))
		ft_error_ttf();
	if (SDL_BlitScaled(core->text_surface, NULL, core->screen_surface, &rect))
		ft_error(core);
	SDL_FreeSurface(core->text_surface);
	core->text_surface = NULL;
	ft_strdel(&str);
	core->text_color.a = 0;
	return (0);
}

int		ft_draw_wall(t_core *core, int n)
{
	int			new_n;
	int			x;
	int			y;
	SDL_Rect	rect;

	new_n = (n / 2) * 3 + (n % 2) + 1;
	y = 2 + (15) * (new_n / 192);
	x = 228 + 8 * (new_n % 192);
	rect.x = x;
	rect.y = y;
	rect.w = 14;
	rect.h = 13;
	if (SDL_FillRect(core->screen_surface, &(rect), core->col))
		ft_error();
	return (0);
}
