/*
** fct_send_msg.c for fct_send_msg in /home/marcha_j//svn_rendu/c/myirc-2015-2014s-marcha_j/Serveur
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Wed Apr  6 11:18:46 2005 hugo marchadier
** Last update Fri Apr 20 18:12:12 2012 hugo marchadier
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>

#include	"defines.h"
#include	"fct_msg.h"
#include	"fct_annexe.h"
#include	"channel_utils.h"

char		*add_msg(char *buffer, char *str, char sep)
{
  char		*new_msg;

  if (buffer == NULL)
    {
      new_msg = xmalloc_serveur(strlen(str) + 2);
      snprintf(new_msg, strlen(str) + 2, "%s%c", str, sep);
    }
  else
    {
      new_msg = xmalloc_serveur(strlen(buffer) + strlen(str) + 2);
      snprintf(new_msg, strlen(buffer) + strlen(str) + 2,
	       "%s%s%c", buffer, str, sep);
      free(buffer);
    }
  return (new_msg);
}

char		*send_channel(char *str, char *name_channel, char sep)
{
  str = add_msg(str, CHANNEL_FLAG, '[');
  str = add_msg(str, name_channel, ']');
  str = add_msg(str, "", sep);
  return (str);
}

char		*send_user(char *str, char *nick, char sep, eBool flag)
{
  str = add_msg(str, NICK_FLAG, '[');
  str = add_msg(str, nick, ']');
  if (flag == E_TRUE)
    str = add_msg(str, ":", sep);
  else
    str = add_msg(str, "", sep);
  return (str);
}

char		*send_serveur(char *str, char *msg, char sep)
{
  str = add_msg(str, SERVEUR, ' ');
  str = add_msg(str, msg, sep);
  return (str);
}

void		send_all_users(t_msg ***msg, t_channel *channel,
			       int id, char *str)
{
  int		j;
  int		pos_dest;

  j = 0;
  while (j != MAX_FD)
    {
      if (g_env.fd_type[j] == FD_CLIENT && channel->id[j]
	  != UNUSED && (pos_dest = find_id_msg(j, *msg)) != UNUSED)
	{
	  (*msg)[pos_dest]->buffer = send_channel((*msg)[pos_dest]->buffer,
						  channel->name, '\0');
	  (*msg)[pos_dest]->buffer = send_user((*msg)[pos_dest]->buffer,
					       g_env.name[id], ' ', E_TRUE);
	  (*msg)[pos_dest]->buffer = add_msg((*msg)[pos_dest]->buffer,
					     str, '\0');
	}
      j = j + 1;
    }
}
