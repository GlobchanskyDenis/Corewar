/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 19:31:40 by jstokes           #+#    #+#             */
/*   Updated: 2020/02/15 16:57:31 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_code(t_arg_type type)
{
	if (type == T_REG)
		return (REG_CODE);
	else if (type == T_DIR)
		return (DIR_CODE);
	else if (type == T_IND)
		return (IND_CODE);
	return (0);
}

void	add_num(t_asm *tasm, int num, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = tasm->text->text + tasm->text->tmp;
	tasm->text->tmp += size;
	while (size)
	{
		str[size - 1] = (unsigned char)((num >> i) & 0xff);
		i += 8;
		size--;
	}
}

void	add_str(t_asm *tasm, char *str, size_t len)
{
	size_t	i;
	char	*res;

	res = tasm->text->text + tasm->text->tmp;
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	while (i < len)
	{
		res[i] = (unsigned char)0x00;
		i++;
	}
	tasm->text->tmp += len;
}

void	add_vars_code(t_asm *tasm, t_lop *lop)
{
	int		res;
	int		i;

	i = -1;
	res = 0;
	while (++i < lop->op->vars_num)
	{
		res *= 4;
		res += get_code(lop->at[i]);
	}
	while (i++ < 4)
		res *= 4;
	add_num(tasm, res, 1);
}

char	print_result(t_asm *tasm)
{
	t_lop	*lop;
	int		i;

	ft_strdel(&(tasm->text->text));
	tasm->text->tmp = 0;
	if (!(tasm->text->text = (char *)malloc(tasm->full_len)))
		return (error0(tasm, MEM_ALLOC));
	add_num(tasm, COREWAR_EXEC_MAGIC, 4);
	add_str(tasm, tasm->header->prog_name, PROG_NAME_LENGTH + 4);
	add_num(tasm, tasm->header->prog_size, 4);
	add_str(tasm, tasm->header->comment, COMMENT_LENGTH + 4);
	lop = tasm->lops;
	while (lop && lop->op)
	{
		add_num(tasm, lop->op->ind, 1);
		if (lop->op->vars_num > 1 || lop->op->ind == 16)
			add_vars_code(tasm, lop);
		i = -1;
		while (++i < lop->op->vars_num)
			add_num(tasm, lop->value[i], get_size(lop->at[i], lop->op->ind));
		lop = lop->next;
	}
	write(tasm->cor_fd, tasm->text->text, tasm->full_len);
	return (1);
}
