/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:23:40 by jstokes           #+#    #+#             */
/*   Updated: 2020/02/15 17:06:45 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	build_cor_name(t_asm *tmp_asm)
{
	char	*cor_name;
	size_t	len;

	len = ft_strlen(tmp_asm->s_name);
	if (!(cor_name = (char *)malloc(len + 3)))
	{
		error(tmp_asm, MEM_ALLOC);
		return (0);
	}
	ft_strncpy(cor_name, tmp_asm->s_name, len - 2);
	ft_strncpy(cor_name + len - 2, ".cor", 4);
	cor_name[len + 2] = '\0';
	tmp_asm->cor_name = cor_name;
	return (1);
}

void		print_bytecode(t_asm *tasm)
{
	size_t	j;
	char	*str;

	j = -1;
	str = tasm->text->text;
	while (++j < tasm->full_len)
		fprint("%d.%d ",
			((unsigned char)str[j]) / 16, ((unsigned char)str[j]) % 16);
	fprint("\n");
}

void		print_info(t_asm *tasm)
{
	t_lop	*lop;
	size_t	j;

	lop = tasm->lops;
	fprint("NAME: %s\n", tasm->header->prog_name);
	fprint("COMMENT: %s\n", tasm->header->comment);
	while (lop && lop->op)
	{
		j = -1;
		fprint("%s ", lop->op->com);
		while (++j < (size_t)lop->op->vars_num)
			fprint("%d, ", lop->value[j]);
		fprint("size = %d\n", lop->size);
		lop = lop->next;
	}
}

void		ft_asm(char *name)
{
	t_asm	tasm;

	tasm.s_name = name;
	tasm.s_fd = open(name, O_RDONLY);
	init_asm(&tasm);
	if (tasm.s_fd <= 0 || read(tasm.s_fd, NULL, 0) < 0)
		return (error(&tasm, " can't be read\n"));
	if (!build_cor_name(&tasm))
		return ;
	tasm.cor_fd = open(tasm.cor_name, O_CREAT | O_RDWR | O_TRUNC,
											S_IRUSR | S_IWUSR);
	if (tasm.cor_fd <= 0)
		return (error(&tasm, ": can't create and open *.cor file\n"));
	if (!(tasm.header = (t_header *)malloc(sizeof(t_header))) ||
		!init_text(&tasm) || !init_ops(tasm.ops))
		return (error(&tasm, ": memory can't be allocated\n"));
	if (!get_name_n_comment(&tasm) || !read_ops(&tasm) ||
		!replace_labels(&tasm) || !print_result(&tasm))
		return ;
	fprint("File %s successfully processed!\n", tasm.s_name);
	clean_asm(&tasm);
}
