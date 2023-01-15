CC		= g++
# CC		= c++
# FLAGS	= -Wall -Wextra -Werror -std=c++98
FLAGS	= -g -Wall -Wextra
# FLAGS	= -g

EXT		= .out
RM		= rm -rf

NAME		= 	webserv
NAME_EXT	= 	${NAME}${EXT}

S		=	src
O		=	obj

SRCS		=	main.cpp Socket.cpp
# SRCS_std	=	main_orig.cpp

SRCS	:=	$(foreach file,$(SRCS),$S/$(file))

OBJS	= ${SRCS:$S/%.cpp=$O/%.o}
DEP		= ${OBJS:$O/%.o=$O/%.d}

all		: ${NAME_EXT}

${NAME_EXT}	:	${OBJS}
	${CC} ${FLAGS} $^ -o $@

$O		:
	@mkdir $@

$O/%.o		:	$S/%.cpp | $O
	${CC} ${FLAGS} -MMD -c $< -o $@

-include ${DEP}

#!--DEBUG

ARGS	= 0

run		:	${NAME_EXT}
	@echo
	@./$^  ${ARGS}

debug	:	${NAME_EXT}
	@lldb -- ./$^ ${ARGS}

leaks	:	${NAME_EXT}
	@leaks --atExit -- ./$^  ${ARGS}

all_tests : ${NAME_TEST}

${NAME_TEST} : ${OBJS}

#!--DEBUG

clean	:
	${RM} $O

fclean	: clean
	${RM} ${NAME_EXT}

re		: fclean all

.PHONY : all clean fclean re norm run debug
