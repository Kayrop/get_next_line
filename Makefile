NAME = get_next_line.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCES = get_next_line_bonus.c get_next_line_utils_bonus.c get_next_line.c get_next_line_utils.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)
	@echo "\n   __                                                              __                              "
	@echo " /         /                        /         / /                /                   / /         |"
	@echo "( __  ___ (___       ___  ___      (___      (    ___  ___      (     ___  _ _  ___   (  ___  ___|"
	@echo "|   )|___)|         |   )|___)(_/_ |         | | |   )|___)     |   )|   )| | )|   )| | |___)|   )"
	@echo "|__/ |__  |__       |  / |__   / / |__       | | |  / |__       |__/ |__/ |  / |__/ | | |__  |__/ "
	@echo "                                                                               |\n\n"
	@echo "\033[93m☆\033[00m ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ \033[93m☆\n\n"

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: all
