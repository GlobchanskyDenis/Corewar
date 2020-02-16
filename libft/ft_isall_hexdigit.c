/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isall_hexdigit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 10:35:25 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/11/22 10:35:27 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isall_hexdigit(char *str)
{
	size_t	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && \
				!(str[i] >= 'a' && str[i] <= 'f') && \
				!(str[i] >= 'A' && str[i] <= 'F'))
			return (0);
		i++;
	}
	return (1);
}