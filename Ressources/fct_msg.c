/*
** fct_msg.c for fct_msg in /home/marcha_j//test/c/irc/proj
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Sat Apr  2 20:20:24 2005 hugo marchadier
** Last update Thu Apr 19 16:46:42 2012 hugo marchadier
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>

#include	"defines.h"

int		msg_len(t_msg **msg)
{
  int		i;

  i = 0;
  while (msg != NULL && msg[i] != NULL)
    i = i + 1;
  return (i);
}

int		find_id_msg(int fd, t_msg **msg)
{
  int		i;

  i = 0;
  while (msg != NULL && msg[i] != NULL)
    {
      if (msg[i]->fd == fd)
	return (i);
      i = i + 1;
    }
  return (-1);
}

void            cp_msg(t_msg *src, t_msg *dest)
{
 if (src == NULL)
    {
      dest = NULL;
      return ;
    }
  if (src->buffer == NULL)
    dest->buffer = NULL;
  else
    dest->buffer = strdup(src->buffer);
  dest->len = src->len;
  dest->fd = src->fd;
  snprintf(dest->channel, MAX_NAME - 1, src->channel);
}

void		delete_msg(t_msg **msg)
{
  int	i;

  i = 0;
  while (msg != NULL && msg[i] != NULL)
    {
      if (msg[i]->buffer != NULL)
	free(msg[i]->buffer);
      free(msg[i]);
      i = i + 1;
    }
  if (msg != NULL)
    free(msg);
}
