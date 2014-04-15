/*
** fct_msg.c for fct_msg in /home/marcha_j//test/c/irc/proj
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Sat Apr  2 20:08:13 2005 hugo marchadier
** Last update Wed Apr  6 21:57:34 2005 hugo marchadier
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>

#include	"defines.h"
#include	"serveur.h"
#include	"fct_msg.h"
#include	"fct_annexe.h"
#include	"channel_utils.h"

t_msg		*init_msg_serveur(int fd)
{
  t_msg		*tmp;

  tmp = xmalloc_serveur(sizeof(*tmp));
  tmp->buffer = NULL;
  tmp->len = 0;
  tmp->fd = fd;
  memset(tmp->channel, 0, MAX_NAME - 1);
  return (tmp);
}

t_msg		**add_msg_serveur(t_msg **msg, int fd)
{
  t_msg		**new;
  int		i;

  i = 0;
  new = xmalloc_serveur(sizeof(*new) * (msg_len(msg) + 2));
  while (i != msg_len(msg))
    {
      new[i] = init_msg_serveur(0);
      cp_msg(msg[i], new[i]);
      i = i + 1;
    }
  new[i] = init_msg_serveur(fd);
  new[i + 1] = NULL;
  delete_msg(msg);
  return (new);
}

t_msg		**delete_msg_serveur(t_msg **msg, int pos)
{
  t_msg		**new;
  int		i;
  int		j;

  i = 0;
  if (msg_len(msg) < 2)
    {
      delete_msg(msg);
      return (NULL);
    }
  j = 0;
  new = xmalloc_serveur(sizeof(*new) * (msg_len(msg)));
  while (i < msg_len(msg) - 1)
    {
      if (i != pos)
	{
	  new[j] = init_msg_serveur(0);
	  cp_msg(msg[i], new[j]);
	  j = j + 1;
	}
      i = i + 1;
    }
  new[j] = NULL;
  delete_msg(msg);
  return (new);
}

void		user_quit(t_msg ***msg, t_channel ***channel, char **name, int id)
{
  int		pos;
  int		i;

  if ((pos = channel_verif(*msg, name, id, 0)) == UNUSED)
    return ;
  i = 0;
  while (*channel != NULL && (*channel)[i] != NULL)
    {
      (*channel)[i]->id[id] = UNUSED;
      i = i + 1;
    }
  printf("[%s] quite the server.\n", g_env.name[id]);
  *msg = delete_msg_serveur(*msg, pos);
  g_env.fd_type[id] = FD_FREE;
  g_env.fct_read[id] = NULL;
  g_env.fct_write[id] = NULL;
  g_env.name[id][0] = '\0';
}
