/*
** main.c for main in /home/marcha_j//test/c/irc/proj/Serveur
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Mon Apr 16 15:26:22 2012 hugo marchadier
** Last update Fri Apr 20 16:58:55 2012 hugo marchadier
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<string.h>

#include	<signal.h>

#include	"defines.h"
#include	"serveur.h"
#include	"parser.h"

t_env		g_env;

void    hand(int sig)
{
  int	i;

  i = 0;
  if (sig != SIGPIPE)
    while (i != MAX_FD)
      {
	if (g_env.fd_type[i] == FD_CLIENT)
	  write(i, SERVER_EXIT, strlen(SERVER_EXIT));
	i = i + 1;
      }
  close_serveur();
  exit(EXIT_FAILURE);
}

int		main(int argc, char **argv)
{
  t_msg		**msg;

  msg = NULL;
  memset(g_env.fd_type, FD_FREE, MAX_FD);
  memset(g_env.name, 0, MAX_FD - 1);
  if (argc < 2)
    g_env.port = atoi(DEFAULT_PORT);
  else
    g_env.port = atoi(argv[1]);
  msg = init_serveur(msg);
  signal(SIGINT, hand);
  signal(SIGPIPE, hand);
  parser(msg);
  close_serveur();
  return (1);
}
