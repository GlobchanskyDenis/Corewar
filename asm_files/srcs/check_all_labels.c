/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_labels.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:53:26 by jstokes           #+#    #+#             */
/*   Updated: 2020/02/13 18:59:01 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	subcheck_all_labels(t_list *tmplst, t_list *check)
{
	while (check)
	{
		if (ft_strcmp(tmplst->content, check->content) == 0)
			return (0);
		check = check->next;
	}
	return (1);
}

char		check_all_labels(t_asm *tasm)
{
	t_lop	*lop[2];
	t_list	*lst;

	lop[0] = tasm->lops;
	while (lop[0] && lop[0]->next)
	{
		lst = lop[0]->labels;
		while (lst)
		{
			lop[1] = lop[0]->next;
			while (lop[1])
			{
				if (!subcheck_all_labels(lst, lop[1]->labels))
					return (0);
				lop[1] = lop[1]->next;
			}
			lst = lst->next;
		}
		lop[0] = lop[0]->next;
	}
	return (1);
}
