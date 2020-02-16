/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:02:30 by jmaynard          #+#    #+#             */
/*   Updated: 2020/02/15 18:54:36 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

/*
**	OPERATION	ZJMP (zero jump)
**	OPCODE		ARGUMENT_1
**	9			T_DIR
**
**	Если флаг carry был установлен в единицу (операция записала ноль), каретка
**	прыгает на расстояние указанное аргументом 1.
*/

inline static int	error(int position, int *step)
{
	*step = -1;
	fprint("Error: zjmp function error at %d position\n", position);
	return (-1);
}

void				operation_zjmp(t_dasm *dasm, int position, int *step)
{
	int				arg1;

	if (dasm->codesize < position + 2 && error(position, step))
		return ;
	arg1 = get_bytes(dasm->code, position + 1, 2, dasm);
	fprint_fd(dasm->fd_o, "\tzjmp %%%d\n", arg1);
	*step = 3;
}
