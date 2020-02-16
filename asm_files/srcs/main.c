/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:23:43 by jstokes           #+#    #+#             */
/*   Updated: 2020/02/15 17:40:53 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int argc, char **argv)
{
	int		i;

	if (argc == 1)
		print_usage();
	else
	{
		i = 0;
		while (++i < argc)
			analize_name(argv[i]);
	}
	return (0);
}
