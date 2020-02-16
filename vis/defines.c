/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:04:49 by jmaynard          #+#    #+#             */
/*   Updated: 2020/02/15 15:47:49 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

int		ft_put_defines(t_core *core, t_vm *vm)
{
	core->game->cycle = vm->cw->cycle;
	core->game->processes = 0;
	core->game->cycle_to_die = vm->cw->cycles_to_die;
	core->game->cycle_delta = CYCLE_DELTA;
	core->game->nbr_live = vm->cw->lives_for_cycle;
	core->game->max_checks = MAX_CHECKS;
	core->game->status = 1;
	return (0);
}

int		ft_draw_word(t_core *core, char *str, SDL_Rect rect)
{
	if (core->number_theme == 1)
		ft_get_col(&core->text_color, 0xf53a18);
	if (core->number_theme == 2)
		ft_get_col(&core->text_color, 0x000000);
	if (core->number_theme == 3)
		ft_get_col(&core->text_color, 0x000000);
	if (!(core->text_surface = TTF_RenderText_Blended(core->font_menu, \
		(const char *)str, core->text_color)))
		ft_error_ttf();
	if (SDL_BlitScaled(core->text_surface, \
		NULL, core->screen_surface, &rect) < 0)
		ft_error();
	SDL_FreeSurface(core->text_surface);
	core->text_surface = NULL;
	return (0);
}

void	ft_defines(t_core *core, SDL_Rect *rect, char *s, int n)
{
	char	*str;
	char	*num;

	if (!(num = ft_itoa(n)))
		ft_sim_error();
	if (!(str = ft_strjoin(s, num)))
		ft_sim_error();
	if (SDL_FillRect(core->screen_surface, rect, core->game_fon) < 0)
		ft_error();
	ft_draw_word(core, str, *rect);
	ft_strdel(&str);
	ft_strdel(&num);
}

int		ft_draw_defines(t_core *core)
{
	SDL_Rect	rect;

	ft_get_col(&core->text_color, 0xf73a18);
	rect.x = 555;
	rect.y = 965;
	rect.w = 200;
	rect.h = 35;
	ft_defines(core, &rect, "Cycle: ", core->game->cycle);
	rect.x = 780;
	ft_defines(core, &rect, "Cycle to die: ", core->game->cycle_to_die);
	rect.x = 1015;
	ft_defines(core, &rect, "NBR live: ", core->game->nbr_live);
	rect.x = 1245;
	ft_defines(core, &rect, "Max checks: ", core->game->max_checks);
	return (0);
}
