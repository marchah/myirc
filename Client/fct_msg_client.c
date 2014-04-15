/*
** fct_msg_client.c for fct_msg_client in /home/marcha_j//test/c/irc/proj
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Sat Apr  2 23:14:08 2005 hugo marchadier
** Last update Fri Apr 20 18:51:55 2012 hugo marchadier
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>

#include	"defines.h"
#include	"fct_msg.h"
#include	"fct_annexe.h"

t_msg		**send_msg(t_msg **msg, int id, char *fct, char *str)
{
  char		*new;

  if (msg[id]->buffer == NULL)
    {
      new = xmalloc_client(sizeof(*new) * (strlen(str) + 3 + strlen(fct)));
      snprintf(new, (strlen(str) + 3 + strlen(fct)), "%s %s\n", fct, str);
    }
  else
    {
      new = xmalloc_client(sizeof(*new) * (strlen(str) + 3 + strlen(fct)
					   + strlen(msg[id]->buffer)));
      snprintf(new, (strlen(str) + 3 + strlen(fct)
		     + strlen(msg[id]->buffer)), "%s%s %s\n",
	       msg[id]->buffer, fct, str);
    }
  msg[id]->buffer = new;
  return (msg);
}

t_msg		*init_msg_client(int fd)
{
  t_msg		*tmp;

  tmp = xmalloc_client(sizeof(*tmp));
  tmp->buffer = NULL;
  tmp->len = 0;
  tmp->fd = fd;
  tmp->channel[0] = '\0';
  return (tmp);
}

t_msg		**add_msg_client(t_msg **msg, int fd)
{
  t_msg		**new;
  int		i;

  i = 0;
  new = xmalloc_client(sizeof(*new) * (msg_len(msg) + 2));
  while (i != msg_len(msg))
    {
      new[i] = init_msg_client(0);
      cp_msg(msg[i], new[i]);
      i = i + 1;
    }
  new[i] = init_msg_client(fd);
  new[i + 1] = NULL;
  delete_msg(msg);
  return (new);
}
