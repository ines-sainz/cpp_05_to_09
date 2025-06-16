# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 12:31:37 by isainz-r          #+#    #+#              #
#    Updated: 2025/01/15 12:31:39 by isainz-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Set the name of the output binary
NAME = bureaucrats

# Specify the compiler to use
CC = c++

# Compiler flags: show all warnings, treat warnings as errors, and enable extra warnings
# -std=c++98 to enforce the C++98 standard
CFLAGS = -Wall -Werror -Wextra #-std=c++98

# Source files
SRCS = main.cpp Bureaucrat.cpp

# Object files, replacing .cpp with .o
OBJS = $(SRCS:.cpp=.o)

# Default rule: build the target defined in $(NAME)
all: $(NAME)

# Rule to create the binary: compile object files into executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

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
