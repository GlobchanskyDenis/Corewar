/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_field.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:54:39 by jmaynard          #+#    #+#             */
/*   Updated: 2020/02/12 12:00:36 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

unsigned char	hex_char(int nbr)
{
	if (nbr == 0)
		return ('0');
	else if (nbr > 0 && nbr < 10)
		return (nbr + '0');
	else if (nbr == 10)
		return ('a');
	else if (nbr == 11)
		return ('b');
	else if (nbr == 12)
		return ('c');
	else if (nbr == 13)
		return ('d');
	else if (nbr == 14)
		return ('e');
	else if (nbr == 15)
		return ('f');
	return ('-');
}

unsigned char	*ft_strdup_bit(unsigned char *s1)
{
	size_t			len;
	size_t			i;
	size_t			k;
	unsigned char	*dst;

	len = 0;
	i = 0;
	k = 0;
	if (!(dst = (unsigned char *)malloc(sizeof(unsigned char) \
		* (2 * MEM_SIZE + 1))))
		return (NULL);
	while (i < MEM_SIZE)
	{
		dst[k] = hex_char((s1[i] >> 4));
		dst[k + 1] = hex_char((s1[i] & 0xF));
		k += 2;
		i++;
	}
	dst[k] = '\0';
	return (dst);
}

int				ft_put_field(t_core *core, t_vm *vm)
{
	if (core->game->prev_field)
	{
		free(core->game->prev_field);
		core->game->prev_field = NULL;
	}
	if (core->game->field)
		if (!(core->game->prev_field = \
		(unsigned char *)ft_strdup((char *)core->game->field)))
			ft_sim_error();
	if (core->game->field)
	{
		free(core->game->field);
		core->game->field = NULL;
	}
	if (!(core->game->field = ft_strdup_bit(vm->arena)))
		ft_sim_error();
	return (0);
}
