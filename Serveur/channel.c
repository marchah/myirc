/*
** channel.c for channel in /home/marcha_j//test/c/irc/proj
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Tue Apr 17 15:49:13 2012 hugo marchadier
** Last update Wed Apr  6 21:16:56 2005 hugo marchadier
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

void		list(t_msg ***msg, t_channel ***channel,
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
      if (strlen_tab(name) > 0 && strstr((*channel)[i]->name, name[0]) != NULL)
	(*msg)[pos]->buffer = send_channel((*msg)[pos]->buffer,
					   (*channel)[i]->name, '\n');
      else if (strlen_tab(name) == 0)
	(*msg)[pos]->buffer = send_channel((*msg)[pos]->buffer,
					   (*channel)[i]->name, '\n');
      else
	count_channel = -1;
      count_channel++;
      i = i + 1;
    }
  if (count_channel <= 0)
    (*msg)[pos]->buffer = add_msg((*msg)[pos]->buffer, "Any Channel", '\n');
}

void		part_channel(t_msg ***msg, t_channel ***channel,
			     char **name, int id)
{
  int		pos;
  int		i;

  i = 0;
  if ((pos = channel_verif(*msg, name, id, 1)) == UNUSED)
    return ;
  (*msg)[pos]->buffer = add_msg((*msg)[pos]->buffer, SERVEUR, ' ');
  while (*channel != NULL && (*channel)[i] != NULL)
      {
	if ((*channel)[i]->id[id] != UNUSED
	    && strcmp(name[0], (*channel)[i]->name) == 0)
	  {
	    part_channel_follow(msg, *channel, name, id);
	    (*channel)[i]->id[id] = UNUSED;
	    (*channel) = delete_channel_unused(*channel, i);
	    (*msg)[pos]->buffer = add_msg((*msg)[pos]->buffer, QUIT_C, '\n');
	    return ;
	  }
	i = i + 1;
      }
  (*msg)[pos]->buffer = add_msg((*msg)[pos]->buffer, NOT_THIS_C, '\n');
}

void		channel_msg_all_users(t_msg ***msg, t_channel ***channel,
				      char *str, int id)
{
 int		pos;
 int		i;

  if ((pos = channel_verif(*msg, NULL, id, 0)) == UNUSED)
    return ;
  i = 0;
  while ((*channel) != NULL && (*channel)[i] != NULL)
    {
      if ((*channel)[i]->id[id] != UNUSED
	  && strcmp((*channel)[i]->name, (*msg)[pos]->channel) == 0)
	{
	  send_all_users(msg, (*channel)[i], id, str);
	  return ;
	}
      i = i + 1;
    }
  (*msg)[pos]->buffer = send_serveur((*msg)[pos]->buffer, NOT, '\n');
}

void		join_channel(t_msg ***msg, t_channel ***channel,
			     char **name, int id)
{
  int		channel_user;
  int		pos;

  if ((pos = channel_verif(*msg, name, id, 1)) == UNUSED)
    return ;
  if ((channel_user = find_one_channel(*channel, name[0])) == UNUSED)
    {
      *channel = add_new_channel(*channel, name[0], id);
      if (strlen((*msg)[pos]->channel) == 0)
	snprintf((*msg)[pos]->channel, MAX_NAME - 1, name[0]);
      (*msg)[pos]->buffer = send_serveur((*msg)[pos]->buffer, CONNECT, '\n');
    }
  else
    if ((*channel)[channel_user]->id[id] == UNUSED)
      {
	(*channel)[channel_user]->id[id] = id;
	if (strlen((*msg)[pos]->channel) == 0)
	  snprintf((*msg)[pos]->channel, MAX_NAME - 1, name[0]);
	(*msg)[pos]->buffer = send_serveur((*msg)[pos]->buffer, CONNECT, '\n');
      }
    else
      (*msg)[pos]->buffer = send_serveur((*msg)[pos]->buffer, ALREADY, '\n');
}

void		channel_nickname(t_msg ***msg, t_channel ***channel,
				 char **name, int id)
{
  int		pos;
  int		i;

  (void)channel;
  if ((pos = channel_verif(*msg, name, id, 1)) == UNUSED)
    return ;
  i = 0;
  (*msg)[pos]->buffer = add_msg((*msg)[pos]->buffer, SERVEUR, ' ');
  while (i != MAX_FD)
    {
      if (g_env.fd_type[i] == FD_CLIENT && strcmp(g_env.name[i], name[0]) == 0)
	{
	  (*msg)[pos]->buffer = add_msg((*msg)[pos]->buffer, ALREADY_N, '\n');
	  return ;
	}
      i = i + 1;
    }
  snprintf(g_env.name[id], MAX_NAME - 1, "%s", name[0]);
  (*msg)[pos]->buffer = add_msg((*msg)[pos]->buffer, CHANGE_N, '\n');
}
