CC = cc
 CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

RM = rm -rf  
HEADERS = ./mandatory/fdf.h 
SRCS = mandatory/main.c  mandatory/ft_map_points.c   mandatory/transfomation_matrix.c mandatory/ft_draw_map.c mandatory/ft_scale_factor.c mandatory/ft_iso_calcul.c

INCLUDES = MLX42/build/libmlx42.a MLX42/build/libglfw3.a -Iinclude -lm -framework Cocoa -framework OpenGL -framework IOKit

NAME = fdf
OBJS = $(SRCS:.c=.o)
LIBFT=libftt/libft.a


all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(LIBFT) $(INCLUDES) $(OBJS) -o $(NAME)

$(LIBFT):
	make -C libftt/

clean:
	@$(RM) $(OBJS) 
	@make clean -C libftt

%.o : %.c $(HEADERS) 
	$(CC) $(CFLAGS) -c $< -o $@ 

fclean : clean 
		@$(RM) $(NAME) 
		@make fclean -C libftt

re : fclean all 

.PHONY: all clean fclean re 