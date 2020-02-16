/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplitestsep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstokes <jstokes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:04:57 by jstokes           #+#    #+#             */
/*   Updated: 2020/02/13 18:21:16 by jstokes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	**get_mem(char **tmp)
{
	size_t	i;
	char	**improved;

	i = 0;
	while (tmp[i])
		i++;
	if (!(improved = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = -1;
	while (tmp[++i])
		if (!(improved[i] = ft_strnew(ft_strlen(tmp[i]))))
		{
			improved[i] = NULL;
			ft_strsplitdel(&improved);
		}
	improved[i] = NULL;
	return (improved);
}

static char	**improved_mem(char **tmp)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	**improved;

	if (!(improved = get_mem(tmp)))
		return (NULL);
	i = -1;
	while (improved[++i])
	{
		str = skip_sp_tab(tmp[i]);
		j = 0;
		if (*str == '%')
		{
			improved[i][j++] = *str;
			str = skip_sp_tab(str + 1);
		}
		if (*str == ':')
		{
			improved[i][j++] = *str;
			str = skip_sp_tab(str + 1);
		}
		ft_strncpy(improved[i] + j, str, ft_strlen(str));
	}
	return (improved);
}

char		**strsplitestsep(char *str)
{
	char	**tmp;
	char	**improved;

	if (!(tmp = ft_strsplit(str, SEPARATOR_CHAR)))
		return (NULL);
	if (!(improved = improved_mem(tmp)))
	{
		ft_strsplitdel(&tmp);
		return (NULL);
	}
	ft_strsplitdel(&tmp);
	return (improved);
}
