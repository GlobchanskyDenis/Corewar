/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disasm_free_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 19:06:25 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/02/15 18:21:08 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

void		free_dasm(t_dasm *dasm)
{
	if (dasm)
	{
		if (dasm->filename)
			free(dasm->filename);
		if (dasm->name)
			free(dasm->name);
		if (dasm->comment)
			free(dasm->comment);
		if (dasm->code)
			free(dasm->code);
		close(dasm->fd_i);
		close(dasm->fd_o);
		free(dasm);
	}
}

int			free_and_return(t_dasm *dasm, char *message)
{
	free_dasm(dasm);
	if (message)
		fprint("%s\n", message);
	return (-1);
}
