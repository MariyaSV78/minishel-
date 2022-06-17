
NAME = minishell

# --   Directory   -- #
# CHECK_DIR = checker_dir
OBJ_DIR = objs

INC = -Iinclude -Ilibft

# --  Search All files in SRCS  -- #
SRC_DIR = $(shell find srcs -type d)
vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)
SRCS = $(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.c), $(notdir $(file))))

# --  Redirection in OBJS  -- #
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

# --   Compilation flags  -- #
FLAGS = -g -Wall -Wextra -Werror

CC 	  =	gcc

LIBFT = libft/libft.a


all:	
	mkdir -p $(OBJ_DIR)
	make $(NAME)

$(NAME): $(LIBFT) $(OBJS) 
	echo "$(OBJS)"
	@echo "\033[93m>> minishell compilation\033[0m"
	$(CC) $(FLAGS) $(INC) -o $(NAME) $(OBJS) $(LIBFT) -lreadline

$(LIBFT):
	@echo "\033[93m>> Libft compilation\033[0m"
	make -C libft
	
$(OBJ_DIR)/%.o: %.c
	@echo "\033[93m>> minishell obj $@\033[0m"
	$(CC) $(FLAGS) $(INC) -o $@ -c $<


clean:
	@echo "\033[93m>> Cleaning objects \033[0m"
	make $@ -C libft
	rm -rf $(OBJ_DIR)

fclean: clean
	make $@ -C libft
	rm -f $(NAME)

re:
	make fclean
	make all

bonus: $(NAME)

.PHONY: all, clean, fclean, re, bonus

