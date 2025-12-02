CC := cc
NAME := push_swap
BUILD_DIR := .build
LIBFT = libft/libft.a
INCLUDES = -Ilibft/includes -Iincludes
CFLAGS = -Werror -Wextra -Wall -MD $(INCLUDES)
MODE ?= release

VPATH = srcs
SRCS = main.c\
	   stack_operations.c\
	   stack_operations_utils.c\
	   sort_utils.c\
	   sort.c\
	   sort_utils_reverse.c\
	   stack_utils.c\
	   stack_complex_operations.c\
	   check_sort.c\
	   comp.c\
	   best_utils.c

OBJS = $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

ifeq ($(MODE), debug)
	CFLAGS += -g3
endif

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
