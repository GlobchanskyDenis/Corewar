/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comments.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:36:51 by jstokes           #+#    #+#             */
/*   Updated: 2020/02/13 18:59:05 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	is_comment(char *str)
{
	if (str)
		if (*str == COMMENT_CHAR || *str == COMMENT_CHAR2)
			return (1);
	return (0);
}
