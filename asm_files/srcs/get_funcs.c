/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstokes <jstokes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:12:00 by jstokes           #+#    #+#             */
/*   Updated: 2020/02/15 14:48:52 by jstokes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

size_t		get_size(t_arg_type type, int ind)
{
	if (type == T_REG)
		return (1);
	else if (type == T_IND)
		return (2);
	else if (type == T_DIR && (ind == 9 || ind == 10 || ind == 11 || ind == 12
			|| ind == 14 || ind == 15))
		return (2);
	else if (type == T_DIR)
		return (4);
	return (0);
}

static char	care_of_sp_tab(char *var)
{
	char	*tmp;
	size_t	pl;
	size_t	j;

	j = 0;
	while (ft_isdigit(var[j]))
		j++;
	pl = j;
	tmp = skip_sp_tab(var + j);
	if (*tmp)
		return (0);
	var[pl] = '\0';
	return (1);
}

static int	process_min_int(char *var, size_t i, char minus)
{
	char	*tmp;

	tmp = var + i + 10;
	if (minus == 1 && ft_strncmp(var + i, "2147483648", 10) == 0 &&
		(*tmp == '\0' || *tmp == '\t' || *tmp == ' '))
		return (-2147483648);
	if (minus == 1)
		return (-1 * ft_atoi(var + i));
	return (ft_atoi(var + i));
}

char		get_num(char *var, int *num)
{
	size_t	i;
	char	minus;

	minus = (var[0] == '-') ? (1) : (0);
	i = (var[0] == '-') ? (1) : (0);
	if (!care_of_sp_tab(var + i))
		return (0);
	while (var[i] == '0')
		i++;
	if (var[i] == '\0')
	{
		if (var[i - 1] != '0')
			return (0);
		*num = 0;
		return (1);
	}
	*num = process_min_int(var, i, minus);
	if (!ft_intcheck(var + i - minus, minus, *num))
		return (0);
	return (1);
}
