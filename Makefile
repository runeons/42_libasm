NAME = libasm.a

ASM = nasm
AFLAGS = -felf64
SRC = ft_read.s \
	ft_strcmp.s \
	ft_strcpy.s \
	ft_strdup.s \
	ft_strlen.s \
	ft_write.s \

OBJ = $(SRC:.s=.o)

%.o: %.s
	$(ASM) $(AFLAGS) $< -o $@

OPTION = -I .

all: $(NAME)

$(NAME): $(SRC) $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
