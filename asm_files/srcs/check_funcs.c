/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:51:15 by jstokes           #+#    #+#             */
/*   Updated: 2020/02/15 17:30:13 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	subcheck_label(t_asm *tasm, char *new, char *cur)
{
	if (!create_tmp_lop(tasm) || !lop_add_label(tasm->tmp_lop, &new))
	{
		ft_strdel(&new);
		return (error0(tasm, MEM_ALLOC));
	}
	cur = skip_sp_tab(cur + 1);
	if (*cur == COMMENT_CHAR || *cur == COMMENT_CHAR2 || *cur == '\0')
	{
		ft_strdel(&(tasm->line));
		return (1);
	}
	return (check_op(tasm, 1));
}

char		check_label(t_asm *tasm)
{
	char	*new;
	char	*cur;
	size_t	len;
	size_t	i;

	cur = skip_sp_tab(tasm->line);
	if (!(new = ft_strchr(cur, LABEL_CHAR)))
		return (error0(tasm, ": no LABEL_CHAR after label\n"));
	len = new - cur;
	if (!(new = ft_strnew(len)))
		return (error0(tasm, MEM_ALLOC));
	i = -1;
	while (++i < len)
	{
		if (!ft_strchr(LABEL_CHARS, cur[i]))
		{
			cur = skip_sp_tab(cur + i);
			if (*cur == LABEL_CHAR)
				break ;
			return (error0(tasm, ": bad symbol in the label\n"));
		}
		new[i] = cur[i];
	}
	new[i] = '\0';
	return (subcheck_label(tasm, new, cur + i));
}

static char	check_vars(t_asm *tasm, char *cur)
{
	size_t	i;
	size_t	args_num;

	if (!(tasm->split = strsplitestsep(cur)))
		return (error0(tasm, MEM_ALLOC));
	if (!(args_num = count_seps_n_blocks(cur, tasm->split)))
		return (error0(tasm, ": too many commas in a line\n"));
	if (args_num != (size_t)tasm->tmp_lop->op->vars_num)
		return (error0(tasm, ": wrong number of arguments\n"));
	i = -1;
	while (++i < args_num)
		if (!analize_var(tasm->split[i], tasm->tmp_lop, i))
			return (error0(tasm, ": bad format of variable or its type\n"));
	lop_add_end(&(tasm->lops), &(tasm->tmp_lop));
	ft_strdel(&(tasm->line));
	ft_strsplitdel(&(tasm->split));
	return (1);
}

char		check_op(t_asm *tasm, char label_read)
{
	int		j;
	char	*cur;

	cur = (!label_read) ? (skip_sp_tab(tasm->line)) :
			(skip_sp_tab(ft_strchr(tasm->line, LABEL_CHAR) + 1));
	j = 17;
	while (--j > 0)
		if (ft_strncmp(cur, tasm->ops[j].com, tasm->ops[j].com_len) == 0)
		{
			cur += tasm->ops[j].com_len;
			if (*cur != ' ' && *cur != '\t' && *cur != DIRECT_CHAR &&
				*cur != LABEL_CHAR)
				return (error0(tasm, ": bad symbol after operation\n"));
			if (!create_tmp_lop(tasm))
				return (error0(tasm, MEM_ALLOC));
			cur = skip_sp_tab(cur);
			tasm->tmp_lop->op = &(tasm->ops[j]);
			return (check_vars(tasm, cur));
		}
	return (error0(tasm, ": operation not found\n"));
}
