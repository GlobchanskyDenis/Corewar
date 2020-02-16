/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstokes <jstokes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:29:24 by jstokes           #+#    #+#             */
/*   Updated: 2020/02/13 18:29:48 by jstokes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		ft_intcheck(char *str, int j, int num)
{
	int		k;
	int		tmp;
	int		ord;

	k = 1;
	tmp = num;
	ord = 1;
	while (tmp / 10)
	{
		k++;
		ord *= 10;
		tmp /= 10;
	}
	tmp = (num < 0 && j > 0) ? (-1) : (1);
	while (str[j] && k-- > 0)
	{
		if (str[j] != (num / ord) * tmp + '0')
			return (0);
		j++;
		num = num % ord;
		ord /= 10;
	}
	if (str[j] != '\0' || k > 0)
		return (0);
	return (1);
}
