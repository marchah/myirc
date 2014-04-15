/*
** xfct_client.c for xfct_client in /home/marcha_j//test/c/ftp/tp/Client
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Mon Apr  2 16:15:33 2012 hugo marchadier
** Last update Tue Apr  5 23:03:03 2005 hugo marchadier
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<unistd.h>
#include		<string.h>
#include		<errno.h>

#include		<sys/socket.h>
#include		<netinet/in.h>
#include		<arpa/inet.h>

#include		"defines.h"
#include		"client.h"
#include		"fct_annexe.h"
#include		"fct_msg.h"

void			xconnect(int port, in_addr_t machine)
{
  struct sockaddr_in	sin;
  int			errno;

  errno = 0;
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = machine;
  if (connect(g_client, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
    {
      fprintf(stderr, "Error: connect failed, %s.\n", strerror(errno));
      close_client();
      exit(EXIT_FAILURE);
    }
}

char			*xread(int fd_in, t_msg **msg)
{
  int			ret;
  char			buffer[SIZE_BUFFER];
  char			*str;

  errno = 0;
  if ((ret = read(fd_in, buffer, SIZE_BUFFER - 1)) == -1)
    {
      fprintf(stderr, "Error: read failed, %s\n", strerror(errno));
      delete_msg(msg);
      close_client();
      exit(EXIT_FAILURE);
    }
  buffer[ret] = '\0';
  if (ret == 0)
    return (NULL);
  str = xmalloc_client(sizeof(char*) * (ret + 1));
  str = strdup(buffer);
  return (str);
}
