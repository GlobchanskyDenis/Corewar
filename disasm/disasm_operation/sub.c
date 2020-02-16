/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:51:44 by jmaynard          #+#    #+#             */
/*   Updated: 2020/02/15 18:54:27 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

/*
**	OPERATION	SUB (subtraction)
**	OPCODE		ARGUMENT_1		ARGUMENT_2		ARGUMENT_3
**	5			T_REG			T_REG			T_REG
**
**	Записывает в регистр заданный аргументом 3 разницу значений регистров
**	полученных из аргументов 1 и 2. Меняет carry.
*/

inline static short	is_invalid_parameters(short types)
{
	if (types >> 6 != REG_CODE || (types >> 4 & 3) != REG_CODE || \
			(types >> 2 & 3) != REG_CODE)
		return (1);
	return (0);
}

inline static void	print_param(int fd, short type, int val, short cont_flag)
{
	if (type == REG_CODE)
		fprint_fd(fd, "r%d", val);
	else if (type == IND_CODE)
		fprint_fd(fd, "%d", val);
	else
		fprint_fd(fd, "%%%d", val);
	if (cont_flag)
		fprint_fd(fd, ", ");
	else
		fprint_fd(fd, "\n");
}

inline static int	error(int position, int *step)
{
	*step = -1;
	fprint("Error: sub function error at %d position\n", position);
	return (-1);
}

void				operation_sub(t_dasm *dasm, int position, int *step)
{
	short	types;
	t_arg	arg1;
	t_arg	arg2;
	t_arg	arg3;

	types = (short)(dasm->code[position + 1]);
	arg1.size = get_arg_size(types >> 6, 5);
	arg2.size = get_arg_size((types >> 4) & 3, 5);
	arg3.size = get_arg_size((types >> 2) & 3, 5);
	if (dasm->codesize < position + 1 + arg1.size + arg2.size + arg3.size && \
			error(position, step))
		return ;
	arg1.val = get_bytes(dasm->code, position + 2, arg1.size, dasm);
	arg2.val = get_bytes(dasm->code, position + 2 + arg1.size, arg2.size, dasm);
	arg3.val = get_bytes(dasm->code, position + 2 + arg1.size + arg2.size, \
			arg3.size, dasm);
	if (is_invalid_parameters(types) && error(position, step))
		return ;
	fprint_fd(dasm->fd_o, "\tsub ", arg1);
	print_param(dasm->fd_o, types >> 6, arg1.val, 1);
	print_param(dasm->fd_o, (types >> 4) & 3, arg2.val, 1);
	print_param(dasm->fd_o, (types >> 2) & 3, arg3.val, 0);
	*step = 2 + arg1.size + arg2.size + arg3.size;
}
