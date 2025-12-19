# Program name
NAME     = push_swap

# Style
GREY     = \033[0;30m
RED      = \033[0;31m
GREEN    = \033[0;32m
YELLOW   = \033[0;33m
BLUE     = \033[0;34m
PURPLE   = \033[0;35m
CYAN     = \033[0;36m
WHITE    = \033[0;37m

BOLD     = \033[1m
UNDER    = \033[4m
REV      = \033[7m
BLINK    = \033[5m

NC       = \033[0;0m
ERASE    = \033[2K\r
ERASE2   = $(ERASE)\033[F$(ERASE)

# Compiler and flags
CC       = cc

DEPFLAGS = -MMD -MP
CFLAGS   = $(DEPFLAGS) -Wall -Wextra -Werror
DEBUG_FLAGS = -g3

BONUS_CFLAGS := $(CFLAGS) -DPRINT_OPERATION=0

ifeq ($(MAKECMDGOALS), debug)
	CFLAGS += $(DEBUG_FLAGS)
endif

# libs
LIBFTDIR = libft/
LIBFT    = $(LIBFTDIR)libft.a

# Includes
INCLUDES = -I includes/ -I $(LIBFTDIR)includes/

# Source files (grouped with correct directories)
PUSH_SWAP_DIR             = src/

# Mandatory sources (in src/)
PUSH_SWAP_MANDATORY			= push_swap.c \
							ft_debug.c \
							ft_format_input.c \
							ft_free_push_swap.c \
							ft_disorder.c \
							ft_bench.c \
							ft_error.c

PUSH_SWAP_CHECKER			= ft_checker.c \
							ft_format_input.c \
							ft_free_push_swap.c \
							ft_disorder.c \
							ft_bench.c \
							ft_error.c

# Utils sources (in src/utils/)
PUSH_SWAP_UTILS_DIR			= src/utils/
PUSH_SWAP_UTILS				= ft_stack_len.c \
								ft_maths.c \
								ft_free_split.c \
								ft_is_in_stack.c \
								ft_sort.c

# Operations sources (in src/operations/)
PUSH_SWAP_OPERATIONS_DIR	= src/operations/
PUSH_SWAP_OPERATIONS      	= operation_p.c \
							operation_s.c \
							operation_r.c \
							operation_rr.c

# Operations sources (in src/operations/)
PUSH_SWAP_STRATEGIES_DIR	= src/strategies/
PUSH_SWAP_STRATEGIES      	= ft_strategy_selector.c \
								simple/ft_strategy_simple.c \
								medium/ft_strategy_medium.c \
								complex/ft_strategy_complex.c

# Build full paths for all sources
PUSH_SWAP_FILE	= $(addprefix $(PUSH_SWAP_DIR), $(PUSH_SWAP_MANDATORY)) \
					$(addprefix $(PUSH_SWAP_UTILS_DIR), $(PUSH_SWAP_UTILS)) \
					$(addprefix $(PUSH_SWAP_OPERATIONS_DIR), $(PUSH_SWAP_OPERATIONS)) \
					$(addprefix $(PUSH_SWAP_STRATEGIES_DIR), $(PUSH_SWAP_STRATEGIES))

PUSH_SWAP_CHECKER_FILE	= $(addprefix $(PUSH_SWAP_DIR), $(PUSH_SWAP_CHECKER)) \
					$(addprefix $(PUSH_SWAP_UTILS_DIR), $(PUSH_SWAP_UTILS)) \
					$(addprefix $(PUSH_SWAP_OPERATIONS_DIR), $(PUSH_SWAP_OPERATIONS))\
					$(addprefix $(PUSH_SWAP_STRATEGIES_DIR), $(PUSH_SWAP_STRATEGIES))


M_FILE  = $(PUSH_SWAP_FILE)

# Add checker sources list and derived object/deps
CHECKER_M_FILE = $(PUSH_SWAP_CHECKER_FILE)

# Object files directory
OBJ_BONUS_DIR := .obj_bonus/
OBJ_DIR   = .obj/
OBJ       = $(M_FILE:%.c=$(OBJ_DIR)%.o)
CHECKER_OBJ = $(CHECKER_M_FILE:%.c=$(OBJ_BONUS_DIR)%.o)

DEPS      = $(M_FILE:%.c=$(OBJ_DIR)%.d)
CHECKER_DEPS = $(CHECKER_M_FILE:%.c=$(OBJ_BONUS_DIR)%.d)

# NORMINETTE (use same paths as norm target)
# NORM_RET = $(RED)[ERROR]$(BOLD) Norminette Disable$(NC)
NORM   = $(shell norminette src/ libft/ includes/ | grep -c 'Error!')
ifeq ($(NORM), 0)
  NORM_RET = $(GREEN)[DONE] $(BOLD)$(YELLOW)Norminette.$(NC)
else
  NORM_RET = $(RED)[ERROR] $(BOLD)$(YELLOW)Norminette.$(NC)
endif

COMPILED_FILES := 0

# Pattern rule for object files
$(OBJ_DIR)%.o : %.c
	@if [ $(COMPILED_FILES) -eq 0 ]; then \
		echo "\n$(YELLOW)╔══════════════════════════════════════════════╗$(NC)";                          \
		echo "$(YELLOW)║      Starting $(YELLOW2)$(NAME)$(YELLOW) compilation...       ║$(NC)";           \
		echo "$(YELLOW)╚══════════════════════════════════════════════╝$(NC)";                        \
	fi
	@$(eval COMPILED_FILES := 1)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)
	@printf "\n$(GREEN)[Compiling] $(NC)$(shell echo $< | sed 's|^src/||')";

# New pattern rule for bonus object files (compile checker sources with BONUS_CFLAGS)
$(OBJ_BONUS_DIR)%.o : %.c
	@if [ $(COMPILED_FILES) -eq 0 ]; then \
		echo "\n$(YELLOW)╔══════════════════════════════════════════════╗$(NC)";                          \
		echo "$(YELLOW)║      Starting $(YELLOW2)checker$(YELLOW) compilation...       ║$(NC)";       \
		echo "$(YELLOW)╚══════════════════════════════════════════════╝$(NC)";                        \
	fi
	@$(eval COMPILED_FILES := 1)
	@mkdir -p $(dir $@)
	@$(CC) $(BONUS_CFLAGS) -o $@ -c $< $(INCLUDES)
	@printf "\n$(GREEN)[Compiling] $(NC)$(shell echo $< | sed 's|^src/||')";

all : make_libft $(NAME) nothing_to_be_done

nothing_to_be_done:
	@if [ $(COMPILED_FILES) -eq 0 ]; then \
		echo "\n$(YELLOW)╔══════════════════════════════════════════════╗$(NC)";                          \
		echo "$(YELLOW)║      Nothing to be done for $(YELLOW2)$(NAME)$(YELLOW).       ║$(NC)";           \
		echo "$(YELLOW)╚══════════════════════════════════════════════╝$(NC)\n";                          \
	fi

$(NAME) : $(LIBFT) $(OBJ)
	@if [ $(COMPILED_FILES) -eq 0 ]; then \
		echo "\n$(YELLOW)╔══════════════════════════════════════════════╗$(NC)";                          \
		echo "$(YELLOW)║      Starting $(YELLOW2)$(NAME)$(YELLOW) compilation...       ║$(NC)";           \
		echo "$(YELLOW)╚══════════════════════════════════════════════╝$(NC)";                        \
	fi
	@$(eval COMPILED_FILES := 1)
	@echo "\n\n$(GREEN)[Compiling program] $(NC)$(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
# 	@make --no-print-directory end_message

# New rule to build checker executable
checker: $(LIBFT) $(CHECKER_OBJ)
	@if [ $(COMPILED_FILES) -eq 0 ]; then \
		echo "\n$(YELLOW)╔══════════════════════════════════════════════╗$(NC)";                          \
		echo "$(YELLOW)║      Starting $(YELLOW2)checker$(YELLOW) compilation...       ║$(NC)";       \
		echo "$(YELLOW)╚══════════════════════════════════════════════╝$(NC)";                        \
	fi
	@$(eval COMPILED_FILES := 1)
	@echo "\n\n$(GREEN)[Compiling program] $(NC)checker"
	@$(CC) $(BONUS_CFLAGS) -o checker $(CHECKER_OBJ) $(LIBFT)

# bonus target builds the checker
bonus: checker

make_libft:
	@make --no-print-directory -C $(LIBFTDIR) all

$(LIBFT): make_libft

clean :
	@echo "$(RED)[Removing] $(NC)libft object files"
	@make --no-print-directory -C $(LIBFTDIR) clean
	@echo "$(RED)[Removing] $(NC)object files"
	@rm -rf $(OBJ_DIR)

fclean : clean
	@make --no-print-directory -C $(LIBFTDIR) fclean
	@if [ -f $(NAME) ]; then \
		echo "$(RED)[Removing] $(NC)program $(NAME)"; \
		rm -f $(NAME); \
	fi
	@if [ -f checker ]; then \
		echo "$(RED)[Removing] $(NC)program checker"; \
		rm -f checker; \
	fi
	@if [ -f checker ]; then \
		echo "$(RED)[Removing] $(NC)program checker"; \
		rm -f checker; \
	fi

fcleanp :
	@echo "$(RED)[Removing] $(NC)object files"
	@rm -rf $(OBJ_DIR)
	@if [ -f $(NAME) ]; then \
		echo "$(RED)[Removing] $(NC)program $(NAME)"; \
		rm -f $(NAME); \
	fi

re : fclean
	@make --no-print-directory all

debug: all 

norm:
	@norminette src/ libft/ includes/

bonus:

.PHONY: all clean fclean re make_libft nothing_to_be_done norminette debug bonus checker

-include $(DEPS) $(CHECKER_DEPS)