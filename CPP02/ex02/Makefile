NAME = MaintenantOnPeutParler

C_FILES = main.cpp\
	Fixed.cpp

CFLAGS = -Wall -Werror -Wextra -std=c++98

C_TYPE = c++

all: ${NAME}

${NAME}: ${C_FILES}
	${C_TYPE} ${CFLAGS} ${C_FILES} -o ${NAME}

clean:
	rm -f ${NAME}

fclean:	clean

re: fclean all

.PHONY: all clean fclean re%