/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name_n_comment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstokes <jstokes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:35:53 by jstokes           #+#    #+#             */
/*   Updated: 2020/02/15 14:22:16 by jstokes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*check_command(t_asm *tasm, char *cur, int cmd_str_len)
{
	cur = skip_sp_tab(cur + cmd_str_len);
	if (*cur != '\"')
		return (errornull(tasm, ": wrong format of name or comment\n"));
	cur++;
	return (cur);
}

static char	*read_from_to(char *cur, char *prog_char)
{
	size_t	i;

	i = 0;
	while (1)
	{
		if (cur[i] == '\"')
		{
			prog_char[i] = '\0';
			return (cur + i + 1);
		}
		prog_char[i] = cur[i];
		i++;
	}
	return (NULL);
}

static char	useful_func(t_asm *tasm,
				char *cur, int prog_char_len, char *prog_char)
{
	tasm->text->tmp = cur - tasm->text->text;
	if (!read_while_no_char(tasm, '\"'))
		return (0);
	cur = tasm->text->text + tasm->text->tmp;
	if (ft_strchr(cur, '\"') - cur > prog_char_len)
		return (error0(tasm, ": too long .name or .comment\n"));
	tasm->text->tmp = skip_sp_tab(read_from_to(cur, prog_char))
						- tasm->text->text;
	if (!read_while_no_char(tasm, '\n'))
		return (0);
	cur = tasm->text->text + tasm->text->tmp;
	if (*cur == COMMENT_CHAR || *cur == COMMENT_CHAR2 || *cur == '\n')
		cur = go_to_next_line(cur, tasm->text);
	else
		return (error0(tasm, ": bad symbols after name or comment\n"));
	tasm->text->tmp = cur - tasm->text->text;
	return (1);
}

static char	read_name_or_comment(t_asm *tasm)
{
	char	*cur;

	cur = skip_sp_tab(tasm->text->text + tasm->text->tmp);
	if (!tasm->name_read &&
		ft_strncmp(cur, NAME_CMD_STRING, NAME_CMD_STR_LEN) == 0)
	{
		if (!(cur = check_command(tasm, cur, NAME_CMD_STR_LEN))
				||
			!useful_func(tasm, cur, PROG_NAME_LENGTH, tasm->header->prog_name))
			return (0);
		tasm->name_read = 1;
		return (1);
	}
	if (!tasm->comment_read &&
		ft_strncmp(cur, COMMENT_CMD_STRING, COMMENT_CMD_ST_LEN) == 0)
	{
		if (!(cur = check_command(tasm, cur, COMMENT_CMD_ST_LEN))
			|| !useful_func(tasm, cur, COMMENT_LENGTH, tasm->header->comment))
			return (0);
		tasm->comment_read = 1;
		return (1);
	}
	return (error0(tasm, ": name or comment not found\n"));
}

char		get_name_n_comment(t_asm *tasm)
{
	char	j;

	j = 0;
	tasm->name_read = 0;
	tasm->comment_read = 0;
	while (j < 2)
	{
		if (!read_while_no_char(tasm, '\n'))
			return (0);
		if (!skip_comments(tasm))
		{
			if (!read_name_or_comment(tasm))
				return (0);
			j++;
		}
	}
	return (1);
}
