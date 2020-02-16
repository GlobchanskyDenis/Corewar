/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_winner_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 20:17:53 by jmaynard          #+#    #+#             */
/*   Updated: 2020/02/11 20:21:50 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void	ft_find_h(char **str1, char **str2, char **str3, int theme)
{
	if (!(*str1 = strdup("./game/winner/t")))
		ft_sim_error();
	if (!(*str2 = ft_itoa(theme)))
		ft_sim_error();
	if (!(*str3 = ft_strjoin(*str1, *str2)))
		ft_sim_error();
	ft_strdel(str1);
	ft_strdel(str2);
	if (!(*str1 = ft_strdup("_p")))
		ft_sim_error();
	if (!(*str2 = ft_strjoin(*str3, *str1)))
		ft_sim_error();
	ft_strdel(str1);
	ft_strdel(str3);
}

int		ft_find_winner_file(char **str, int theme, int pl)
{
	char *str1;
	char *str2;
	char *str3;

	ft_find_h(&str1, &str2, &str3, theme);
	if (!(str1 = ft_itoa(pl)))
		ft_sim_error();
	if (!(str3 = ft_strjoin(str2, str1)))
		ft_sim_error();
	ft_strdel(&str1);
	ft_strdel(&str2);
	if (!(str1 = ft_strdup(".bmp")))
		ft_sim_error();
	if (!(*str = ft_strjoin(str3, str1)))
		ft_sim_error();
	ft_strdel(&str1);
	ft_strdel(&str3);
	return (0);
}
