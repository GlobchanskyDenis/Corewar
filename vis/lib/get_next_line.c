/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 19:21:43 by volyvar-          #+#    #+#             */
/*   Updated: 2019/07/31 17:38:28 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_is_n(const char *str)
{
	int i;

	i = 0;
	if (str)
	{
		while ((*(str + i) != '\n') && (*(str + i) != '\0'))
			i++;
		if (*(str + i) == '\n')
			return (i);
	}
	return (-1);
}

int		ft_mem_del_n(char **str)
{
	char	*new_str;
	int		i;
	int		count;

	i = ft_is_n(*str);
	count = ft_strlen(*str);
	if ((i == -1) || ((i + 1) == count))
	{
		free(*str);
		*str = NULL;
		return (0);
	}
	if (!(new_str = ft_strsub(*str, i + 1, (size_t)(count - i))))
		return (-1);
	free(*str);
	*str = new_str;
	return (0);
}

int		ft_find_line(char **str, int *tr, const int fd)
{
	char *remember;
	char *tmp;

	while (((*str == NULL) || (ft_is_n(*str) == -1)) && (*tr != 0))
	{
		if (!(remember = (char *)(ft_strnew(BUFF_SIZE + 1))))
			return (-1);
		if ((*tr = read(fd, remember, BUFF_SIZE)) < 0)
			return (-1);
		ft_bzero(remember + *tr, BUFF_SIZE + 1 - (size_t)(*tr));
		if ((*str == NULL) && (*tr != 0))
		{
			if (!(*str = ft_strsub(remember, 0, *tr)))
				return (-1);
		}
		else if ((*str != NULL) && (*tr != 0))
		{
			if (!(tmp = ft_strjoin(*str, remember)))
				return (-1);
			free(*str);
			*str = tmp;
		}
		ft_strdel(&remember);
	}
	return (0);
}

int		ft_get_line(int tr, char **str, char **line)
{
	if ((tr == 0) && (ft_is_n(*str) == -1))
	{
		if (*str == NULL)
		{
			return (0);
		}
		if (*str != NULL)
		{
			if (!(*line = ft_strdup(*str)))
				return (-1);
			ft_strdel(str);
		}
	}
	if (ft_is_n(*str) != -1)
	{
		if (!(*line = ft_strsub(*str, 0, (size_t)ft_is_n(*str))))
			return (-1);
		if (ft_mem_del_n(str) == -1)
			return (-1);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int			tr;
	static char	**rem2;
	char		*tmp;

	tmp = NULL;
	if ((MAT_SIZE > 3000) || (MAT_SIZE <= 0) || (fd > MAT_SIZE))
		return (-1);
	if ((fd < 0) || (!line) || (BUFF_SIZE <= 0) || (read(fd, tmp, 0) < 0))
		return (-1);
	free(tmp);
	if (rem2 == NULL)
	{
		if (!(rem2 = (char **)malloc(sizeof(char *) * MAT_SIZE)))
			return (-1);
		tr = 0;
		while (tr < MAT_SIZE)
		{
			rem2[tr] = NULL;
			tr++;
		}
	}
	tr = -2;
	if (ft_find_line(&rem2[fd], &tr, fd) == -1)
		return (-1);
	return (ft_get_line(tr, &(rem2[fd]), line));
}
