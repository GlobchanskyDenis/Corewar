/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disasm_getters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 23:46:52 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/02/15 18:21:10 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

/*
**	Function returns how many bytes we must read in this argument
*/

short		get_arg_size(unsigned char byte, short op_code)
{
	if (byte == REG_CODE)
		return (1);
	if (byte == DIR_CODE)
	{
		if ((op_code >= OP_LIVE && op_code <= OP_XOR) || op_code == OP_LLD || \
				op_code == OP_AFF)
			return (4);
		return (2);
	}
	if (byte == IND_CODE)
		return (2);
	return (0);
}

static int	get_4_bytes(unsigned char *code, int start)
{
	int				i;
	int				position;
	int				dst;

	dst = 0;
	position = start;
	i = -1;
	while (++i < 4)
	{
		dst = dst << 8;
		dst += (int)code[position];
		position++;
	}
	return (dst);
}

static int	get_2_bytes(unsigned char *code, int start)
{
	int				i;
	int				position;
	short			dst;

	dst = 0;
	position = start;
	i = -1;
	while (++i < 2)
	{
		dst = dst << 8;
		dst += (short)code[position];
		position++;
	}
	return ((int)dst);
}

/*
**	function returns selected bytes from the code in integer variable
*/

int			get_bytes(unsigned char *code, int start, int len, t_dasm *dasm)
{
	if (dasm->codesize < start + len - 1)
		return (0);
	if (len == 4)
		return (get_4_bytes(code, start));
	if (len == 2)
		return (get_2_bytes(code, start));
	if (len == 1)
		return ((int)code[start]);
	return (0);
}
