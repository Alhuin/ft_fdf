# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/14 19:15:23 by jmonneri     #+#   ##    ##    #+#        #
#    Updated: 2018/03/28 19:31:31 by jjanin-r    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fdf
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
PATH_OBJ = ./objs/
PATH_SRC = ./srcs/
PATH_INC = ./incs/
INC = $(addprefix $(PATH_INC), fdf.h )

#******************************************************************************#
#                                    MLX                                       #
#******************************************************************************#

NAME_MLX = mlx
PATH_MLX = ./minilibx/
PATH_INC_MLX = ./minilibx/
FRAMEWORKS = -framework OpenGL -framework AppKit
MINILIBX = $(PATH_MLX)lib$(NAME_MLX).a

#******************************************************************************#
#                                    FDF                                       #
#******************************************************************************#

PATH_SRC_FDF = $(PATH_SRC)Fdf/
PATH_OBJ_FDF = $(PATH_OBJ)Fdf/
FILES_FDF = ft_bresenham ft_fdf_draw ft_fdf_engine ft_fdf_parse\
			ft_fdf_put_in_tab perspective main ft_fdf_test_file keys
OBJ_FDF = $(addprefix $(PATH_OBJ_FDF), $(addsuffix .o, $(FILES_FDF)))
SRC_FDF = $(addprefix $(PATH_SRC_FDF), $(addsuffix .c, $(FILES_FDF)))

#******************************************************************************#
#                                     ALL                                      #
#******************************************************************************#

PATHS_OBJ = $(PATH_OBJ) $(PATH_OBJ_FDF)
OBJ = $(OBJ_FDF)
SRC = $(SRC_FDF)
FILES = $(FILES_FDF)

#******************************************************************************#
#                                    RULES                                     #
#******************************************************************************#

all: $(NAME)

clean:
	@printf "\n\033[1m🦄 🦄 🦄 🦄 SUPPRESSION DES OBJETS🦄 🦄 🦄 🦄\033[0m\n"
	@make clean -C ./libft/
	@rm -rf $(PATH_OBJ)

test: all
	@./$(NAME) tests/42.fdf

fclean: clean
	@printf "\n\033[1m🦄 🦄 🦄 🦄 SUPPRESSION DE $(NAME)🦄 🦄 🦄 🦄\033[0m\n"
	@rm -rf $(NAME)
	@rm -rf ./libft/libft.a

re: fclean all

#******************************************************************************#
#                                  Comp FDF                                    #
#******************************************************************************#


$(NAME): $(MINILIBX) $(PATHS_OBJ) $(OBJ)
	@printf "\n\033[1m🦄 🦄 🦄 🦄 CREATION DE FDF🦄 🦄 🦄 🦄\033[0m\n"
	@make -C ./libft/
	@$(CC) $(CC_FLAGS) $(OBJ) -I $(PATH_INC) -I $(PATH_INC_MLX) -L $(PATH_MLX)\
		-l$(NAME_MLX) $(FRAMEWORKS) -L ./libft/ -lft -o $(NAME)
	@printf "  👍  👍  👍 \033[1mEXECUTABLE CREE\033[0m👍  👍  👍\n\n"

$(MINILIBX):
	@printf "Creating libmlx.a..."
	@make -C $(PATH_MLX)
	@printf "   \033[0;32m[OK]\033[0m\n"

$(PATH_OBJ)%.o: $(PATH_SRC)%.c $(INC)
	@printf "0️⃣  Compilation de \033[1m$<\033[0m en \033[1m$@\033[0m"
	@$(CC) $(CC_FLAGS) -o $@ -c $< -I $(PATH_INC)
	@printf "   \033[0;32m[OK]\033[0m\n"

$(PATHS_OBJ):
	@mkdir $@
