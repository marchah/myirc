/*
** channel_utils.c for channel_utils in /home/marcha_j//test/c/irc/proj
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Sun Apr  3 22:42:09 2005 hugo marchadier
** Last update Fri Apr 20 17:16:36 2012 hugo marchadier
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>

#include	"defines.h"
#include	"fct_msg.h"
#include	"fct_annexe.h"

int		find_one_channel(t_channel **channel, char *name)
{
  int		i;

  i = 0;
  while (channel != NULL && channel[i] != NULL)
    {
      if (strcmp(channel[i]->name, name) == 0)
	  return (i);
      i = i + 1;
    }
  return (UNUSED);
}

eBool		check_if_copy(t_channel *channel)
{
  int		i;

  i = 0;
  while (channel != NULL && i != MAX_FD)
    {
      if (channel->id[i] != UNUSED)
	return (E_TRUE);
      i = i + 1;
    }
  return (E_FALSE);
}

int		find_size_tab_channel(t_channel **channel)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (channel != NULL && channel[i] != NULL)
    {
      if (check_if_copy(channel[i]) == E_TRUE)
	count = count + 1;
      i = i + 1;
    }
  return (count);
}

int		channel_verif(t_msg **msg, char **name, int id, int size)
{
  int		pos;

  if ((pos = find_id_msg(id, msg)) == UNUSED)
    {
      fprintf(stderr, "Error: Invalid id.\n");
      return (UNUSED);
    }
  if (strlen_tab(name) < size)
    {
      fprintf(stderr, "Error: transmition failed.\n");
      return (UNUSED);
    }
  return (pos);
}

t_channel	*cpy_channel(t_channel *channel, char *name,
			     eBool init, int id)
{
  t_channel	*new;
  int		i;

  i = 0;
  new = xmalloc_serveur(sizeof(*new));
  if (init == E_TRUE)
    {
      snprintf(new->name, MAX_NAME - 1, "%s", name);
      memset(new->id, UNUSED, MAX_FD);
      new->id[id] = id;
    }
  else
    {
      snprintf(new->name, MAX_NAME - 1, "%s", channel->name);
      while (i != MAX_FD)
	{
	  new->id[i] = channel->id[i];
	  i = i + 1;
	}
    }
  return (new);
}
