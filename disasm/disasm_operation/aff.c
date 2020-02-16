/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:06:09 by jmaynard          #+#    #+#             */
/*   Updated: 2020/02/15 18:53:30 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

/*
**	OPERATION	AFF (aff)
**	OPCODE		ARGUMENT_1
**	16 (0x10)	T_REG
**
**	Эта операция выводит на экран значение из регистра как ASCII символ.
*/

inline static short	is_invalid_parameters(int types)
{
	if (types >> 6 != REG_CODE)
		return (-1);
	return (0);
}

inline static int	error(int position, int *step)
{
	*step = -1;
	fprint("Error: aff function error at %d position\n", position);
	return (-1);
}

void				operation_aff(t_dasm *dasm, int position, int *step)
{
	int				types;
	int				arg1;

	if (dasm->codesize < position + 2 && error(position, step))
		return ;
	types = (int)(dasm->code[position + 1]);
	arg1 = (int)(dasm->code[position + 2]);
	if (is_invalid_parameters(types) && error(position, step))
		return ;
	fprint_fd(dasm->fd_o, "\taff r%d\n", arg1);
	*step = 3;
}
