NAME = minishell
LIB = minishell.a
CFLAGS = 

SRC = 	ft_cd.c \
		ft_dollar.c\
		ft_echo.c \
		ft_export.c \
		ft_get_args.c \
		ft_get_path.c \
		ft_init.c \
		ft_multi_command.c \
		ft_pipe.c \
		ft_pwd.c \
		ft_redirection.c \
		ft_split.c \
		ft_unset.c \
		get_next_line.c \
		get_next_line_utils.c \
		main.c \
		minishell_utils.c \
		ft_command_run.c \
		ft_dup2.c \
		ft_env.c \
		ft_signal.c \
		ft_start.c \
		ft_split_1.c \
		ft_free_all.c \
		syn_error.c \
		ft_split_2.c \
		ft_pipe_2.c \
		minishell_utils_2.c 

		

OBJ= $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(LIB) $(OBJ)
	@gcc $(CFLAGS) $(LIB) -o $(NAME)
	@echo "\033[1;33mMake \033[1;32m\t    [OK]"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~"
	@echo "\033[1;32m| \033[1;33m" $(NAME) : Created ! "\033[1;32m|"
	@echo "\033[1;32m~~~~~~~~~~~~~~~~~~~~~~~~~~"
%.o: %.c
	@gcc -o $@ -c $<

test: re
	@make clean
	@./minishell
clean:
	@rm -f $(OBJ)
	@echo "\033[1;33mMake clean \033[1;32m [OK]"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIB)
	@echo "\033[1;33mMake fclean \033[1;32m[OK]"

re:
	@make fclean --no-print-directory
	@make all --no-print-directory
