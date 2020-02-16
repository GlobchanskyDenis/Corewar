/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disasm_translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 20:04:10 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/02/15 18:21:15 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

static void		initialize_operations_array(void **op_arr)
{
	op_arr[OP_LIVE] = &operation_live;
	op_arr[OP_LD] = &operation_ld;
	op_arr[OP_ST] = &operation_st;
	op_arr[OP_ADD] = &operation_add;
	op_arr[OP_SUB] = &operation_sub;
	op_arr[OP_AND] = &operation_and;
	op_arr[OP_OR] = &operation_or;
	op_arr[OP_XOR] = &operation_xor;
	op_arr[OP_ZJMP] = &operation_zjmp;
	op_arr[OP_LDI] = &operation_ldi;
	op_arr[OP_STI] = &operation_sti;
	op_arr[OP_FORK] = &operation_fork;
	op_arr[OP_LLD] = &operation_lld;
	op_arr[OP_LLDI] = &operation_lldi;
	op_arr[OP_LFORK] = &operation_lfork;
	op_arr[OP_AFF] = &operation_aff;
}

int				translate(t_dasm *dasm)
{
	int				position;
	unsigned char	*code;
	int				operation;
	void			(*op_arr[17])(t_dasm *dasm, int position, int *step);
	int				step;

	initialize_operations_array((void **)op_arr);
	code = dasm->code;
	position = 0;
	while (position < dasm->codesize)
	{
		operation = (int)code[position];
		if (operation < 1 || operation > 16 || dasm->codesize < position + 1)
			return (free_and_return(dasm, "translate error"));
		else
		{
			op_arr[operation](dasm, position, &step);
			if (step < 0)
				return (free_and_return(dasm, NULL));
			position += step;
		}
	}
	return (0);
}
