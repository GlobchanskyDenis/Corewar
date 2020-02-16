/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_extract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:32:46 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/02/15 16:41:06 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

size_t			extract_number(const char *str, t_vm *vm)
{
	size_t	nbr;
	short	i;

	if (!vm || !str)
		error_exit(vm, "extract number - empty ptr found");
	nbr = 0;
	i = 0;
	while (str[i] == '0')
		i++;
	while (str[i] && nbr < UINT_MAX)
		nbr = nbr * 10 + (int)(str[i++] - '0');
	if (nbr > UINT_MAX)
		nbr = UINT_MAX;
	return (nbr);
}

static char		*allocate_this(char *buf, short name_len, t_vm *vm)
{
	char	*dst;
	short	len;

	if (!buf || !vm)
		error_exit(vm, "allocate this - empty ptr found");
	len = 0;
	while (len < name_len && buf[len])
		len++;
	if (!(dst = ft_strnew(len + 1)))
		error_exit(vm, "allocate this - malloc returned null");
	ft_memcpy(dst, buf, (size_t)len);
	while (len < name_len)
	{
		if (buf[len])
			error_exit(vm, "allocate this - name or comment error");
		len++;
	}
	return (dst);
}

static char		*allocate_code(char *buf, short len, t_vm *vm)
{
	char	*dst;

	if (!buf || !vm)
		error_exit(vm, "allocate this - empty ptr found");
	if (!(dst = ft_strnew(len + 1)))
		error_exit(vm, "allocate this - malloc returned null");
	ft_memcpy(dst, buf, (size_t)len);
	return (dst);
}

/*
**	Function extracts data from the bufer (it was filled from the file in
**	read_files function) to the player (name, comment, players code).
*/

void			extract_data(t_pl *player, char *buf, t_vm *vm)
{
	if (!player || !vm || !buf)
		error_exit(vm, "extract data - empty ptr found");
	if (!(player->name = allocate_this(&(buf[4]), PROG_NAME_LENGTH, vm)))
		error_exit(vm, "extract data - allocating function returned null");
	if (!(player->comment = allocate_this(&(buf[8 + PROG_NAME_LENGTH + \
			CHAMP_EXEC_CODE_SIZE]), COMMENT_LENGTH, vm)))
		error_exit(vm, "extract data - allocating function returned null");
	if (!(player->code = (unsigned char *)allocate_code(&(buf[12 + \
			PROG_NAME_LENGTH + CHAMP_EXEC_CODE_SIZE + COMMENT_LENGTH]), \
			player->codesize, vm)))
		error_exit(vm, "extract data - allocating function returned null");
}
