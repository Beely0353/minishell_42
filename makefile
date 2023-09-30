RED		=	\033[31m
GRE		=	\033[32m
BLU		=	\033[36m
YEL		=	\033[33m
EOC		=	\033[0m
BEI		=	\033[38;5;223m

DEF		=	\033[0m
BOLD	=	\033[1m
CUR		=	\033[3m
UL		=	\033[4m
UP		=	\033[A

NAME		=	minishell

SOURCES		=	./sources
INCLUDES	=	./includes
OBJECTS		=	./bin

SRCS 		=	minishell.c\
				$(addprefix lexer/, lexer.c lexer_utils1.c lexer_utils2.c lexer_utils3.c lexer_utils4.c)\
				$(addprefix parsing/, init.c parse_env.c which_cmd.c parse_tokens.c)\
				$(addprefix cmd/, cd.c clear.c echo.c env.c exit.c export.c history.c pwd.c unset.c)\
				$(addprefix utils/, memory.c memory2.c string.c string2.c string3.c string4.c string5.c utils.c lst.c env.c)\
				$(addprefix error/, error1.c)\
				$(addprefix validator/, validator.c)\
				$(addprefix tools/, expander.c expander2.c)\
				$(addprefix executor/, executor.c)


OBJS		=	$(addprefix ${OBJECTS}/, $(SRCS:.c=.o))

CFLAGS		=	-Wall -Wextra -Werror -Iincludes -g
CC			=	gcc
CINCLUDES	=	-I ${INCLUDES}
LINK		=	libreadline.a -lreadline -lncurses
# ---------------------------------------------------------------------------- #

SRCS_COUNT = 0
SRCS_TOT = ${shell find ./sources/ -type f -name '*.c' | wc -l}
SRCS_PRCT = ${shell expr 100 \* ${SRCS_COUNT} / ${SRCS_TOT}}
BAR =  ${shell expr 23 \* ${SRCS_COUNT} / ${SRCS_TOT}}

${OBJECTS}/%.o: ${SOURCES}/%.c
	@${eval SRCS_COUNT = ${shell expr ${SRCS_COUNT} + 1}}
	@mkdir -p $(dir $@)
	@${CC} ${CFLAGS} -o $@ -c $< ${CINCLUDES}
	@echo ""
	@echo "\r\033[K -> Compilation de ""$(YEL)${notdir $<}$(EOC). ⏳"
	@printf "   ${BEI}[%-23.${BAR}s] [%d/%d (%d%%)]${DEF}" "***********************" ${SRCS_COUNT} ${SRCS_TOT} ${SRCS_PRCT}
	@echo "${UP}${UP}${UP}"

all: start ${NAME}

rl:
	@echo "⏳ Creation de $(YEL)libreadline$(EOC). ⏳"
	@curl -ks https://ftp.gnu.org/gnu/readline/readline-8.1.tar.gz > readline-8.1.tar.gz
	@tar -xf readline-8.1.tar.gz 
	@mv readline-8.1 readline
	@rm -rf readline-8.1.tar.gz
	@mv readline includes
	@cd includes/readline/ && \
	./configure --prefix=$$(pwd)/includes/readline >> /dev/null && \
	make -s && make -s install && make -s clean && \
	cd ../../
	stty -echoctl
	@clear
	@echo "✅ $(GRE)Creation de libreadline terminée.$(EOC) ✅"

start:
	@if [ ! -d "includes/readline" ]; then make rl; fi
	@if [ ! -e "bin" ]; then \
		echo "🚀 Début de la compilation de $(BLU)${NAME} 🚀$(EOC)"; \
	else \
		echo "make: Nothing to be done for \`all'."; \
	fi

${NAME}: ${OBJS}
	@clear
	@echo "$(GRE)✅ Compilation terminée.$(EOC)"
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LINK} 

clean:
	@echo "🗑  $(RED)Supression des fichiers binaires (.o).$(EOC) 🗑"
	@rm -rf ${OBJECTS}

fclean: clean
	@echo "🗑  $(RED)Supression des executables et librairies.$(EOC) 🗑"
	@rm -f ${NAME}
	@rm -rf includes/readline
	@clear

re: fclean all

fcleanr: clean
	@echo "🗑  $(RED)Supression des executables et librairies.$(EOC) 🗑"
	@rm -f ${NAME}
	@clear

rer: fcleanr all

.PHONY:	all clean fclean re
