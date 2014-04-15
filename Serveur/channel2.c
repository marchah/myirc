/*
** channel2.c for channel2 in /home/marcha_j//svn_rendu/c/myirc-2015-2014s-marcha_j
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Fri Apr 20 17:01:36 2012 hugo marchadier
** Last update Fri Apr 20 17:16:01 2012 hugo marchadier
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>

#include	"defines.h"
#include	"fct_annexe.h"
#include	"channel.h"
#include	"channel_utils.h"
#include	"fct_send_msg.h"
#include	"fct_msg.h"

t_channel	**add_new_channel(t_channel **channel, char *name, int id)
{
  t_channel	**tab;
  int		i;
  int		j;

  tab = xmalloc_serveur(sizeof(*tab) * (find_size_tab_channel(channel) + 2));
  i = 0;
  j = 0;
  while (channel != NULL && channel[i] != NULL)
    {
      if (check_if_copy(channel[i]) == E_TRUE)
	{
	  tab[j] = cpy_channel(channel[i], NULL, E_FALSE, id);
	  j = j + 1;
	}
      i = i + 1;
    }
  tab[j] = cpy_channel(NULL, name, E_TRUE, id);
  tab[j + 1] = NULL;
  delete_all_channel(channel);
  return (tab);
}

static void		send_private_msg(t_msg ***msg, char **name,
					 int pos_dest, int id)
{
  int		count;
  count = 1;
  (*msg)[pos_dest]->buffer = send_user((*msg)[pos_dest]->buffer,
				       g_env.name[id], ' ', E_FALSE);
  while (name[count + 1] != NULL)
    (*msg)[pos_dest]->buffer = add_msg((*msg)[pos_dest]->buffer,
				       name[count++], ' ');
  (*msg)[pos_dest]->buffer = add_msg((*msg)[pos_dest]->buffer,
				     name[count], '\n');
}

void		private_msg_channel(t_msg ***msg, t_channel ***channel,
				    char **name, int id)
{
  int		pos;
  int		pos_dest;
  int		j;

  (void)channel;
  if ((pos = channel_verif(*msg, name, id, 2)) == UNUSED)
    return ;
  j = 0;
  while (j != MAX_FD)
    {
      if (strcmp(g_env.name[j], name[0]) == 0)
	{
	  if ((pos_dest = channel_verif(*msg, name, j, 2)) == UNUSED)
	    return ;
	  send_private_msg(msg, name, pos_dest, id);
	  return ;
	}
      j = j + 1;
    }
  (*msg)[pos]->buffer = send_serveur((*msg)[pos]->buffer, UNKNOW, '\n');
}

void		part_channel_follow(t_msg ***msg, t_channel **channel,
				    char **name, int id)
{
  int		i;
  int		pos;

  i = 0;
  pos = find_id_msg(id, *msg);
  while (channel != NULL && channel[i] != NULL)
    {
      if (channel[i]->id[id] != UNUSED
	  && strcmp(name[0], channel[i]->name) != 0)
	{
	  snprintf((*msg)[pos]->channel, MAX_NAME - 1, channel[i]->name);
	  return ;
	}
      i = i + 1;
    }
  memset((*msg)[pos]->channel, 0, MAX_NAME);
}

t_channel	**delete_channel_unused(t_channel **channel, int pos)
{
  int		i;
  int		j;
  t_channel	**tab;

  if (channel == NULL || check_if_copy(channel[pos]) != E_FALSE)
    return (channel);
  if (find_size_tab_channel(channel) < 2)
    {
      delete_all_channel(channel);
      return (NULL);
    }
  tab = xmalloc_serveur(sizeof(*tab) * (find_size_tab_channel(channel)));
  i = 0;
  j = 0;
  while (i < find_size_tab_channel(channel) - 1)
    {
      if (i != pos)
	tab[j++] = cpy_channel(channel[i], NULL, E_FALSE, UNUSED);
      i = i + 1;
    }
  tab[j] = NULL;
  delete_all_channel(channel);
  return (tab);
}
