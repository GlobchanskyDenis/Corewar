# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/26 16:00:22 by bsabre-c          #+#    #+#              #
#    Updated: 2020/02/13 19:01:34 by bsabre-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	libft.a
FLAGS 	=	-g -Wall -Wextra -Werror
DIR_O 	=	objects

FILES 	=	ft_atoi.c		ft_atoll.c		ft_countwords.c	\
			ft_bzero.c		ft_isalnum.c	ft_isalpha.c	ft_isascii.c	\
			ft_isdigit.c	ft_isprint.c	ft_itoa.c		ft_lltoa.c		\
			ft_lstadd.c		ft_lstdel.c		ft_lstdelone.c	ft_lstiter.c	\
			ft_lstmap.c		ft_lstnew.c		ft_memalloc.c	ft_memccpy.c	\
			ft_memchr.c		ft_memcmp.c		ft_memcpy.c		ft_memdel.c		\
			ft_memmove.c	ft_memset.c		ft_putchar.c	ft_putchar_fd.c	\
			ft_putendl.c	ft_putendl_fd.c	ft_putnbr.c		ft_putnbr_fd.c	\
			ft_putnbrll.c	ft_putstr.c		ft_putstr_fd.c	ft_strcat.c		\
			ft_strchr.c		ft_strclr.c		ft_strcmp.c		ft_strcpy.c		\
			ft_strdel.c		ft_strdup.c		ft_strequ.c		ft_striter.c	\
			ft_striteri.c	ft_strjoin.c	ft_strlcat.c	ft_strlen.c		\
			ft_strmap.c		ft_strmapi.c	ft_strncat.c	ft_strncmp.c	\
			ft_strncpy.c	ft_strnequ.c	ft_strnew.c		ft_strnstr.c	\
			ft_strrchr.c	ft_strsplit.c	ft_strstr.c		ft_strsub.c		\
			ft_strtrim.c	ft_tolower.c	ft_toupper.c	ft_lstnew_fag.c	\
			ft_list_bublesort.c		ft_list_murgesort.c 	ft_wstrlen.c	\
			ft_putwchar_fd.c		ft_putwstrn_fd.c		ft_strupr.c		\
			ft_ulltoa_base.c		ft_putchar_fd_smpl.c	ft_lltoa_base.c	\
			ft_sqr_int.c			ft_sqr_ll.c				ft_sqr_szt.c	\
			ft_strnewc.c			ft_isall_hexdigit.c		ft_isall_digit.c\
			count_words.c			ft_lstdel_fag.c			ft_atoi_base.c	\
			ft_mini.c				ft_maxi.c				ft_minf.c		\
			ft_maxf.c				ft_mind.c				ft_maxd.c		\
			ft_minll.c				ft_maxll.c				ft_absi.c		\
			ft_absf.c				ft_absd.c				ft_absll.c		\
			ft_szttoa.c				fprint_specifiers.c		fprint.c		\
			fprint_string_operations.c										\
			ft_intcheck.c			ft_lstaddend.c			ft_strsplitdel.c\
			ft_lstdelstr.c

OBJECTS =	$(addprefix $(DIR_O)/,$(FILES:.c=.o))

$(NAME) : $(OBJECTS)
			@echo "Compiling libft files"
			@ar rc $(NAME) $(OBJECTS)
			@ranlib $(NAME)
			@echo "Done"

$(DIR_O)/%.o : %.c libft.h
			@mkdir -p $(DIR_O)
			@gcc $(FLAGS) -o $@ -c $<

clean :
			@echo "remove libft object files and some trash"
			@rm -f $(OBJECTS)
			@rm -rf $(DIR_O)
			@rm -rf .DS_Store
			@echo "Done"

fclean : clean
			@echo "remove $(NAME)"
			@rm -f $(NAME)

.PHONY: all, clean, fclean, re

all : $(NAME)

re: fclean all
