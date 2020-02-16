/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:19:40 by jmaynard          #+#    #+#             */
/*   Updated: 2020/02/15 18:53:55 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

/*
**	OPERATION	LIVE (alive)
**	OPCODE		ARGUMENT_1
**	1			T_DIR
**
**	Засчитывает что каретка жива (переменная last_alive), если аргумент
**	совпадает с номером живого чемпиона, то этот чемпион также обновляет свою
**	переменную last_alive
*/

inline static int	error(int position, int *step)
{
	*step = -1;
	fprint("Error: live function error at %d position\n", position);
	return (-1);
}

void				operation_live(t_dasm *dasm, int position, int *step)
{
	int				arg1;

	if (dasm->codesize < position + 4 && error(position, step))
		return ;
	arg1 = get_bytes(dasm->code, position + 1, 4, dasm);
	fprint_fd(dasm->fd_o, "\tlive %%%d\n", arg1);
	*step = 5;
}
