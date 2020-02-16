/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstokes <jstokes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:29:10 by jstokes           #+#    #+#             */
/*   Updated: 2020/02/13 17:29:39 by jstokes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	add2(t_op *op, char var1, char var2, char var3)
{
	op->var[0] = var1;
	op->var[1] = var2;
	op->var[2] = var3;
	return (1);
}

static char	add1(t_op *op, int vars_num, char *com, int ind)
{
	op->vars_num = vars_num;
	op->com = com;
	op->ind = ind;
	if (op->com)
		op->com_len = ft_strlen(op->com);
	else
		op->com_len = 0;
	return (1);
}

char		init_ops(t_op *ops)
{
	if (!add1(ops + 0, 0, NULL, 0) || !add2(ops + 0, 0, 0, 0) ||
		!add1(ops + 1, 1, "live", 1) || !add2(ops + 1, T_DIR, 0, 0) ||
		!add1(ops + 2, 2, "ld", 2) ||
			!add2(ops + 2, T_DIR | T_IND, T_REG, 0) ||
		!add1(ops + 3, 2, "st", 3) ||
			!add2(ops + 3, T_REG, T_IND | T_REG, 0) ||
		!add1(ops + 4, 3, "add", 4) || !add2(ops + 4, T_REG, T_REG, T_REG) ||
		!add1(ops + 5, 3, "sub", 5) || !add2(ops + 5, T_REG, T_REG, T_REG) ||
		!add1(ops + 6, 3, "and", 6) || !add2(ops + 6, T_RDI, T_RDI, T_REG) ||
		!add1(ops + 7, 3, "or", 7) || !add2(ops + 7, T_RDI, T_RDI, T_REG) ||
		!add1(ops + 8, 3, "xor", 8) || !add2(ops + 8, T_RDI, T_RDI, T_REG) ||
		!add1(ops + 9, 1, "zjmp", 9) || !add2(ops + 9, T_DIR, 0, 0) ||
		!add1(ops + 10, 3, "ldi", 10) ||
			!add2(ops + 10, T_RDI, T_DIR | T_REG, T_REG) ||
		!add1(ops + 11, 3, "sti", 11) ||
			!add2(ops + 11, T_REG, T_RDI, T_DIR | T_REG) ||
		!add1(ops + 12, 1, "fork", 12) || !add2(ops + 12, T_DIR, 0, 0) ||
		!add1(ops + 13, 2, "lld", 13) ||
			!add2(ops + 13, T_DIR | T_IND, T_REG, 0) ||
		!add1(ops + 14, 3, "lldi", 14) ||
			!add2(ops + 14, T_RDI, T_DIR | T_REG, T_REG) ||
		!add1(ops + 15, 1, "lfork", 15) || !add2(ops + 15, T_DIR, 0, 0) ||
		!add1(ops + 16, 1, "aff", 16) || !add2(ops + 16, T_REG, 0, 0))
		return (0);
	return (1);
}
