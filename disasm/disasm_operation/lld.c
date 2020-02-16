/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:05:37 by jmaynard          #+#    #+#             */
/*   Updated: 2020/02/15 18:54:00 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

/*
**	OPERATION	LLD (long load)
**	OPCODE		ARGUMENT_1		ARGUMENT_2
**	13 (0x0D)	T_DIR/T_IND		T_REG
**
**	Загружает значение из аргумента 1 в регистр из аргумента 2 без ограничения
**	по дальности IDX_MOD. Меняет carry.
*/

inline static short	is_invalid_parameters(short types)
{
	if (types >> 6 == REG_CODE || types >> 6 == 0 || \
		(types >> 4 & 3) != REG_CODE)
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
	fprint("Error: lld function error at %d position\n", position);
	return (-1);
}

void				operation_lld(t_dasm *dasm, int position, int *step)
{
	short	types;
	t_arg	arg1;
	t_arg	arg2;

	types = (short)(dasm->code[position + 1]);
	arg1.size = get_arg_size(types >> 6, 13);
	arg2.size = get_arg_size((types >> 4) & 3, 13);
	if (dasm->codesize < position + 1 + arg1.size + arg2.size && \
			error(position, step))
		return ;
	arg1.val = get_bytes(dasm->code, position + 2, arg1.size, dasm);
	arg2.val = get_bytes(dasm->code, position + 2 + arg1.size, arg2.size, dasm);
	if (is_invalid_parameters(types) && error(position, step))
		return ;
	fprint_fd(dasm->fd_o, "\tlld ", arg1);
	print_param(dasm->fd_o, types >> 6, arg1.val, 1);
	print_param(dasm->fd_o, (types >> 4) & 3, arg2.val, 0);
	*step = 2 + arg1.size + arg2.size;
}
