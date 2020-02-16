/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_labels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstokes <jstokes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:31:22 by jstokes           #+#    #+#             */
/*   Updated: 2020/02/13 18:25:30 by jstokes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		compute_ops_size(t_asm *tasm)
{
	int		i;
	size_t	size;
	t_lop	*lop;

	lop = tasm->lops;
	tasm->header->prog_size = 0;
	while (lop && lop->op)
	{
		size = (lop->op->vars_num > 1 || lop->op->ind == 16) ? (2) : (1);
		i = -1;
		while (++i < lop->op->vars_num)
			size += get_size(lop->at[i], lop->op->ind);
		lop->size = size;
		tasm->header->prog_size += size;
		lop = lop->next;
	}
}

static t_lop	*get_lop(t_asm *tasm, char *label)
{
	t_list	*labels;
	t_lop	*lop;

	lop = tasm->lops;
	while (lop)
	{
		labels = lop->labels;
		while (labels)
		{
			if (ft_strcmp(labels->content, label) == 0)
				return (lop);
			labels = labels->next;
		}
		lop = lop->next;
	}
	return (NULL);
}

static int		get_value(t_asm *tasm, t_lop *tmp, t_lop *lop_label)
{
	char	flag;
	t_lop	*lop;
	size_t	len;

	lop = tasm->lops;
	flag = 1;
	while (lop)
	{
		if (lop == tmp || lop == lop_label)
			break ;
		lop = lop->next;
	}
	if (lop == lop_label)
		flag = -1;
	len = lop->size;
	lop = lop->next;
	while (lop)
	{
		if (lop == tmp || lop == lop_label)
			break ;
		len += lop->size;
		lop = lop->next;
	}
	return (flag * ((int)len));
}

static void		subreplace_labels(t_asm *tasm)
{
	int		i;
	t_lop	*lop;

	lop = tasm->lops;
	while (lop && lop->op)
	{
		i = -1;
		while (++i < lop->op->vars_num)
		{
			if (lop->lop[i])
				lop->value[i] = get_value(tasm, lop, lop->lop[i]);
		}
		lop = lop->next;
	}
}

char			replace_labels(t_asm *tasm)
{
	int		i;
	t_lop	*lop;

	compute_ops_size(tasm);
	lop = tasm->lops;
	while (lop && lop->op)
	{
		i = -1;
		while (++i < lop->op->vars_num)
		{
			if (lop->label[i])
				if (!(lop->lop[i] = get_lop(tasm, lop->label[i])))
					return (error0(tasm, ": label not found\n"));
			ft_strdel(&(lop->label[i]));
		}
		lop = lop->next;
	}
	subreplace_labels(tasm);
	tasm->full_len = 4 + PROG_NAME_LENGTH + 4 + COMMENT_LENGTH +
									4 + 4 + tasm->header->prog_size;
	return (1);
}
