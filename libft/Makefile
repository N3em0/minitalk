# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 17:59:37 by teatime           #+#    #+#              #
#    Updated: 2025/04/23 22:03:10 by egache           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEAD	        :=	include/libft.h

NAME            :=	libft.a

SRC_DIR         :=  src
SRC             :=      \
ft_atoi.c               \
ft_bzero.c              \
ft_calloc.c             \
ft_isalnum.c            \
ft_isalpha.c            \
ft_isascii.c            \
ft_isdigit.c            \
ft_isprint.c            \
ft_itoa.c               \
ft_memchr.c             \
ft_memcmp.c             \
ft_memcpy.c             \
ft_memmove.c            \
ft_memset.c             \
ft_putchar_fd.c         \
ft_putendl_fd.c         \
ft_putnbr_fd.c          \
ft_putstr_fd.c          \
ft_split.c              \
ft_strchr.c             \
ft_strdup.c             \
ft_striteri.c           \
ft_strjoin.c            \
ft_strlcat.c            \
ft_strlcpy.c            \
ft_strlen.c             \
ft_strmapi.c            \
ft_strncmp.c            \
ft_strnstr.c            \
ft_strrchr.c            \
ft_strtrim.c            \
ft_substr.c             \
ft_tolower.c            \
ft_toupper.c            \
ft_lstadd_back.c        \
ft_lstadd_front.c       \
ft_lstclear.c           \
ft_lstdelone.c          \
ft_lstiter.c            \
ft_lstlast.c            \
ft_lstmap.c             \
ft_lstnew.c             \
ft_lstsize.c            \

SRC             := $(SRC:$(SRC_DIR)/%=$(SRC_DIR)/%)

BUILD_DIR       :=  .build
OBJ	            :=	$(SRC:%.c=$(BUILD_DIR)/%.o)
DEP				:=	$(OBJ:%.o=.d)

AR	            :=	ar -rcs

CC	            :=	cc
FLAGS	        :=	-Wall -Wextra -Werror
INCLUDE			:=	-MMD -MP -Iinclude

MAKEFLAGS       :=  --no-print-directory

DIR_DUP			=	mkdir -p $(@D)

RM				:=	rm -f
RMF				:=	rm -rf

all             :	$(NAME)

$(NAME)			:	$(OBJ) $(HEAD)
			$(AR) $(NAME) $(OBJ)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
			$(DIR_DUP)
			$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

-include $(DEP)

clean 			:
			$(RMF) $(BUILD_DIR)

fclean			:	clean
			$(RM) $(NAME)

re				:
			$(MAKE) fclean
			$(MAKE) all

.PHONY			:	all clean fclean re

#.SILENT			:
