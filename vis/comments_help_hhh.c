/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comments_help_hhh.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:22:03 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/15 15:46:51 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

int		ft_find_local_end(char **comment, t_core *core)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*comment) && (i < (int)ft_strlen(*comment)))
	{
		if (((*comment)[i] == '\0') ||
			((*comment)[i] == ' ' && i >= 7 && i < 10) || (i == 10))
		{
			if ((*comment)[i] == '\0')
			{
				ft_strdel(comment);
				return (0);
			}
			else
			{
				tmp = ft_cpy_comment(comment, i, core);
				ft_strdel(&tmp);
			}
			i = 0;
		}
		i++;
	}
	return (0);
}

void	ft_rect_for_text(SDL_Rect *rect_text, SDL_Rect rect, int num)
{
	(*rect_text).w = 150 - 5 - 5;
	(*rect_text).h = 150 - 5 - 5;
	(*rect_text).x = rect.x + 5;
	if (num == 1 || num == 3)
	{
		(*rect_text).y = rect.y + 5;
	}
	if (num == 2 || num == 4)
	{
		(*rect_text).y = rect.y + 10 + 5;
	}
}

void	ft_load_i_comment_h(t_core *core, int i, int pl, char *str)
{
	if (pl == 1)
	{
		if (!(core->player_info->pl1_comm[i] = ft_strdup(str)))
			ft_sim_error(core);
	}
	else if (pl == 2)
	{
		if (!(core->player_info->pl2_comm[i] = ft_strdup(str)))
			ft_sim_error(core);
	}
	else if (pl == 3)
	{
		if (!(core->player_info->pl3_comm[i] = ft_strdup(str)))
			ft_sim_error(core);
	}
	else if (pl == 4)
	{
		if (!(core->player_info->pl4_comm[i] = ft_strdup(str)))
			ft_sim_error(core);
	}
}

int		ft_load_i_comment(t_core *core, int theme, int pl)
{
	int		fd;
	char	*file_name;
	char	*str;
	int		tr;
	int		i;

	ft_create_file_name_theme(&file_name, theme, pl, core);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		ft_sim_error(core);
	i = 0;
	while ((tr = get_next_line(fd, &str)) > 0)
	{
		ft_load_i_comment_h(core, i, pl, str);
		i++;
		ft_strdel(&str);
	}
	ft_strdel(&file_name);
	if (close(fd) == -1)
		ft_sim_error(core);
	return (0);
}
