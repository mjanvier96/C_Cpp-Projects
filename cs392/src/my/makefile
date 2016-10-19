FILES = my_alpha.c my_atoi.c my_char.c my_digits.c my_int.c my_num_base.c my_revstr.c my_str.c my_strcat.c my_strcmp.c my_strconcat.c my_strcpy.c my_strdup.c my_strfind.c my_strindex.c my_strlen.c my_strncmp.c my_strnconcat.c my_strncpy.c my_strrfind.c my_strrindex.c

OBJ = $(FILES:.c=.o)

LIBRARY = libmy.a

CFLAGS = -I../../include -Wall -Werror --pedantic

all: $(OBJ)
	gcc -c $(FILES) $(CFLAGS)
	ar -rc $(LIBRARY) $(OBJ)
	ranlib $(LIBRARY)
	mv $(LIBRARY) ../../lib

clean:
	rm -f $(OBJ)

fclean:
	rm $(OBJ)
	rm -f ../../lib/$(LIBRARY)

re: fclean all
