# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acossari <acossari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/06 12:24:26 by acossari          #+#    #+#              #
#    Updated: 2025/05/07 12:00:56 by acossari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# tests/Makefile — for local tests only; do NOT submit this file

# 1) Disable all built-in suffix rules so we only use our explicit ones
.SUFFIXES:

# 2) Compiler settings (include parent dir for libft.h)
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -I ..

# 3) Path to your compiled libft library
LIBFT	=	../libft.a

# 4) Gather all test sources and derive object + binary names
SRC		=	$(wildcard test_ft_*.c)
OBJ		=	$(SRC:.c=.o)
BIN		=	$(SRC:.c=)

.PHONY: all clean

# 5) Default target: build every test executable
all:	$(BIN)

# 6) Link each test binary against libft.a
#    “test_ft_atoi” depends on “test_ft_atoi.o” and “../libft.a”
test_ft_%: test_ft_%.o $(LIBFT)
	$(CC) $(CFLAGS) $< $(LIBFT) -o $@

# 7) Compile each .c into .o
%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

# 8) Clean up everything this Makefile generates
clean:
	rm -f $(OBJ) $(BIN)
