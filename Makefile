# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 12:46:18 by pmeising          #+#    #+#              #
#    Updated: 2022/07/28 09:53:15 by pmeising         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap

CHECKER		:= checker

CC			:= gcc

CFLAGS		:= -Werror -Wextra -Wall

RM			:= rm -f

HEADER		:= pushswap.h
			
SRCS	:= ./operations/operations.c			\
			./operations/push.c					\
			./operations/rev_rotate.c				\
			./operations/rotate.c					\
			./operations/swap.c					\
			./sorting/ft_lis_to_b_2.c				\
			./sorting/ft_lis_to_b.c				\
			./sorting/ft_longest_increasing_subsequence.c	\
			./sorting/ft_optimize.c				\
			./sorting/ft_put_sorted.c				\
			./sorting/ft_sort_back_in_2.c			\
			./sorting/ft_sort_back_in.c			\
			./sorting/ft_sort.c					\
			./sorting/ft_switch.c					\
			./sorting/optimize.c					\
			./sorting/ft_helper.c					\
			./sorting/ft_helper_2.c					\
			./sorting/ft_sort_short.c				\
			./utils/main.c						\
			./utils/ft_atolonglong.c				\
			./utils/ft_del_lst.c					\
			./utils/ft_error.c					\
			./utils/ft_lstadd_back.c				\
			./utils/ft_lstadd_front.c				\
			./utils/ft_lstclear.c					\
			./utils/ft_lstdelone.c				\
			./utils/ft_lstiter.c					\
			./utils/ft_substr.c					\
			./utils/ft_lstlast.c					\
			./utils/ft_lstnew.c					\
			./utils/ft_lstsize.c					\
			./utils/ft_split.c					\
			./utils/ft_strchr.c					\
			./utils/ft_strdup.c					\
			./utils/ft_strlen.c					\

B_SRCS	:=	./bonus/bonus_main.c				\
			./bonus/ft_helper_bonus.c			\
			./bonus/bonus_operations.c			\
			./bonus/get_next_line.c				\
			./bonus/get_next_line_utils.c		\
			./operations/operations.c			\
			./operations/push.c					\
			./operations/rev_rotate.c				\
			./operations/rotate.c					\
			./operations/swap.c					\
			./sorting/ft_lis_to_b_2.c				\
			./sorting/ft_lis_to_b.c				\
			./sorting/ft_longest_increasing_subsequence.c	\
			./sorting/ft_optimize.c				\
			./sorting/ft_put_sorted.c				\
			./sorting/ft_sort_back_in_2.c			\
			./sorting/ft_sort_back_in.c			\
			./sorting/ft_sort.c					\
			./sorting/ft_switch.c					\
			./sorting/optimize.c					\
			./sorting/ft_helper.c					\
			./sorting/ft_helper_2.c					\
			./utils/ft_atolonglong.c				\
			./utils/ft_del_lst.c					\
			./utils/ft_error.c					\
			./utils/ft_lstadd_back.c				\
			./utils/ft_lstadd_front.c				\
			./utils/ft_lstclear.c					\
			./utils/ft_lstdelone.c				\
			./utils/ft_lstiter.c					\
			./utils/ft_substr.c					\
			./utils/ft_lstlast.c					\
			./utils/ft_lstnew.c					\
			./utils/ft_lstsize.c					\
			./utils/ft_split.c					\
			./utils/ft_strchr.c					\
			./utils/ft_strdup.c					\
			./utils/ft_strlen.c					\
			./utils/ft_calloc.c					\


OBJS		:= ${SRCS:.c=.o}

B_OBJS		:= ${B_SRCS:.c=.o}

.PHONY:		all clean fclean re

all:		${NAME} bonus

$(NAME):	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${SRCS}

$(CHECKER):	${B_OBJS}

bonus:		$(CHECKER)
			${CC} ${CFLAGS} -o ${CHECKER} ${B_SRCS}

re:			fclean all

clean:
			$(RM) $(OBJS) $(B_OBJS)

fclean:		clean
			$(RM) $(NAME) $(CHECKER)
