# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 15:58:15 by egache            #+#    #+#              #
#    Updated: 2025/04/24 01:16:07 by egache           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBS		:=	ft printf
LIBS_TARGET	:=					\
	libft/libft.a				\
	ft_printf/libprintf.a		\

HEADER := include/minitalk.h	\

HEAD		:=					\
include							\
libft/include					\
ft_printf/include				\

NAME_CLIENT		:=	client
NAME_CLIENT_B	:=	client_b
NAME_SERVER		:=	server
NAME_SERVER_B	:=	server_b

SRC_DIR			:=	src

BUILD_DIR		:=	.build

SRC_SERVER		:=	server.c 		\
					del_int.c		\

SRC_SERVER		:=	$(SRC_SERVER:%=$(SRC_DIR)/%)
OBJ_SERVER		:=	$(SRC_SERVER:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEP_SERVER		:=	$(OBJ_SERVER:%.o=.d)

SRC_SERVER_B	:=	server_bonus.c	\
					del_int.c		\

SRC_SERVER_B	:=	$(SRC_SERVER_B:%=$(SRC_DIR)/%)
OBJ_SERVER_B	:=	$(SRC_SERVER_B:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEP_SERVER_B	:=	$(OBJ_SERVER_B:%.o=.d)

SRC_CLIENT		:=	client.c
SRC_CLIENT		:=	$(SRC_CLIENT:%=$(SRC_DIR)/%)
OBJ_CLIENT		:=	$(SRC_CLIENT:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEP_CLIENT		:=	$(OBJ_CLIENT:%.o=.d)

SRC_CLIENT_B	:=	client_bonus.c
SRC_CLIENT_B	:=	$(SRC_CLIENT_B:%=$(SRC_DIR)/%)
OBJ_CLIENT_B	:=	$(SRC_CLIENT_B:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEP_CLIENT_B	:=	$(OBJ_CLIENT_B:%.o=.d)



AR	:=	ar -rcs

CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror
INCLUDE	:=	$(addprefix -I,$(HEAD)) -MMD -MP
LIBDIR	:=	$(addprefix -L,$(dir $(LIBS_TARGET)))
LIBNAME	:=	$(addprefix -l,$(LIBS))

DIR_DUP	=	mkdir -p $(@D)

MAKEFLAGS	+= --no-print-directory

RM	:=	rm -f
RMF	:=	rm -rf

all:	$(NAME_CLIENT) $(NAME_SERVER)

bonus:	$(NAME_CLIENT_B) $(NAME_SERVER_B)

$(NAME_CLIENT)		:	$(OBJ_CLIENT) $(LIBS_TARGET) $(HEADER)
			$(CC) $(LIBDIR) $(OBJ_CLIENT) $(LIBNAME) -o $(NAME_CLIENT)

$(NAME_CLIENT_B)	:	$(OBJ_CLIENT_B) $(LIBS_TARGET) $(HEADER)
			$(CC) $(LIBDIR) $(OBJ_CLIENT_B) $(LIBNAME) -o $(NAME_CLIENT_B)

$(NAME_SERVER)		:	$(OBJ_SERVER) $(LIBS_TARGET) $(HEADER)
			$(CC) $(LIBDIR) $(OBJ_SERVER) $(LIBNAME) -o $(NAME_SERVER)

$(NAME_SERVER_B)	:	$(OBJ_SERVER_B) $(LIBS_TARGET) $(HEADER)
			$(CC) $(LIBDIR) $(OBJ_SERVER_B) $(LIBNAME) -o $(NAME_SERVER_B)

$(LIBS_TARGET)		: FORCE
			@$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o	:	$(SRC_DIR)/%.c
			$(DIR_DUP)
			$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<


-include $(DEP)

clean:
			$(RM) $(OBJ_CLIENT) $(OBJ_SERVER) $(DEP_CLIENT) $(DEP_SERVER) $(DEP_CLIENT_B) $(DEP_SERVER_B)
			$(RMF) $(BUILD_DIR)
			@$(MAKE) clean -C libft
			@$(MAKE) clean -C ft_printf

fclean:	clean
			$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_B) $(NAME_SERVER_B)
			@$(MAKE) fclean -C libft
			@$(MAKE) fclean -C ft_printf

re:
			@$(MAKE) fclean
			@$(MAKE) all


FORCE :

.PHONY:	all clean fclean FORCE re
