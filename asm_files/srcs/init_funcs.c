/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:39:19 by jstokes           #+#    #+#             */
/*   Updated: 2020/02/13 19:22:04 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	init_text(t_asm *tmp_asm)
{
	if (!(tmp_asm->text = (t_text *)malloc(sizeof(t_text))))
		return (0);
	tmp_asm->text->tmp = 0;
	tmp_asm->text->text = NULL;
	return (1);
}

void	init_asm(t_asm *tasm)
{
	tasm->cor_name = NULL;
	tasm->cor_fd = -1;
	tasm->header = NULL;
	tasm->line = NULL;
	tasm->split = NULL;
	tasm->lops = NULL;
	tasm->tmp_lop = NULL;
	tasm->text = NULL;
}
