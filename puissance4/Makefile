### ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2014/03/28 01:03:05 by elhmn             #+#    #+#             ##
##   Updated: 2014/03/28 01:03:05 by elhmn            ###   ########.fr       ##
##                                                                            ##
## ########################################################################## ##

NAME= puissance4

FLAGS= -Wall -Werror -Wextra

LIBS= -L./libft -lft

INCLUDES= -I ./includes/

CC=gcc

SRC= eval.c ft_error.c gametools.c minimax.c tab_tools.c win.c \
		ft_check_data.c ft_tab.c main.c mode_tools.c tools.c win_diag.c
OBJ= $(SRC:.c=.o)

SRCDIR= ./srcs/
OBJDIR= ./objs/

SRCS= $(addprefix $(SRCDIR), $(SRC))
OBJS= $(addprefix $(OBJDIR), $(OBJ))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBS)

$(OBJS): $(SRCS)
	make -C libft/
	$(CC) $(FLAGS) $(INCLUDES) -c $(SRCS)
	mv $(OBJ) $(OBJDIR)

clean:
	make clean -C libft/
	rm -rf $(OBJS)

fclean: clean
	make fclean -C libft/
	rm -rf $(NAME)

re: fclean all
