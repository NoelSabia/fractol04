NAME = ft_printf.a

SOURCES = ft_printf.c\
ft_words.c\
ft_unsigned_int_nums.c\
ft_decimal_or_int_nums.c\
ft_hex_nums.c\
ft_pointer_hex.c

OBJ = ${SOURCES:.c=.o}

INCLUDES = ft_printf.h

CFLAGS = -Wall -Wextra -Werror -I ./

.c.o:
	cc ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCLUDES}

${NAME}: ${OBJ}
	ar rc ${NAME} ${OBJ}
	ranlib ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all