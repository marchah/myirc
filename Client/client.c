/*
** client.c for client in /home/marcha_j//test/c/irc/proj/Client
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Mon Apr 16 18:15:20 2012 hugo marchadier
** Last update Fri Apr 20 17:39:26 2012 hugo marchadier
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<unistd.h>
#include		<string.h>
#include		<errno.h>

#include		<sys/socket.h>
#include		<netinet/in.h>
#include		<arpa/inet.h>
#include		<netdb.h>

#include		"xfct.h"
#include		"defines.h"
#include		"client.h"
#include		"xfct_client.h"
#include		"fct_msg.h"
#include		"fct_annexe.h"
#include		"graphics.h"

static void		check_exit_server(char *buffer, t_msg **msg)
{
  if (strncmp(buffer, SERVER_EXIT, strlen(SERVER_EXIT) - 1) == 0)
    {
      fprintf(stderr, "The server is closed\n");
      free(buffer);
      delete_msg(msg);
      end_ncurses(NULL);
      close_client();
      exit(EXIT_SUCCESS);
    }
}

void			client_read(int fd_in, int fd_out, t_msg ***msg)
{
  int			pos;
  char			*buffer;
  char			*str;

  buffer = xread(fd_in, *msg);
  if (buffer != NULL)
    {
      check_exit_server(buffer, *msg);
      if ((pos = find_id_msg(fd_out, *msg)) != -1)
	{
	  if ((*msg)[pos]->buffer != NULL)
	    {
	      str = xmalloc_client(sizeof(char) * (strlen((*msg)[pos]->buffer)
						   + strlen(buffer) + 1));
	      snprintf(str, strlen((*msg)[pos]->buffer) + strlen(buffer) + 1,
		       "%s%s", (*msg)[pos]->buffer, buffer);
	      free((*msg)[pos]->buffer);
	      (*msg)[pos]->buffer = str;
	    }
	  else
	    (*msg)[pos]->buffer = strdup(buffer);
	}
      free(buffer);
    }
}

void			client_write(int fd, t_msg ***msg, void *win_msg)
{
  int			pos;
  int			ret;

  if ((pos = find_id_msg(fd, *msg)) == -1)
    {
      print_msg(win_msg, "Error: can't find fd %d\n", fd);
      return ;
    }
  if ((*msg)[pos]->buffer == NULL)
    return ;
  errno = 0;
  if ((ret = write(fd, (*msg)[pos]->buffer + (*msg)[pos]->len,
		   strlen((*msg)[pos]->buffer) - (*msg)[pos]->len)) == -1)
    {
      print_msg(win_msg, "Error: write failed, %s\n", strerror(errno));
      return ;
    }
  if (ret < (int)(strlen((*msg)[pos]->buffer) - (*msg)[pos]->len))
    (*msg)[pos]->len += ret;
  else
    {
      (*msg)[pos]->len = 0;
      free((*msg)[pos]->buffer);
      (*msg)[pos]->buffer = NULL;
    }
}

void			init_client(int port, char *ip)
{
  struct protoent       *protocole;

  protocole = xgetprotobyname("TCP");
  g_client = xsocket(AF_INET, SOCK_STREAM, protocole->p_proto);
  xconnect(port, inet_addr(ip));
}

void			close_client()
{
  close(g_client);
}
