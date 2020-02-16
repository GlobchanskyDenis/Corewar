/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comments_help_hh.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:11:53 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/15 15:46:32 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void	ft_delete_prev_comm_h(t_core *core, int j)
{
	SDL_Rect rect;

	if (j / 10 == 3)
	{
		ft_find_rect_sq(core, &rect, 3);
		if (SDL_FillRect(core->screen_surface, &rect, core->game_fon))
			ft_error(core);
	}
	if (j / 10 == 4)
	{
		ft_find_rect_sq(core, &rect, 4);
		if (SDL_FillRect(core->screen_surface, &rect, core->game_fon))
			ft_error(core);
	}
}

int		ft_delete_prev_comm(t_core *core, int j)
{
	SDL_Rect rect;

	if (j / 10 == 1)
	{
		ft_find_rect_sq(core, &rect, 1);
		if (SDL_FillRect(core->screen_surface, &rect, core->game_fon))
			ft_error(core);
	}
	if (j / 10 == 2)
	{
		ft_find_rect_sq(core, &rect, 2);
		if (SDL_FillRect(core->screen_surface, &rect, core->game_fon))
			ft_error(core);
	}
	ft_delete_prev_comm_h(core, j);
	return (0);
}

void	ft_cpy_comment_h(int *i, char **comment, int new_len, char **tmp)
{
	int j;

	j = 0;
	while (j < new_len)
	{
		(*tmp)[j] = (*comment)[*i + 1];
		j++;
		(*i)++;
	}
	(*tmp)[j] = '\0';
}

char	*ft_cpy_comment(char **comment, int i, t_core *core)
{
	int		j;
	int		len;
	char	*tmp;
	char	*t_tmp;

	len = ft_strlen(*comment);
	if (!(tmp = (char *)malloc(sizeof(char) * (len - i - 1 + 1))))
		ft_sim_error(core);
	if (!(t_tmp = (char *)malloc(sizeof(char) * (i + 2))))
		ft_sim_error(core);
	ft_cpy_comment_h(&i, comment, len - i - 1, &tmp);
	j = 0;
	while (j < i + 1)
	{
		t_tmp[j] = (*comment)[j];
		j++;
	}
	t_tmp[j] = '\0';
	ft_strdel(comment);
	if (!(*comment = ft_strdup(tmp)))
		ft_sim_error(core);
	ft_strdel(&tmp);
	return (t_tmp);
}

int		ft_part_rect(SDL_Rect *r, SDL_Rect rect, int i, int count)
{
	i = 0;
	(*r).y = (*r).y + (rect.h - 10) / count;
	return (0);
}
