/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:10:32 by jstokes           #+#    #+#             */
/*   Updated: 2020/02/13 18:59:04 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	clean_lops(t_lop **lops)
{
	int		j;

	if (!lops || !(*lops))
		return ;
	if ((*lops)->next)
		clean_lops(&((*lops)->next));
	ft_lstdelstr(&((*lops)->labels));
	j = -1;
	if ((*lops)->op)
		while (++j < (*lops)->op->vars_num)
			if ((*lops)->label[j])
				ft_strdel(&((*lops)->label[j]));
	free(*lops);
	*lops = NULL;
}

void	clean_text(t_text **text)
{
	if (!text || !(*text))
		return ;
	if ((*text)->text)
		ft_strdel(&((*text)->text));
	free(*text);
	*text = NULL;
}

void	clean_asm(t_asm *tmp_asm)
{
	if (tmp_asm->cor_name)
		ft_strdel(&(tmp_asm->cor_name));
	if (tmp_asm->s_fd > 0)
		close(tmp_asm->s_fd);
	tmp_asm->s_fd = -1;
	if (tmp_asm->cor_fd > 0)
		close(tmp_asm->cor_fd);
	tmp_asm->cor_fd = -1;
	if (tmp_asm->header)
	{
		free(tmp_asm->header);
		tmp_asm->header = NULL;
	}
	clean_lops(&(tmp_asm->lops));
	clean_lops(&(tmp_asm->tmp_lop));
	clean_text(&(tmp_asm->text));
	ft_strdel(&(tmp_asm->line));
	ft_strsplitdel(&(tmp_asm->split));
}
