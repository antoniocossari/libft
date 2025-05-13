# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acossari <acossari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 16:21:57 by acossari          #+#    #+#              #
#    Updated: 2025/05/13 12:53:57 by acossari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the static library to create
NAME	=	libft.a

# Compiler to use
CC	=	cc

# Compiler flags:
#   -Wall   : enable all warnings
#   -Wextra : enable extra warnings
#   -Werror : treat warnings as errors
CFLAGS	=	-Wall -Wextra -Werror

# Mandatory source files (.c)
SRCS	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
	ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
	ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
	ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c

# Object files (.o) for mandatory sources
OBJS	=	$(SRCS:.c=.o)

# Bonus source files (.c) for linked-list functions
BONUS_SRCS	=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

# Object files (.o) for bonus sources
BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

# Default target: builds the library when you run `make`
all:	$(NAME)

# Automatic variables:
#	$@ expands to the current target
#	$^ expands to all prerequisites
#	$< expands to the first prerequsite

# Rule to create the library archive from object files
#	r: replace or insert files into the archive
#	c: create the archive if it doesn’t exist
#	s: write an index (symbol table) for faster linking
$(NAME):	$(OBJS)
	ar rcs $@ $^

# Rule to build the library including bonus objects
bonus:	$(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $^

# Pattern rule: compile any .c into corresponding .o
#	% is make’s pattern metacharacter capturing the “stem” (base filename)
#	for each stem.c it generates stem.o in a 1:1 correspondence

# Compiler flags:
#	-c: compile only: generate .o files without linking
#	-o: specify output file name for the generated file
%.o:	%.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

# Remove all object files (mandatory and bonus)
# 	-f: suppresses errors if files are missing
clean:
	rm -f $(OBJS) $(BONUS_OBJS)

# Remove object files and the library
fclean:	clean
	rm -f $(NAME)

# Rebuild everything from scratch
re:	fclean all

# Declare phony targets (not real files)
.PHONY:	all clean fclean re bonus
