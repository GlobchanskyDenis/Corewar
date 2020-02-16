/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lop_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstokes <jstokes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:04:50 by jstokes           #+#    #+#             */
/*   Updated: 2020/02/13 18:20:50 by jstokes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_lop	*lop_new(void)
{
	t_lop	*new;

	if (!(new = (t_lop *)malloc(sizeof(t_lop))))
		return (NULL);
	new->at[0] = 0;
	new->at[1] = 0;
	new->at[2] = 0;
	new->label[0] = NULL;
	new->label[1] = NULL;
	new->label[2] = NULL;
	new->lop[0] = NULL;
	new->lop[1] = NULL;
	new->lop[2] = NULL;
	new->labels = NULL;
	new->next = NULL;
	new->op = NULL;
	return (new);
}

t_lop	*lop_add_end(t_lop **lops, t_lop **new)
{
	t_lop	*tmp;

	if (!lops || !new || !(*new))
		return (NULL);
	if (!(*lops))
	{
		*lops = *new;
		*new = NULL;
		return (NULL);
	}
	tmp = *lops;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *new;
	*new = NULL;
	return (tmp->next);
}

void	*lop_add_label(t_lop *lop, char **label)
{
	t_list	*new;

	if (!lop || !label || !(*label))
		return (NULL);
	if (!(new = ft_lstnew(*label, ft_strlen(*label) + 1)))
		return (NULL);
	ft_lstaddend(&(lop->labels), new);
	ft_strdel(label);
	return (new);
}

void	*create_tmp_lop(t_asm *tasm)
{
	if (!tasm)
		return (NULL);
	if (!tasm->tmp_lop)
		if (!(tasm->tmp_lop = lop_new()))
			return (NULL);
	return (tasm->tmp_lop);
}
