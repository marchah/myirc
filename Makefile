##
## Makefile for lemipc in /home/marcha_j//test/c/lemipc/proj
## 
## Made by hugo marchadier
## Login   <marcha_j@epitech.net>
## 
## Started on  Mon Mar 19 17:15:46 2012 hugo marchadier
## Last update Wed Apr  6 21:58:07 2005 hugo marchadier
##

NAME_SERVER=	serveur

SRC_SERVER=	Serveur/main.c \
		Serveur/serveur.c \
		Serveur/parser.c \
		Ressources/xfct.c \
		Ressources/fct_msg.c \
		Serveur/xfct_serveur.c \
		Serveur/fct_annexe.c \
		Serveur/fct_msg_serveur.c \
		Serveur/channel.c \
		Serveur/channel2.c \
		Serveur/channel_bonus.c \
		Serveur/channel_utils.c \
		Serveur/fct_send_msg.c \
		Serveur/str_to_tab.c \
		Serveur/check_command.c \

NAME_CLIENT=	client

SRC_CLIENT=	Client/main.c \
		Client/client.c \
		Client/xfct_client.c \
		Client/parser.c \
		Client/fct_msg_client.c \
		Client/fct_annexe.c \
		Client/getln.c \
		Client/exec_command.c \
		Client/cmd_client1.c \
		Client/cmd_client2.c \
		Client/cmd_client_bonus.c \
		Client/str_to_tab.c \
		Client/get_connect.c \
		Ressources/xfct.c \
		Ressources/fct_msg.c \
		Client/graphics.c


CC=		gcc

CFLAGS= -W -Wall -Wextra -Werror -ansi -pedantic -I./Ressources -D_XOPEN_SOURCE=700

OBJ_SERVER=	$(SRC_SERVER:.c=.o)

OBJ_CLIENT=	$(SRC_CLIENT:.c=.o)

all:	$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):	$(OBJ_SERVER)
	$(CC) -o $(NAME_SERVER) $(OBJ_SERVER) $(CFLAGS)

$(NAME_CLIENT):	$(OBJ_CLIENT)
	$(CC) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(CFLAGS) -lncurses

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re:     fclean all

.PHONY: all clean fclean re