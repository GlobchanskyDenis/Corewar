/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analize_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:19:18 by jstokes           #+#    #+#             */
/*   Updated: 2020/02/15 17:19:44 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	is_reg(t_lop *tmp, char *var, size_t i)
{
	int		num;

	if (var[0] != 'r')
		return (0);
	if (!get_num(var + 1, &num) || num < 1 || num > REG_NUMBER)
		return (0);
	tmp->at[i] = T_REG;
	tmp->value[i] = num;
	return (1);
}

char	*get_label(char *var)
{
	char	*label;
	size_t	i;
	size_t	len;

	len = ft_strlen(var);
	if (!(label = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (var[i] && ft_strchr(LABEL_CHARS, var[i]))
	{
		label[i] = var[i];
		i++;
	}
	var = skip_sp_tab(var + i);
	if (*var)
	{
		ft_strdel(&label);
		return (NULL);
	}
	return (label);
}

char	dir_ind(t_lop *tmp, char *var, t_arg_type type, size_t i)
{
	int		num;
	char	*label;
	size_t	j;

	if (type == T_DIR && *var != '%')
		return (0);
	j = (type == T_DIR) ? (1) : (0);
	if (var[j] == ':')
	{
		if (!(label = get_label(var + j + 1)))
			return (0);
		tmp->label[i] = label;
		tmp->at[i] = type;
		return (1);
	}
	if (!get_num(var + j, &num))
		return (0);
	tmp->value[i] = num;
	tmp->at[i] = type;
	return (1);
}

char	analize_var(char *var, t_lop *tmp, size_t i)
{
	t_arg_type	type;

	type = tmp->op->var[i];
	if ((type & T_REG) == T_REG && is_reg(tmp, var, i))
		return (1);
	else if ((type & T_DIR) == T_DIR && dir_ind(tmp, var, T_DIR, i))
		return (1);
	else if ((type & T_IND) == T_IND && dir_ind(tmp, var, T_IND, i))
		return (1);
	return (0);
}
