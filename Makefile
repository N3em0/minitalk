# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 15:58:15 by egache            #+#    #+#              #
#    Updated: 2025/03/28 18:25:29 by egache           ###   ########.fr        #
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

NAME_CLIENT	:=	client
NAME_SERVER :=	server

SRC_DIR		:=	src
SRC_SERVER	:=	server.c
SRC_CLIENT	:=	client.c

SRC_CLIENT	:=	$(SRC_CLIENT:%=$(SRC_DIR)/%)
SRC_SERVER	:=	$(SRC_SERVER:%=$(SRC_DIR)/%)


BUILD_DIR:=	.build
OBJ_CLIENT	:=	$(SRC_CLIENT:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJ_SERVER	:=	$(SRC_SERVER:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEP_CLIENT	:=	$(OBJ_CLIENT:%.o=.d)
DEP_SERVER	:=	$(OBJ_SERVER:%.o=.d)

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

BOLDGREEN	:= \e[1;32m
BOLDBLUE 	:= \033[1;34m
YELLOW		:= \033[1;93m
WHITE 		:= \033[0m
BLUE		:= \033[0;34m
PURPLE		:= \e[1;35m

all:		.printsep $(NAME_CLIENT) $(NAME_SERVER)
			echo "$(BOLDBLUE)$(NAME) $(WHITE)compilation $(BOLDGREEN)done"
			$(call SEPARATOR)

$(NAME_CLIENT)	:	$(OBJ_CLIENT) $(LIBS_TARGET) $(HEADER)
			$(CC) $(LIBDIR) $(OBJ_CLIENT) $(LIBNAME) -o $(NAME_CLIENT)
			echo "$(BOLDBLUE)$(NAME_CLIENT) $(WHITE)compilation $(BOLDGREEN)done"
			$(call SEPARATOR)

$(NAME_SERVER)	:	$(OBJ_SERVER) $(LIBS_TARGET) $(HEADER)
			$(CC) $(LIBDIR) $(OBJ_SERVER) $(LIBNAME) -o $(NAME_SERVER)
			echo "$(BOLDBLUE)$(NAME_SERVER) $(WHITE)compilation $(BOLDGREEN)done"
			$(call SEPARATOR)

$(LIBS_TARGET)	: FORCE
			$(MAKE) -C $(@D)
			@echo "$(BOLDBLUE)$(@D) $(WHITE)library $(BOLDGREEN)done"

$(BUILD_DIR)/%.o:	$(SRC_DIR)/%.c
			$(DIR_DUP)
			$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<


-include $(DEP)

clean:
			$(RM) $(OBJ_CLIENT) $(OBJ_SERVER) $(DEP_CLIENT) $(DEP_SERVER)
			$(RMF) $(BUILD_DIR)
			$(MAKE) clean -C libft
			$(MAKE) clean -C ft_printf

fclean:	clean
			$(call SEPARATOR)
			echo "$(BOLDBLUE)$(NAME) $(WHITE)fclean  $(YELLOW)..."
			$(RM) $(NAME_CLIENT) $(NAME_SERVER)
			$(MAKE) fclean -C libft
			$(MAKE) fclean -C ft_printf
			$(call SEPARATOR)
			echo "$(BOLDBLUE)$(NAME) $(WHITE)fclean  $(BOLDGREEN)done"

re:
			$(MAKE) fclean
			$(MAKE) all

.printsep:
			$(call SEPARATOR)

FORCE :

.PHONY:	all clean fclean FORCE re

#.SILENT:

define	SEPARATOR
						@echo "\n$(PURPLE)--------------------------\n";
endef
