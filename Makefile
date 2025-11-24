CC := cc
NAME := push_swap
BUILD_DIR := .build
LIBFT = libft/libft.a
INCLUDES = -Ilibft/includes -Iincludes
CFLAGS = -Werror -Wextra -Wall -MD $(INCLUDES)

VPATH = srcs
SRCS = main.c

OBJS = $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

all: libft $(NAME)
	@echo $(SRCS)

$(NAME): $(BUILD_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

libft:
	$(MAKE) -C libft

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C libft clean
	rm -rf $(BUILD_DIR)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft

-include $(DEPS)
