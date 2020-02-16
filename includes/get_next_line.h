/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 19:22:42 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/13 20:41:13 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# define MAT_SIZE 3000
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

int		get_next_line(const int fd, char **line);
int		ft_find_line(char **str, int *tr, const int fd);
int		ft_get_line(int tr, char **str, char **line);

#endif
