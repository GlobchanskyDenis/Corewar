/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstokes <jstokes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:04:48 by jstokes           #+#    #+#             */
/*   Updated: 2020/02/15 14:27:50 by jstokes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "libft.h"
# include <sys/stat.h>

# define MEM_ALLOC ": memory can't be allocated\n"
# define ERR_BS ": bad symbols in a line or no new line at the end\n"
# define SIM_LAB ": two similar labels for distinct operations\n"
# define OPS_NUM 16
# define BUFF_SIZE	100
# define MAX_INT	2147483647

typedef struct	s_text
{
	char	*text;
	size_t	tmp;
}				t_text;

typedef struct	s_op
{
	char		*com;
	size_t		com_len;
	int			vars_num;
	int			ind;
	char		var[3];
}				t_op;

typedef struct	s_lop
{
	t_list			*labels;
	t_op			*op;
	t_arg_type		at[3];
	int				value[3];
	char			*label[3];
	struct s_lop	*lop[3];
	size_t			size;
	struct s_lop	*next;
}				t_lop;

typedef struct	s_asm
{
	t_header	*header;
	char		*s_name;
	char		*cor_name;
	int			s_fd;
	int			cor_fd;
	char		name_read;
	char		comment_read;
	t_op		ops[17];
	t_text		*text;
	t_lop		*lops;
	t_lop		*tmp_lop;
	size_t		full_len;
	char		*line;
	char		**split;
}				t_asm;

void			analize_name(char *name);

/*
** FT_ASM
*/
void			ft_asm(char *name);
char			is_comment(char *str);
char			get_name_n_comment(t_asm *tasm);
char			read_ops(t_asm *tasm);
char			replace_labels(t_asm *tasm);
char			print_result(t_asm *tasm);
char			check_all_labels(t_asm *tasm);
char			check_op(t_asm *tasm, char label_read);
char			check_label(t_asm *tasm);
size_t			count_seps_n_blocks(char *str, char **tmp);

/*
** FT_DEASM
*/
void			ft_deasm(char *name);

/*
** PRINT_FUNCS
*/
void			print_usage(void);
void			error(t_asm *tmp_asm, char *err);
char			error0(t_asm *tmp_asm, char *err);
char			*errornull(t_asm *tasm, char *err);
void			clean_n_error(char **line,
						char ***tmp, t_asm *tmp_asm, char *err);
char			clean_n_error0(char **line,
						char ***tmp, t_asm *tmp_asm, char *err);
size_t			get_size(t_arg_type type, int ind);
char			get_num(char *var, int *num);
void			print_num(t_asm *tasm, int num, size_t size);

/*
** INIT_FUNCS
*/
void			init_asm(t_asm *tmp_asm);
char			init_ops(t_op *ops);
char			init_text(t_asm *tmp_asm);

/*
** CLEAN_FUNCS
*/
void			clean_asm(t_asm *tmp_asm);

/*
** READ_FUNCS
*/
char			*skip_sp_tab(char *str);
char			*go_to_next_line(char *cur, t_text *text);
char			skip_comments(t_asm *tasm);
char			read_while_no_char(t_asm *tmp_asm, char c);
char			**strsplitestsep(char *s);
char			check_op(t_asm *tasm, char label_read);
char			analize_var(char *var, t_lop *tmp, size_t i);

/*
** LOP_FUNCS
*/
t_lop			*lop_new(void);
void			*create_tmp_lop(t_asm *tasm);
void			*lop_add_label(t_lop *lop, char **label);
t_lop			*lop_add_end(t_lop **lops, t_lop **new);

#endif
