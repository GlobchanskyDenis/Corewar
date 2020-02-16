/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:04:53 by jstokes           #+#    #+#             */
/*   Updated: 2020/02/15 17:30:32 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*get_line(t_asm *tasm)
{
	char	*tmp[3];
	char	*cur;
	char	*line;
	size_t	len[3];

	cur = tasm->text->text + tasm->text->tmp;
	tmp[0] = ft_strchr(cur, COMMENT_CHAR2);
	tmp[1] = ft_strchr(cur, COMMENT_CHAR);
	tmp[2] = ft_strchr(cur, '\n');
	len[0] = MAX_INT;
	len[1] = MAX_INT;
	len[2] = tmp[2] - cur;
	if (tmp[0] && tmp[0] < tmp[2])
		len[0] = tmp[0] - cur;
	if (tmp[1] && tmp[1] < tmp[2])
		len[1] = tmp[1] - cur;
	if (len[0] < len[2] && len[0] < len[1])
		len[2] = len[0];
	else if (len[1] < len[2] && len[1] < len[0])
		len[2] = len[1];
	if (!(line = ft_strnew(len[2])))
		return (errornull(tasm, MEM_ALLOC));
	ft_strncpy(line, cur, len[2]);
	tasm->text->tmp += tmp[2] - cur;
	return (line);
}

size_t		count_seps_n_blocks(char *str, char **tmp)
{
	size_t	num;
	size_t	i;

	i = 0;
	num = 0;
	while (str[i] && str[i] != COMMENT_CHAR && str[i] != COMMENT_CHAR2)
	{
		if (str[i] == SEPARATOR_CHAR)
			num++;
		i++;
	}
	i = 0;
	while (tmp[i])
		i++;
	if (i - 1 == num)
		return (i);
	return (0);
}

static char	choose_way(t_asm *tasm)
{
	char	*cur;

	cur = skip_sp_tab(tasm->line);
	while (ft_strchr(LABEL_CHARS, *cur))
		cur++;
	cur = skip_sp_tab(cur);
	if (*cur != ':')
		return (check_op(tasm, 0));
	cur = skip_sp_tab(cur + 1);
	if (*cur == '\0' || *cur == COMMENT_CHAR || *cur == COMMENT_CHAR2)
		return (check_label(tasm));
	while (ft_strchr(LABEL_CHARS, *cur))
		cur++;
	cur = skip_sp_tab(cur);
	if (*cur == SEPARATOR_CHAR)
		return (check_op(tasm, 0));
	return (check_label(tasm));
}

char		read_ops(t_asm *tasm)
{
	char	res;

	tasm->tmp_lop = NULL;
	tasm->lops = NULL;
	tasm->line = NULL;
	tasm->split = NULL;
	while ((res = read_while_no_char(tasm, '\n')) == 1)
	{
		if (skip_comments(tasm))
			continue ;
		if (!(tasm->line = get_line(tasm)) ||
			!choose_way(tasm))
			return (0);
	}
	if (res == 0)
	{
		clean_asm(tasm);
		return (0);
	}
	if (tasm->tmp_lop)
		lop_add_end(&(tasm->lops), &(tasm->tmp_lop));
	if (tasm->lops)
		if (!check_all_labels(tasm))
			return (error0(tasm, SIM_LAB));
	return (1);
}
