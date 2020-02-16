/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present_winner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 14:57:05 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/15 19:42:57 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void	ft_print_half(t_core *core)
{
	SDL_Rect	rect;

	rect.x = 0;
	rect.y = 0;
	rect.w = 1000;
	rect.h = 1000;
	SDL_FillRect(core->screen_surface, &rect, 0x2f7190);
}

void	ft_print_winner(t_core *core, t_vm *vm)
{
	SDL_Rect	rect;
	char		*str;

	ft_find_winner_file(&str, core->number_theme, \
			ft_find_owner_col(core, core->l_alive - 1 + 1, vm->max_pl));
	if (!(core->winner = SDL_LoadBMP(str)))
		ft_error();
	rect.x = 250;
	rect.y = 250;
	rect.h = 500;
	rect.w = 500;
	if (SDL_BlitSurface(core->winner, \
			NULL, core->screen_surface, &rect) < 0)
		ft_error();
	rect.x = 100;
	rect.y = 120;
	rect.h = 800;
	rect.w = 800;
	if (SDL_BlitSurface(core->winner_frame, \
			NULL, core->screen_surface, &rect) < 0)
		ft_error();
	ft_strdel(&str);
}

void	ft_print_name(t_core *core, t_vm *vm, char **name)
{
	t_pl	player;
	char	*str;
	char	*trim;
	int		n;

	trim = NULL;
	player = vm->player[core->l_alive - 1];
	if (!(*name = ft_strdup(player.name)) ||
		!(str = ft_strjoin(*name, "   as   ")))
		ft_sim_error();
	ft_strdel(name);
	if ((n = ft_find_owner_col(core, core->l_alive - 1 + 1, vm->max_pl)) == 1)
		trim = ft_strtrim(core->player_info->pl1_name);
	else if (n == 2)
		trim = ft_strtrim(core->player_info->pl2_name);
	else if (n == 3)
		trim = ft_strtrim(core->player_info->pl3_name);
	else if (n == 4)
		trim = ft_strtrim(core->player_info->pl4_name);
	if (!trim)
		ft_sim_error();
	if (!(*name = ft_strjoin(str, trim)))
		ft_sim_error();
	ft_strdel(&trim);
	ft_strdel(&str);
}

int		ft_present_winner(t_core *core, t_vm *vm)
{
	char		*name;
	SDL_Rect	rect;

	ft_print_half(core);
	ft_print_winner(core, vm);
	ft_print_name(core, vm, &name);
	rect.x = 250;
	rect.y = 900;
	rect.w = 500;
	rect.h = 80;
	ft_get_col(&core->text_color, 0xffd500);
	if (!(core->text_surface = TTF_RenderText_Blended(core->font_name, \
			(const char *)name, core->text_color)))
		ft_error_ttf();
	if (SDL_BlitScaled(core->text_surface, \
			NULL, core->screen_surface, &rect) < 0)
		ft_error();
	SDL_FreeSurface(core->text_surface);
	core->text_surface = NULL;
	ft_strdel(&name);
	if (SDL_UpdateWindowSurface(core->window) < 0)
		ft_error();
	return (0);
}
