# Program name
NAME     = libft.a

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

ifeq ($(MAKECMDGOALS), debug)
	CFLAGS += $(DEBUG_FLAGS)
endif

# Includes
INCLUDES = -I includes/

LIBFT_CHAR_DIR	= srcs/char/
LIBFT_CHAR		= ft_isalpha.c \
					ft_isdigit.c \
					ft_isalnum.c \
					ft_isascii.c \
					ft_isprint.c \
					ft_toupper.c \
					ft_tolower.c

LIBFT_MATHS_DIR	= srcs/maths/
LIBFT_MATHS		= ft_abs.c \
					ft_max.c \
					ft_floor_double.c \
					ft_fmod_double.c \
					ft_get_int_len.c \
					ft_pow_double.c \
					ft_signbit.c

LIBFT_MEMORY_DIR	= srcs/memory/
LIBFT_MEMORY		= ft_calloc.c \
					ft_bzero.c \
					ft_memset.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_memchr.c \
					ft_memcmp.c


LIBFT_STR_DIR	= srcs/str/
LIBFT_STR		= ft_strlen.c \
					ft_strchr.c \
					ft_strrchr.c \
					ft_strcmp.c \
					ft_strncmp.c \
					ft_strnstr.c \
					ft_strlcat.c \
					ft_strlcpy.c \
					ft_strdup.c \
					ft_substr.c \
					ft_strjoin.c \
					ft_strtrim.c \
					ft_split.c \
					ft_atoi.c \
					ft_itoa.c \
					ft_strmapi.c \
					ft_striteri.c \
					ft_valid_number.c \
					ft_putdouble.c

LIBFT_FD_DIR	= srcs/fd/
LIBFT_FD		= ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \

LIBFT_LISTS_DIR	= srcs/lists/
LIBFT_LISTS		= ft_lstnew_bonus.c \
					ft_lstadd_front_bonus.c \
					ft_lstsize_bonus.c \
					ft_lstlast_bonus.c \
					ft_lstadd_back_bonus.c \
					ft_lstdelone_bonus.c \
					ft_lstclear_bonus.c \
					ft_lstiter_bonus.c \
					ft_lstmap_bonus.c \

LIBFT_GNL_DIR	= srcs/get_next_line/
LIBFT_GNL		= get_next_line.c \
					get_next_line_utils.c \

LIBFT_PRINTF_DIR	= srcs/printf/
LIBFT_PRINTF		= ft_printf.c \
						srcs/ft_alignment.c \
						srcs/ft_utils.c \
						srcs/ft_utils_fd.c \
						srcs/ft_atol.c \
						srcs/ft_swrite.c \
						srcs/ft_format_arg.c \
						srcs/ft_putnbr_base.c \
						srcs/ft_putnbr.c \
						srcs/ft_type_c.c \
						srcs/ft_type_s.c \
						srcs/ft_type_p.c \
						srcs/ft_type_i.c \
						srcs/ft_type_u.c \
						srcs/ft_type_x.c \
						srcs/ft_type_xx.c \
						srcs/ft_type_f.c \
						srcs/ft_type_mod.c

# Build full paths for all sources
LIBFT_FILE	= $(addprefix $(LIBFT_CHAR_DIR), $(LIBFT_CHAR)) \
					$(addprefix $(LIBFT_MATHS_DIR), $(LIBFT_MATHS)) \
					$(addprefix $(LIBFT_MEMORY_DIR), $(LIBFT_MEMORY)) \
					$(addprefix $(LIBFT_STR_DIR), $(LIBFT_STR)) \
					$(addprefix $(LIBFT_FD_DIR), $(LIBFT_FD)) \
					$(addprefix $(LIBFT_LISTS_DIR), $(LIBFT_LISTS)) \
					$(addprefix $(LIBFT_GNL_DIR), $(LIBFT_GNL)) \
					$(addprefix $(LIBFT_PRINTF_DIR), $(LIBFT_PRINTF))

M_FILE  = $(LIBFT_FILE)


# Object files directory
OBJ_DIR   = .obj/
OBJ       = $(M_FILE:%.c=$(OBJ_DIR)%.o)

DEPS      = $(M_FILE:%.c=$(OBJ_DIR)%.d)

# NORMINETTE (use same paths as norm target)
# NORM_RET = $(RED)[ERROR]$(BOLD) Norminette Disable$(NC)
NORM   = $(shell norminette src/ includes/ | grep -c 'Error!')
ifeq ($(NORM), 0)
  NORM_RET = $(GREEN)[DONE] $(BOLD)$(CYAN)Norminette.$(NC)
else
  NORM_RET = $(RED)[ERROR] $(BOLD)$(CYAN)Norminette.$(NC)
endif

COMPILED_FILES := 0

# Pattern rule for object files
$(OBJ_DIR)%.o : %.c
	@if [ $(COMPILED_FILES) -eq 0 ]; then \
		echo "\n$(CYAN)╔══════════════════════════════════════════════╗$(NC)";                          \
		echo "$(CYAN)║        Starting $(YELLOW)$(NAME)$(CYAN) compilation...       ║$(NC)";           \
		echo "$(CYAN)╚══════════════════════════════════════════════╝$(NC)";                        \
	fi
	@$(eval COMPILED_FILES := 1)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)
	@printf "\n$(GREEN)[Compiling] $(NC)$(shell echo $< | sed 's|^src/||')";

all : $(NAME) nothing_to_be_done

nothing_to_be_done:
	@if [ $(COMPILED_FILES) -eq 0 ]; then \
		echo "\n$(CYAN)╔══════════════════════════════════════════════╗$(NC)";                          \
		echo "$(CYAN)║        Nothing to be done for $(YELLOW)$(NAME)$(CYAN).       ║$(NC)";           \
		echo "$(CYAN)╚══════════════════════════════════════════════╝$(NC)\n";                          \
	fi

$(NAME) : $(OBJ)
	@if [ $(COMPILED_FILES) -eq 0 ]; then \
		echo "\n$(CYAN)╔══════════════════════════════════════════════╗$(NC)";                          \
		echo "$(CYAN)║        Starting $(YELLOW)$(NAME)$(CYAN) compilation...       ║$(NC)";           \
		echo "$(CYAN)╚══════════════════════════════════════════════╝$(NC)";                        \
	fi
	@$(eval COMPILED_FILES := 1)
	@echo "\n\n$(GREEN)[Compiling program] $(NC)$(NAME)"
	@ar rcs $(NAME) $(OBJ)
# 	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
# 	@make --no-print-directory end_message

clean :
	@echo "$(RED)[Removing] $(NC)object files"
	@rm -rf $(OBJ_DIR)

fclean : clean
	@if [ -f $(NAME) ]; then \
		echo "$(RED)[Removing] $(NC)program $(NAME)"; \
		rm -f $(NAME); \
	fi

re : fclean
	@make --no-print-directory all

debug: all 

norm:
	@norminette src/ includes/

bonus:

.PHONY: all clean fclean re nothing_to_be_done norminette debug

-include $(DEPS)