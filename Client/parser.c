/*
** parser.c for parser in /home/marcha_j//test/c/irc/proj
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Sat Apr  2 22:40:32 2005 hugo marchadier
** Last update Wed Apr  6 21:28:51 2005 hugo marchadier
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>

#include	<sys/select.h>

#include	"defines.h"
#include	"client.h"
#include	"fct_msg.h"
#include	"fct_msg_client.h"
#include	"xfct.h"
#include	"getln.h"
#include	"str_to_tab.h"
#include	"cmd_client.h"
#include	"exec_command.h"
#include	"graphics.h"

static void	init_fd_listen(fd_set *fds)
{
  FD_ZERO(fds);
  FD_SET(0, fds);
  FD_SET(g_client, fds);
}

static void	find_fd_read(fd_set *readfds, t_msg **msg, void *win_msg)
{
  char		*buffer;

  if (FD_ISSET(0, readfds))
    {
      buffer = getln(win_msg);
      msg = exec_command(buffer, msg, win_msg);
      free(buffer);
    }
  if (FD_ISSET(g_client, readfds))
    {
      client_read(g_client, 0, &msg);
    }
}

static void	check_client_exit(t_msg ***msg, int pos, void *win_msg)
{
  if (strncmp((*msg)[pos]->buffer, "/quit", 5) == 0)
    {
      client_write(g_client, msg, win_msg);
      print_msg(win_msg, "You quit irc\n");
      delete_msg(*msg);
      end_ncurses(win_msg);
      close_client();
      exit(EXIT_SUCCESS);
    }
}

static void	find_fd_write(fd_set *writefds, t_msg ***msg, void *win_msg)
{
  int		pos;

  if (FD_ISSET(0, writefds))
    {
      if ((pos = find_id_msg(0, *msg)) != -1 && (*msg)[pos]->buffer != NULL)
	{
	  print_msg(win_msg, (*msg)[0]->buffer);
	  (*msg)[pos]->len = 0;
	  free((*msg)[pos]->buffer);
	  (*msg)[pos]->buffer = NULL;
	}
    }
  if (FD_ISSET(g_client, writefds))
    {
      if ((pos = find_id_msg(g_client, *msg)) != -1
	  && (*msg)[pos]->buffer != NULL)
	{
	  check_client_exit(msg, pos, win_msg);
	  client_write(g_client, msg, win_msg);
	}
    }
}

void		parser(void *win_msg)
{
  int		error;
  fd_set	readfds;
  fd_set	writefds;
  t_msg		**msg;

  error = 0;
  msg = NULL;
  msg = add_msg_client(msg, 0);
  msg = add_msg_client(msg, g_client);
  while (error != -1)
    {
      init_fd_listen(&readfds);
      init_fd_listen(&writefds);
      if ((error = xselect(g_client + 1, &readfds, &writefds)) != -1)
	{
	  find_fd_read(&readfds, msg, win_msg);
	  find_fd_write(&writefds, &msg, win_msg);
	}
    }
  delete_msg(msg);
}
