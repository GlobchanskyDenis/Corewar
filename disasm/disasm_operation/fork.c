/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 18:35:13 by jmaynard          #+#    #+#             */
/*   Updated: 2020/02/15 18:53:38 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

/*
**	OPERATION	FORK (fork)
**	OPCODE		ARGUMENT_1
**	12 (0x0C)	T_DIR
**
**	Дублирует каретку и размещает ее по адресу первого аргумента
*/

inline static int	error(int position, int *step)
{
	*step = -1;
	fprint("Error: fork function error at %d position\n", position);
	return (-1);
}

void				operation_fork(t_dasm *dasm, int position, int *step)
{
	int				arg1;

	if (dasm->codesize < position + 2 && error(position, step))
		return ;
	arg1 = get_bytes(dasm->code, position + 1, 2, dasm);
	fprint_fd(dasm->fd_o, "\tfork %%%d\n", arg1);
	*step = 3;
}
