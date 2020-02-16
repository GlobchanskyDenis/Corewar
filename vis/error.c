/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:05:35 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/09 16:52:55 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void	ft_error(void)
{
	fprint("Error: %s\n", SDL_GetError);
	exit(EXIT_FAILURE);
}

void	ft_error_ttf(void)
{
	fprint("Error: %s\n", TTF_GetError());
	exit(EXIT_FAILURE);
}

void	ft_sim_error(void)
{
	fprint("Error\n");
	exit(EXIT_FAILURE);
}
