/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:55:38 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/02/15 18:52:42 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISASM_H

# define DISASM_H
# include "libft.h"
# include "op.h"

# define CHAMP_EXEC_CODE_SIZE	4
# define MAGIC_HEADER			-209458688
# define BUFF_SIZE				4058

/*
**	OPERATION CODES
*/

# define OP_LIVE				1
# define OP_LD					2
# define OP_ST					3
# define OP_ADD					4
# define OP_SUB					5
# define OP_AND					6
# define OP_OR					7
# define OP_XOR					8
# define OP_ZJMP				9
# define OP_LDI					10
# define OP_STI					11
# define OP_FORK				12
# define OP_LLD					13
# define OP_LLDI				14
# define OP_LFORK				15
# define OP_AFF					16

typedef struct		s_dasm
{
	int				fd_i;
	int				fd_o;
	char			*filename;
	char			*name;
	char			*comment;
	unsigned char	*code;
	int				codesize;
}					t_dasm;

typedef struct		s_content
{
	unsigned int	magic;
	char			name[PROG_NAME_LENGTH];
	unsigned int	null_zone_1;
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH];
	unsigned int	null_zone_2;
}					t_content;

typedef struct		s_arg
{
	int				val;
	int				size;
}					t_arg;

void				free_dasm(t_dasm *dasm);
void				print_code(unsigned char *code, int codesize);
int					free_and_return(t_dasm *dasm, char *message);
int					reader(char *filename, t_dasm *dasm);
int					translate(t_dasm *dasm);
char				*ft_strjoin_free1(char *str1, char *str2);
char				*ft_strjoin_free2(char *str1, char *str2);
short				get_arg_size(unsigned char byte, short op_code);
int					get_bytes(unsigned char *code, int start, int len, \
		t_dasm *dasm);

/*
**	OPERATIONS
*/

void				operation_live(t_dasm *dasm, int position, int *step);
void				operation_ld(t_dasm *dasm, int position, int *step);
void				operation_st(t_dasm *dasm, int position, int *step);
void				operation_add(t_dasm *dasm, int position, int *step);
void				operation_sub(t_dasm *dasm, int position, int *step);
void				operation_and(t_dasm *dasm, int position, int *step);
void				operation_or(t_dasm *dasm, int position, int *step);
void				operation_xor(t_dasm *dasm, int position, int *step);
void				operation_zjmp(t_dasm *dasm, int position, int *step);
void				operation_ldi(t_dasm *dasm, int position, int *step);
void				operation_sti(t_dasm *dasm, int position, int *step);
void				operation_fork(t_dasm *dasm, int position, int *step);
void				operation_lld(t_dasm *dasm, int position, int *step);
void				operation_lldi(t_dasm *dasm, int position, int *step);
void				operation_lfork(t_dasm *dasm, int position, int *step);
void				operation_aff(t_dasm *dasm, int position, int *step);

#endif
