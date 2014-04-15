/*
** xlib.c for xlib in /home/marcha_j//test/c/ftp/tp
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Mon Apr  2 15:34:18 2012 hugo marchadier
** Last update Wed Apr 18 17:18:35 2012 hugo marchadier
*/

#include		<stdio.h>
#include		<stdlib.h>
#include		<string.h>
#include		<errno.h>
#include		<ctype.h>

#include		<sys/types.h>
#include		<sys/socket.h>
#include		<sys/select.h>
#include		<netdb.h>

#include		"xfct.h"

struct protoent		*xgetprotobyname(char *protocole)
{
  struct protoent	*tmp;
  int			errno;

  errno = 0;
  if ((tmp = getprotobyname(protocole)) == NULL)
    {
      fprintf(stderr, "Error: getprotobyname failed, %s.\n", strerror(errno));
      exit(EXIT_FAILURE);
    }
  return (tmp);
}

int			xsocket(int domain, int type, int protocole)
{
  int			fd;
  int			errno;

  errno = 0;
  if ((fd = socket(domain, type, protocole)) == -1)
    {
      fprintf(stderr, "Error: socket failed, %s.\n", strerror(errno));
      exit(EXIT_FAILURE);
    }
  return (fd);
}

int			xselect(int n, fd_set *readfds, fd_set *writefds)
{
  int			error;
  int			errno;

  errno = 0;
  if ((error = select(n, readfds, writefds, NULL, NULL)) == -1)
    fprintf(stderr, "Error: select failed, %s.\n", strerror(errno));
  return (error);
}

char		*str_to_upper(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      str[i] = toupper(str[i]);
      ++i;
    }
  return (str);
}
