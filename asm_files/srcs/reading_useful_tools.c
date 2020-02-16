/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_useful_tools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:39:12 by jstokes           #+#    #+#             */
/*   Updated: 2020/02/15 17:06:39 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*skip_sp_tab(char *str)
{
	if (!str)
		return (NULL);
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}

char		*go_to_next_line(char *cur, t_text *text)
{
	if (!cur || !text || !text->text)
		return (NULL);
	while (*cur != '\n')
		cur++;
	cur++;
	text->tmp = cur - text->text;
	return (cur);
}

char		skip_comments(t_asm *tasm)
{
	t_text	*text;
	char	*cur;

	text = tasm->text;
	cur = text->text + text->tmp;
	while (ft_strchr(cur, '\n'))
	{
		cur = skip_sp_tab(cur);
		if (*cur == COMMENT_CHAR || *cur == COMMENT_CHAR2 || *cur == '\n')
			cur = go_to_next_line(cur, text);
		else
			return (0);
	}
	return (1);
}

static char	add_new_part(t_text *text, char *buf)
{
	char	*new_text;

	if (!text->text)
	{
		if (!(text->text = ft_strdup(buf)))
			return (0);
		text->tmp = 0;
		return (1);
	}
	if (!(new_text = ft_strjoin(text->text + text->tmp, buf)))
		return (0);
	ft_strdel(&(text->text));
	text->text = new_text;
	text->tmp = 0;
	return (1);
}

char		read_while_no_char(t_asm *tasm, char c)
{
	char	*cur;
	size_t	ret;
	t_text	*text;
	char	buf[BUFF_SIZE + 1];

	text = tasm->text;
	if (text->text && ft_strchr(text->text + text->tmp, c))
		return (1);
	while ((ret = read(tasm->s_fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!add_new_part(text, buf))
			return (error0(tasm, MEM_ALLOC));
		if (ft_strchr(buf, c))
			return (1);
	}
	cur = skip_sp_tab(text->text + text->tmp);
	if (*cur == COMMENT_CHAR || *cur == COMMENT_CHAR2 || *cur == '\0')
		return (2);
	return (error0(tasm, ERR_BS));
}
