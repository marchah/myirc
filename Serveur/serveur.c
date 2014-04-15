/*
** serveur.c for serveur in /home/marcha_j//test/c/irc/proj/Serveur
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Mon Apr 16 15:43:01 2012 hugo marchadier
** Last update Wed Apr  6 22:00:20 2005 hugo marchadier
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<string.h>
#include	<errno.h>

#include	<arpa/inet.h>

#include	"defines.h"
#include	"xfct.h"
#include	"xfct_serveur.h"
#include	"serveur.h"
#include	"fct_msg.h"
#include	"fct_msg_serveur.h"
#include	"fct_annexe.h"
#include	"check_command.h"
#include	"fct_send_msg.h"
#include	"channel_utils.h"

void		client_read_serveur(int fd, t_msg ***msg, t_channel ***channel)
{
  int		ret;
  char		buffer[SIZE_BUFFER];

  (void)channel;
  errno = 0;
  if ((ret = read(fd, buffer, SIZE_BUFFER - 1)) == -1)
    {
      fprintf(stderr, "Error: read failed, %s\n", strerror(errno));
      delete_msg(*msg);
      close_serveur();
      exit(EXIT_FAILURE);
    }
  if (ret != 0)
    {
      buffer[ret] = '\0';
      check_command(buffer, msg, channel, fd);
    }
}

void		client_write_serveur(int fd, t_msg ***msg, t_channel ***channel)
{
  int		pos;
  int		ret;

  (void)channel;
  if ((pos = find_id_msg(fd, *msg)) == -1)
    {
      fprintf(stderr, "Error: can't find fd %d\n", fd);
      return ;
    }
  if ((*msg)[pos]->buffer == NULL)
    return ;
  errno = 0;
  if ((ret = write(fd, (*msg)[pos]->buffer + (*msg)[pos]->len,
		   strlen((*msg)[pos]->buffer) - (*msg)[pos]->len)) == -1)
    {
      fprintf(stderr, "Error: write failed, %s\n", strerror(errno));
      return ;
    }
  if (ret < (int)(strlen((*msg)[pos]->buffer) - (*msg)[pos]->len))
    (*msg)[pos]->len += ret;
  else
    init_msg_buffer(msg, pos);
}

void		server_read(int socket, t_msg ***msg, t_channel ***channel)
{
  int		new_client;
  static int	count = 1;

  (void)channel;
  new_client = xaccept(socket);
  g_env.fd_type[new_client] = FD_CLIENT;
  g_env.fct_read[new_client] = client_read_serveur;
  g_env.fct_write[new_client] = client_write_serveur;
  snprintf(g_env.name[new_client], MAX_NAME, "Unknow %d", count);
  *msg = add_msg_serveur(*msg, new_client);
  count = count + 1;
  if ((new_client = channel_verif(*msg, NULL, new_client, UNUSED)) == UNUSED)
    return ;
  (*msg)[new_client]->buffer = send_serveur((*msg)[new_client]->buffer,
				     "You connect to the server.", '\n');
}

t_msg		**init_serveur(t_msg **msg)
{
  int		socket;

  socket = xsocket(PF_INET, SOCK_STREAM, 0);
  xbind(socket, g_env.port);
  xlisten(socket);
  g_env.fd_type[socket] = FD_SERVER;
  g_env.fct_read[socket] = server_read;
  g_env.fct_write[socket] = NULL;
  g_env.fd_type[0] = FD_STDIN;
  g_env.fct_read[0] = client_read_serveur;
  g_env.fct_write[0] = client_write_serveur;
  msg = add_msg_serveur(msg, 0);
  msg = add_msg_serveur(msg, socket);
  return (msg);
}

void		close_serveur()
{
  int		i;
  int		fd_serveur;

  i = 0;
  while (i != MAX_FD)
    {
      if (g_env.fd_type[i] == FD_CLIENT)
	{
	  close(i);
	}
      else if (g_env.fd_type[i] == FD_SERVER)
	fd_serveur = i;
      i = i + 1;
    }
  close(fd_serveur);
}
