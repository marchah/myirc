/*
** parser.c for parser in /home/marcha_j//test/c/irc/proj
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Mon Apr 16 16:30:04 2012 hugo marchadier
** Last update Wed Apr  6 11:03:33 2005 hugo marchadier
*/

#include	<stdlib.h>
#include	<sys/select.h>

#include	"defines.h"
#include	"xfct.h"
#include	"fct_msg.h"
#include	"channel.h"

static int	find_max_fd(void)
{
  int		i;
  int		save;

  i = 0;
  save = 0;
  while (i != MAX_FD)
    {
      if (g_env.fd_type[i] != FD_FREE)
	save = i;
      i = i + 1;
    }
  return (save + 1);
}

static void	init_fd_listen(fd_set *fds, int flag)
{
  int		i;

  i = 0;
  FD_ZERO(fds);
  while (i != MAX_FD)
    {
      if (g_env.fd_type[i] != FD_FREE)
	FD_SET(i, fds);
      i = i + 1;
    }
  if (flag == READ)
    FD_SET(0, fds);
}

static t_msg	**find_fd_read_serveur(fd_set *readfds, t_msg **msg,
				       t_channel ***channel)
{
  int		i;

  i = 0;
  while (i != MAX_FD)
    {
      if (g_env.fd_type[i] != FD_FREE && FD_ISSET(i, readfds))
	g_env.fct_read[i](i, &msg, channel);
      i = i + 1;
    }
  return (msg);
}

static t_msg	**find_fd_write_serveur(fd_set *writefds, t_msg **msg)
{
  int		i;
  int		pos;

  i = 0;
  while (i != MAX_FD)
    {
      if (g_env.fd_type[i] != FD_FREE && FD_ISSET(i, writefds))
	{
	  if ((pos = find_id_msg(i, msg)) != -1
	      && msg[pos]->buffer != NULL && g_env.fct_write[i] != NULL)
	    g_env.fct_write[i](i, &msg, NULL);
	}
      i = i + 1;
    }
  return (msg);
}

void		parser(t_msg **msg)
{
  int		error;
  fd_set	readfds;
  fd_set	writefds;
  t_channel	**channel;

  error = 0;
  channel = NULL;
  while (error != -1)
    {
      init_fd_listen(&readfds, READ);
      init_fd_listen(&writefds, WRITE);
      if ((error = xselect(find_max_fd(), &readfds, &writefds)) != -1)
	{
	  msg = find_fd_read_serveur(&readfds, msg, &channel);
	  msg = find_fd_write_serveur(&writefds, msg);
	}
    }
  delete_all_channel(channel);
  delete_msg(msg);
}
