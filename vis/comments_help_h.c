/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comments_help_h.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:06:05 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/09 17:24:30 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

int		ft_prev_comm(int i, t_core *core)
{
	int j;

	j = 0;
	while (j == 0 || ft_is_ok(core, i) == 0)
	{
		j = 1;
		if (i / 10 > 1)
		{
			i = ((i / 10) - 1) * 10 + (i % 10);
		}
		else
		{
			if (i % 10 == 1)
			{
				i = 43;
			}
			else
			{
				i = 4 * 10 + (i % 10) - 1;
			}
		}
	}
	return (i);
}

int		ft_part_com(t_core *core, char **tmp, int i, char *comment)
{
	int j;
	int len;
	int ii;

	j = i * 10;
	len = 0;
	while (comment[j] != '\0' && j < (i * 10 + 10))
	{
		len++;
		j++;
	}
	if (!(*tmp = (char *)malloc(sizeof(char) * (len + 1))))
		ft_sim_error(core);
	ii = 0;
	j = i * 10;
	while (ii < len)
	{
		(*tmp)[ii] = comment[j];
		ii++;
		j++;
	}
	(*tmp)[ii] = '\0';
	return (0);
}

int		ft_create_file_name_theme(char **file, int theme, int pl, t_core *core)
{
	char *str;
	char *str1;
	char *str2;

	if (!(str = ft_itoa(theme)))
		ft_sim_error(core);
	if (!(str1 = ft_strjoin("theme", str)))
		ft_sim_error(core);
	ft_strdel(&str);
	if (!(str = ft_itoa(pl)))
		ft_sim_error(core);
	if (!(str2 = ft_strjoin(str1, "_pl")))
		ft_sim_error(core);
	ft_strdel(&str1);
	if (!(str1 = ft_strjoin(str2, str)))
		ft_sim_error(core);
	ft_strdel(&str);
	ft_strdel(&str2);
	if (!(str = ft_strjoin(str1, "_com")))
		ft_sim_error(core);
	if (!(*file = ft_strjoin("./game/comments/", str)))
		ft_sim_error(core);
	ft_strdel(&str);
	ft_strdel(&str1);
	return (0);
}

void	ft_init_arr(char **arr)
{
	int i;

	i = 0;
	while (i < 3)
	{
		arr[i] = NULL;
		i++;
	}
}

int		ft_load_pic_com(t_core *core)
{
	if (!(core->player_info->pic_com1 =
		SDL_LoadBMP("./game/com_pic/new_kom1.bmp")))
		ft_error(core);
	if (!(core->player_info->pic_com2 =
		SDL_LoadBMP("./game/com_pic/new_kom2.bmp")))
		ft_error(core);
	if (!(core->player_info->pic_com3 =
		SDL_LoadBMP("./game/com_pic/new_kom3.bmp")))
		ft_error(core);
	if (!(core->player_info->pic_com4 =
		SDL_LoadBMP("./game/com_pic/new_kom4.bmp")))
		ft_error(core);
	return (0);
}
