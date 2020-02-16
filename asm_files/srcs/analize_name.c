/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analize_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:23:37 by jstokes           #+#    #+#             */
/*   Updated: 2020/02/13 18:58:59 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	analize_name(char *name)
{
	size_t	len;

	len = ft_strlen(name);
	if (len > 2 && ft_strcmp(name + len - 2, ".s") == 0)
		ft_asm(name);
	else
		fprint("Error! %s has wrong filename extension!\n", name);
}
