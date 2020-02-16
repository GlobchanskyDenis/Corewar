/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_hope.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:30:33 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/15 15:49:10 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void	ft_new_hope_h(SDL_Rect *r, SDL_Rect rect, int count)
{
	(*r).x = rect.x + 3;
	(*r).y = 10 + rect.y - rect.h / count;
	(*r).w = rect.w - 10;
	(*r).h = (rect.h - 10) / count;
}

void	ft_new_hope(t_core *core, SDL_Rect rect, char *comment)
{
	int			count;
	int			i;
	char		*tmp;
	SDL_Rect	r;

	tmp = NULL;
	count = ft_strlen(comment) / 10 + 1;
	if (ft_strlen(comment) % 10 == 0)
		count--;
	ft_new_hope_h(&r, rect, count);
	i = -1;
	while (++i < count)
	{
		ft_part_com(core, &tmp, i, comment);
		ft_part_rect(&r, rect, i, count);
		if (!(core->text_surface =
			TTF_RenderText_Blended(core->font_name, tmp, core->text_color)))
			ft_error_ttf();
		if (SDL_BlitScaled(core->text_surface, \
			NULL, core->screen_surface, &(r)))
			ft_error(core);
		SDL_FreeSurface(core->text_surface);
		core->text_surface = NULL;
		ft_strdel(&tmp);
	}
}
