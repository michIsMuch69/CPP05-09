# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: michismuch <michismuch@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 14:38:21 by jedusser          #+#    #+#              #
#    Updated: 2025/03/22 10:30:23 by michismuch       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -g3 -std=c++98 -MMD -MP

SRC_DIR = .
OBJ_DIR = obj

NAME = second-ex

SRCS = main.cpp \
		Bureaucrat.cpp \
		Form.cpp
       

OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Building $(NAME)"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp Makefile
	@echo "Compiling $< to $@"
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re