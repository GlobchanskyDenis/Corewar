/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:23:54 by jstokes           #+#    #+#             */
/*   Updated: 2020/02/13 19:17:01 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_usage(void)
{
	fprint("usage: ./asm file1.s ... filen.s\n");
}

void	error(t_asm *tmp_asm, char *err)
{
	fprint("Error! %s%s", tmp_asm->s_name, err);
	clean_asm(tmp_asm);
}

char	error0(t_asm *tmp_asm, char *err)
{
	fprint("Error! %s%s", tmp_asm->s_name, err);
	clean_asm(tmp_asm);
	return (0);
}

char	*errornull(t_asm *tasm, char *err)
{
	fprint("Error! %s%s", tasm->s_name, err);
	clean_asm(tasm);
	return (NULL);
}
