/*
** channel_bonus.c for channel bonus in /home/marcha_j//svn_rendu/c/myirc-2015-2014s-marcha_j/Serveur
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Wed Apr  6 11:24:30 2005 hugo marchadier
** Last update Fri Apr 20 17:30:27 2012 hugo marchadier
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>

#include	"defines.h"
#include	"fct_msg.h"
#include	"fct_send_msg.h"
#include	"channel_utils.h"

static void	send_msg_user(t_msg ***msg, t_channel ***channel,
			      int pos, int i)
{
  int		j;

  j = 0;
  (*msg)[pos]->buffer = send_channel((*msg)[pos]->buffer,
				     (*channel)[i]->name, '\n');
  while (j != MAX_FD)
    {
      if ((*channel)[i]->id[j] != UNUSED)
	(*msg)[pos]->buffer = send_user((*msg)[pos]->buffer,
					g_env.name[(int)
						   ((*channel)[i]->id[j])],
					'\n', E_FALSE);
      j = j + 1;
    }
}

void		list_channels(t_msg ***msg, t_channel ***channel,
			      char **name, int id)
{
  int		pos;
  int		i;
  int		count_channel;

  count_channel = 0;
  if ((pos = channel_verif(*msg, name, id, 0)) == UNUSED)
    return ;
  i = 0;
  (*msg)[pos]->buffer = add_msg((*msg)[pos]->buffer, SERVEUR, '\n');
  while (*channel != NULL && (*channel)[i] != NULL)
    {
      send_msg_user(msg, channel, pos, i);
      count_channel++;
      i = i + 1;
    }
  if (count_channel == 0)
    (*msg)[pos]->buffer = add_msg((*msg)[pos]->buffer, "Any Channel", '\n');
}

void		follow_channel(t_msg ***msg, t_channel ***channel,
				 char **name, int id)
{
  int		i;
  int		pos;

  i = 0;
  if ((pos = channel_verif(*msg, name, id, 1)) == UNUSED)
    return ;
  (*msg)[pos]->buffer = add_msg((*msg)[pos]->buffer, SERVEUR, ' ');
  while (*channel != NULL && (*channel)[i] != NULL)
    {
      if ((*channel)[i]->id[id] != UNUSED && strcmp(name[0],
						    (*channel)[i]->name) == 0)
	{
	  snprintf((*msg)[pos]->channel, MAX_NAME - 1, (*channel)[i]->name);
	  (*msg)[pos]->buffer = add_msg((*msg)[pos]->buffer,
					"You follow this channel.", '\n');
	  return ;
	}
      i = i + 1;
    }
  (*msg)[pos]->buffer = add_msg((*msg)[pos]->buffer,
				"You not connect to this channel.", '\n');
}

void		list_users_channel(t_msg ***msg, t_channel ***channel,
				   char **name, int id)
{
  int		channel_user;
  int		i;
  int		pos;

  i = 0;
  if ((pos = channel_verif(*msg, name, id, 0)) == UNUSED)
    return ;
  if ((channel_user = find_one_channel(*channel,
				       (*msg)[pos]->channel)) != UNUSED)
    {
      (*msg)[pos]->buffer = add_msg((*msg)[pos]->buffer, SERVEUR, '\n');
      while (i != MAX_FD)
	{
	  if ((*channel)[channel_user]->id[i] != UNUSED)
	    (*msg)[pos]->buffer = send_user((*msg)[pos]->buffer,
					    g_env.name[i], '\n', E_FALSE);
	  i = i + 1;
	}
    }
  else
      (*msg)[pos]->buffer = send_serveur((*msg)[pos]->buffer, NOT_C, '\n');
}

void		delete_all_channel(t_channel **channel)
{
  int		i;

  i = 0;
  while (channel != NULL && channel[i] != NULL)
    {
      free(channel[i]);
      i = i + 1;
    }
  if (channel != NULL)
    free(channel);
}
