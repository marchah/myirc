/*
** Defines.h for Defines in /home/marcha_j//test/c/irc/proj/Serveur
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Mon Apr 16 15:45:50 2012 hugo marchadier
** Last update Fri Apr 20 18:11:24 2012 hugo marchadier
*/

#ifndef	DEFINES_H_
# define DEFINES_H_

# define FD_STDIN	-1
# define FD_FREE	0
# define FD_CLIENT	1
# define FD_SERVER	2

# define MAX_FD		64

# define SIZE_LISTEN	10

# define READ		0
# define WRITE		1

# define SIZE_BUFFER	50
# define MAX_NAME	50

# define DEFAULT_PORT	"4544"

# define SERVEUR_FLAG	"1"
# define CHANNEL_FLAG	"2"
# define NICK_FLAG	"3"

# define SERVEUR	"1[SERVEUR]:"

# define SERVER_EXIT	"SERVER EXIT\n"

# define BUF_SIZE	1024

typedef enum	e_eBool
  {
    E_FALSE = 0,
    E_TRUE
  }		eBool;

typedef	struct	s_msg
{
  char		*buffer;
  int		len;
  int		fd;
  char		channel[MAX_NAME];

}		t_msg;

#include	"../Serveur/channel.h"

typedef	void	(*fct)(int, t_msg ***, t_channel ***);

typedef	struct	s_env
{
  char	name[MAX_FD][MAX_NAME];
  char	fd_type[MAX_FD];
  fct	fct_read[MAX_FD];
  fct	fct_write[MAX_FD];
  int	port;
}		t_env;

extern t_env	g_env;

# endif /* DEFINE_H_*/
