/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:33:08 by jmaynard          #+#    #+#             */
/*   Updated: 2020/02/15 18:54:23 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

/*
**	OPERATION	STI (store index)
**	OPCODE		ARGUMENT_1		ARGUMENT_2			ARGUMENT_3
**	11 (0x0B)	T_REG			T_REG/T_DIR/T_IND	T_REG/T_DIR
**
**	Эта операция записывает значение регистра, переданного в качестве первого
**	параметра, по адресу — текущая позиция +
**	(<ЗНАЧЕНИЕ_ВТОРОГО_АРГУМЕНТА> + <ЗНАЧЕНИЕ_ТРЕТЕГО_АРГУМЕНТА>) % IDX_MOD
*/

inline static short	is_invalid_parameters(short types)
{
	if ((types >> 6 != REG_CODE) || ((types >> 4 & 3) == 0) || \
			((types >> 2 & 3) != REG_CODE && (types >> 2 & 3) != DIR_CODE))
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
	fprint("Error: sti function error at %d position\n", position);
	return (-1);
}

void				operation_sti(t_dasm *dasm, int position, int *step)
{
	short	types;
	t_arg	arg1;
	t_arg	arg2;
	t_arg	arg3;

	types = (short)(dasm->code[position + 1]);
	arg1.size = get_arg_size(types >> 6, 11);
	arg2.size = get_arg_size((types >> 4) & 3, 11);
	arg3.size = get_arg_size((types >> 2) & 3, 11);
	if (dasm->codesize < position + 1 + arg1.size + arg2.size + arg3.size && \
			error(position, step))
		return ;
	arg1.val = get_bytes(dasm->code, position + 2, arg1.size, dasm);
	arg2.val = get_bytes(dasm->code, position + 2 + arg1.size, arg2.size, dasm);
	arg3.val = get_bytes(dasm->code, position + 2 + arg1.size + arg2.size, \
			arg3.size, dasm);
	if (is_invalid_parameters(types) && error(position, step))
		return ;
	fprint_fd(dasm->fd_o, "\tsti ", arg1);
	print_param(dasm->fd_o, types >> 6, arg1.val, 1);
	print_param(dasm->fd_o, (types >> 4) & 3, arg2.val, 1);
	print_param(dasm->fd_o, (types >> 2) & 3, arg3.val, 0);
	*step = 2 + arg1.size + arg2.size + arg3.size;
}
