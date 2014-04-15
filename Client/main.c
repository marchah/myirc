/*
** client.c for client in /home/marcha_j//test/c/ftp/tp
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Mon Apr  2 14:54:37 2012 hugo marchadier
** Last update Fri Apr 20 18:54:07 2012 hugo marchadier
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<string.h>

#include	<signal.h>

#include	"defines.h"
#include	"client.h"
#include	"parser.h"
#include	"get_connect.h"
#include	"graphics.h"

int		g_client;

void		hand(int sig)
{
  if (sig != SIGPIPE)
    write(g_client, "/quit\n", strlen("/quit\n"));
  close_client();
  end_ncurses(NULL);
  exit(EXIT_FAILURE);
}

int		main(void)
{
  char		*port;
  char		*machine;
  void		*win_msg;

  if ((win_msg = init_ncurses()) == NULL)
    {
      fprintf(stderr, "Creation Ncurses failed.\n");
      return (-1);
    }
  port = NULL;
  machine = NULL;
  if (get_connect(&port, &machine, win_msg) == E_FALSE)
    return (0);
  init_client(atoi(port), machine);
  free(port);
  free(machine);
  signal(SIGINT, hand);
  signal(SIGPIPE, hand);
  parser(win_msg);
  close_client();
  end_ncurses(win_msg);
  return (0);
}
