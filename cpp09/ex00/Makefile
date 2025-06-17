# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/19 17:13:12 by isainz-r          #+#    #+#              #
#    Updated: 2025/02/19 17:13:15 by isainz-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Set the name of the output binary
NAME = btc

# Specify the compiler to use
CC = c++

# Compiler flags: show all warnings, treat warnings as errors, and enable extra warnings
# -std=c++98 to enforce the C++98 standard
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g3

# Source files
SRCS = main.cpp BitcoinExchange.cpp

# Object files, replacing .cpp with .o
OBJS = $(SRCS:.cpp=.o)

# Pattern rule: how to build a .o file from a .cpp file
%.o: %.cpp
	$(CC) $(CFLAGS) -I . -c $< -o $@

# Default rule: build the target defined in $(NAME)
all: $(NAME)

# Rule to create the binary: compile object files into executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I . -o $(NAME) $(OBJS)

# Rule to remove object files
clean:
	rm -rf $(OBJS)

# Rule to remove object files and the binary
fclean: clean
	rm -rf $(NAME)

# Rule to recompile everything from scratch
re: fclean all

# Declare these targets as phony (not actual files)
.PHONY: clean fclean re all
