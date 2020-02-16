/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:04:08 by jmaynard          #+#    #+#             */
/*   Updated: 2020/02/15 18:53:51 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

/*
**	OPERATION	LFORK (long fork)
**	OPCODE		ARGUMENT_1
**	15 (0x0F)	T_DIR
**
**	Дублирует каретку и размещает ее по адресу первого аргумента без ограничения
**	по IDX_MOD.
*/

inline static int	error(int position, int *step)
{
	*step = -1;
	fprint("Error: lfork function error at %d position\n", position);
	return (-1);
}

void				operation_lfork(t_dasm *dasm, int position, int *step)
{
	int				arg1;

	if (dasm->codesize < position + 2 && error(position, step))
		return ;
	arg1 = get_bytes(dasm->code, position + 1, 2, dasm);
	fprint_fd(dasm->fd_o, "\tlfork %%%d\n", arg1);
	*step = 3;
}
