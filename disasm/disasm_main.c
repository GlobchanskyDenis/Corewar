/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disasm_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:53:48 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/02/15 18:21:12 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

static int	allocate_output_name(char *filename, t_dasm *dasm)
{
	int		len;

	if (!filename || !dasm)
	{
		if (dasm)
			free(dasm);
		fprint("Error: open file - empty ptr found\n");
		return (-1);
	}
	len = ft_strlen(filename);
	if (!(dasm->filename = (char *)ft_memalloc(sizeof(char) * (len - 1))))
	{
		fprint("Error: allocate output name - memalloc returned null\n");
		return (-1);
	}
	ft_memcpy(dasm->filename, filename, (size_t)(len - 2));
	dasm->filename[len - 3] = 's';
	return (0);
}

static int	open_input_file(char *filename, t_dasm *dasm)
{
	char	buf;

	if (!filename || !dasm)
	{
		if (dasm)
			free(dasm);
		fprint("Error: open file - empty ptr found\n");
		return (-1);
	}
	dasm->fd_i = open(filename, O_RDONLY);
	if (dasm->fd_i < 3)
	{
		fprint("Warning: can't open file %s\n", filename);
		return (-1);
	}
	if (read(dasm->fd_i, &buf, 0) < 0)
	{
		fprint("Warning: can't read file %s\n", filename);
		return (-1);
	}
	return (0);
}

static int	open_output_file(char *filename, t_dasm *dasm)
{
	char	buf;

	if (!filename || !dasm)
	{
		if (dasm)
			free(dasm);
		fprint("Error: open file - empty ptr found\n");
		return (-1);
	}
	dasm->fd_o = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 511);
	if (dasm->fd_o < 3)
	{
		fprint("Warning: can't open file %s\n", filename);
		return (-1);
	}
	if (write(dasm->fd_o, &buf, 0) < 0)
	{
		fprint("Warning: can't write file %s\n", filename);
		return (-1);
	}
	return (0);
}

static int	check_args(int ac, char **av)
{
	short	len;

	if (ac != 2)
	{
		fprint("Usage: ./disasm champfile.cor\n");
		return (-1);
	}
	len = ft_strlen(av[1]);
	if (len < 5 || av[1][len - 4] != '.' || av[1][len - 3] != 'c' || \
			av[1][len - 2] != 'o' || av[1][len - 1] != 'r')
	{
		fprint("Warning: filename must be *.cor\n");
		return (-1);
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_dasm	*dasm;

	if (check_args(ac, av) == -1)
		return (-1);
	if (!(dasm = (t_dasm *)ft_memalloc(sizeof(t_dasm))))
	{
		fprint("Error: main - memalloc returned null\n");
		return (-1);
	}
	if (allocate_output_name(av[1], dasm) == -1 || \
			open_input_file(av[1], dasm) == -1 || \
			open_output_file(dasm->filename, dasm) == -1 || \
			reader(av[1], dasm) == -1)
		return (-1);
	fprint_fd(dasm->fd_o, "%s \"%s\"\n%s \"%s\"\n\n", NAME_CMD_STRING, \
			dasm->name, COMMENT_CMD_STRING, dasm->comment);
	if (translate(dasm) == -1)
		return (-1);
	free_dasm(dasm);
	return (0);
}
