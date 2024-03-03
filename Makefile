# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egolboyu <egolboyu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/02 14:28:15 by egolboyu          #+#    #+#              #
#    Updated: 2024/03/03 17:59:43 by egolboyu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S = server
NAME_C = client
NAME_BS = server_bonus
NAME_BC = client_bonus

CFLAGS = -Wall -Wextra -Werror

SRCS_S = server.c
SRCS_C = client.c
SRCS_BS = server_bonus.c
SRCS_BC = client_bonus.c
SRCS = ft_printf.c ft_atoi.c ft_strlen.c

OBJS_SRCS = $(SRCS:.c=.o)
OBJS_S = $(SRCS_S:.c=.o) $(OBJS_SRCS)
OBJS_C = $(SRCS_C:.c=.o) $(OBJS_SRCS)
OBJS_BS = $(SRCS_BS:.c=.o) $(OBJS_SRCS)
OBJS_BC = $(SRCS_BC:.c=.o) $(OBJS_SRCS)

RED = \033[91;1m
GREEN = \033[92;1m
YELLOW = \033[93;1m
BLUE = \033[94;1m
PINK = \033[95;1m
CLEAR = \033[0m

all: $(NAME_S) $(NAME_C)
	@echo "$(BLUE)Make all$(CLEAR)"
	@echo "$(PINK)Compiling server and client...$(CLEAR)"
	@gcc $(CFLAGS) $(OBJS_S) -o $(NAME_S)
	@gcc $(CFLAGS) $(OBJS_C) -o $(NAME_C)
	@echo "$(GREEN)Compilation successful!$(CLEAR)"
	@echo "$(YELLOW)Finished$(CLEAR)"

bonus: $(NAME_BS) $(NAME_BC)
	@echo "$(BLUE)Make bonus$(CLEAR)"
	@echo "$(PINK)Compiling bonus server and client...$(CLEAR)"
	@gcc $(CFLAGS) $(OBJS_BS) -o $(NAME_BS)
	@gcc $(CFLAGS) $(OBJS_BC) -o $(NAME_BC)
	@echo "$(GREEN)Compilation successful!$(CLEAR)"
	@echo "$(YELLOW)Finished$(CLEAR)"

$(NAME_S): $(OBJS_S)
	@echo "$(BLUE)Compiling $(NAME_S)$(CLEAR)"
	@gcc $(CFLAGS) $(OBJS_S) -o $(NAME_S)

$(NAME_C): $(OBJS_C)
	@echo "$(BLUE)Compiling $(NAME_C)$(CLEAR)"
	@gcc $(CFLAGS) $(OBJS_C) -o $(NAME_C)

$(NAME_BS): $(OBJS_BS)
	@echo "$(BLUE)Compiling $(NAME_BS)$(CLEAR)"
	@gcc $(CFLAGS) $(OBJS_BS) -o $(NAME_BS)

$(NAME_BC): $(OBJS_BC)
	@echo "$(BLUE)Compiling $(NAME_BC)$(CLEAR)"
	@gcc $(CFLAGS) $(OBJS_BC) -o $(NAME_BC)

clean:
	@echo "$(BLUE)Make clean$(CLEAR)"
	@echo "$(RED)Removing object files...$(CLEAR)"
	@rm -rf $(OBJS_SRCS) $(OBJS_S) $(OBJS_C) $(OBJS_BS) $(OBJS_BC)
	@echo "$(GREEN)Cleanup successful!$(CLEAR)"
	@echo "$(YELLOW)Finished$(CLEAR)"

fclean: clean
	@echo "$(BLUE)Make fclean$(CLEAR)"
	@echo "$(RED)Removing executables...$(CLEAR)"
	@rm -rf $(NAME_S) $(NAME_C) $(NAME_BS) $(NAME_BC)
	@echo "$(GREEN)Cleanup successful!$(CLEAR)"
	@echo "$(YELLOW)Finished$(CLEAR)"

re: fclean all

.PHONY: all clean fclean re bonus
