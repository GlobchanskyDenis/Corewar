/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disasm_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:58:29 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/02/15 18:21:14 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

static char				*allocate_this(char *buf, short name_len, t_dasm *dasm)
{
	char			*dst;
	short			len;

	if (!buf || !dasm)
		return (NULL);
	len = 0;
	while (len < name_len && buf[len])
		len++;
	if (!(dst = ft_strnew(len + 1)))
		return (NULL);
	ft_memcpy(dst, buf, (size_t)len);
	while (len < name_len)
	{
		if (buf[len])
		{
			free(dst);
			return (NULL);
		}
		len++;
	}
	return (dst);
}

static unsigned char	*allocate_code(unsigned char *buf, int len, \
		t_dasm *dasm)
{
	unsigned char	*dst;

	if (!buf || !dasm)
		return (NULL);
	if (!(dst = (unsigned char *)ft_strnew(len + 1)))
		return (NULL);
	ft_memcpy(dst, buf, (size_t)len);
	return (dst);
}

static int				extract_metadata(void *void_ptr, t_dasm *dasm)
{
	t_content		*cont;
	unsigned char	*ptr;
	int				i;

	if (!void_ptr || !dasm)
		return (free_and_return(dasm, "Error: extract met. - empty ptr found"));
	cont = (t_content *)void_ptr;
	if (cont->null_zone_1 != 0 || cont->null_zone_2 != 0 || \
			(int)(cont->magic) != MAGIC_HEADER)
	{
		return (free_and_return(dasm, \
			"Error: file was damaged (check magic header or null zones)"));
	}
	if (!(dasm->name = allocate_this(cont->name, PROG_NAME_LENGTH, dasm)))
		return (free_and_return(dasm, "Error: extract metadata - empty ptr"));
	if (!(dasm->comment = allocate_this(cont->comment, COMMENT_LENGTH, dasm)))
		return (free_and_return(dasm, "Error: extract metadata - empty ptr"));
	dasm->codesize = 0;
	ptr = ((unsigned char *)void_ptr) + 8 + PROG_NAME_LENGTH;
	i = -1;
	while (++i < CHAMP_EXEC_CODE_SIZE)
		dasm->codesize = ((dasm->codesize << 8) + (size_t)ptr[i]);
	if (dasm->codesize < 0)
		return (free_and_return(dasm, "Error: codesize error"));
	return (0);
}

int						reader(char *filename, t_dasm *dasm)
{
	char			*buf[BUFF_SIZE];
	int				ret;
	int				code_index;

	if (!dasm)
		return (free_and_return(dasm, "Error: reader - empty ptr found"));
	ret = read(dasm->fd_i, buf, BUFF_SIZE);
	if (ret < 12 + PROG_NAME_LENGTH + CHAMP_EXEC_CODE_SIZE + COMMENT_LENGTH)
	{
		fprint("Error: file '%s' has too small size\n", filename);
		return (free_and_return(dasm, NULL));
	}
	if (extract_metadata(buf, dasm) == -1)
		return (-1);
	code_index = 12 + PROG_NAME_LENGTH + CHAMP_EXEC_CODE_SIZE + \
			COMMENT_LENGTH;
	if (!(dasm->code = allocate_code(&((unsigned char *)buf)[code_index], \
			dasm->codesize, dasm)))
		return (free_and_return(dasm, "Error: reader - empty ptr found"));
	return (0);
}
