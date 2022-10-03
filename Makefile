UTILS_PATH = ./utils/
UTILS =	check_valid_map.c \
	ft_split.c \
	ft_init.c \
	read_map.c \
	count_characters.c \
	start_game.c \
	end_prog.c \
	move.c \
	ft_putnbr.c \

UTILS_BONUS_PATH = ./utils_bonus/
UTILS_B = check_valid_map_bonus.c \
	ft_split_bonus.c \
	ft_init_bonus.c \
	read_map_bonus.c \
	count_characters_bonus.c \
	start_game_bonus.c \
	end_prog_bonus.c \
	move_bonus.c \
	ft_itoa.c \
	animation.c \
	animation1.c \

GNL_PATH = ./get_next_line/
GNL =	get_next_line.c \
	get_next_line_utils.c

SRCS = ./so_long.c $(addprefix $(UTILS_PATH), $(UTILS)) $(addprefix $(GNL_PATH), $(GNL))
SRCS_B = ./so_long_bonus.c $(addprefix $(UTILS_BONUS_PATH), $(UTILS_B)) $(addprefix $(GNL_PATH), $(GNL))

OBJS = 	$(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

NAME = 	so_long
NAME_B = so_long_bonus

HDRS =	so_long.h
HDRS_B = so_long_bonus.h	

CC = 	cc
CFLAGS = -Wall -Wextra -Werror
RM = 	rm -f

all: $(NAME)

%.o: %.c 
	$(CC) -c $(CFLAGS) -o2 -Imlx -c $< -o $@ 

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(NAME_B)

$(NAME_B): $(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS_B) -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_B)

re: fclean all

norm:
	norminette -R $(SRCS) $(SRCS_B)
	norminette -R CheckDefine $(HDRS) $(HDRS_B)

.PHONY: all clean fclean re bonus norm