# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acossari <acossari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/06 12:24:26 by acossari          #+#    #+#              #
#    Updated: 2025/05/06 12:24:58 by acossari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# tests/Makefile — for local tests only

# Compiler settings
CC      =	cc
CFLAGS  =	-Wall -Wextra -Werror

# Path to libft static library and include directory
LIBFT   =	../libft.a
INC     =	-I ..

# Find all test source files and derive object names and targets
SRC     =	$(wildcard test_ft_*.c)
OBJ     =	$(SRC:.c=.o)
TARGET =	$(SRC:.c=)

# Default rule: build all test executables
all:	$(TARGET)

# Build each test executable, linking against libft.a
# $<  = the .o file, $@ = the target (executable)
%:	%.o $(LIBFT)
	ar rcs $(LIBFT) $(LIBFT)    # dummy archive update to enforce dependency
	$(CC) $(CFLAGS) $< $(LIBFT) -o $@

# Compile a .c file into a .o object
%.o:	%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Remove all generated object files and executables
clean:
	rm -f $(OBJ) $(TARGET)

.PHONY:	all clean
