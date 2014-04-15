/*
** cmd_client_bonus.c for cmd client bonus in /home/marcha_j//svn_rendu/c/myirc-2015-2014s-marcha_j/Client
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Wed Apr  6 10:56:27 2005 hugo marchadier
** Last update Fri Apr 20 18:30:50 2012 olivier l-huillier
*/

#include	<stdio.h>

#include	"defines.h"
#include	"cmd_client.h"
#include	"fct_msg_client.h"
#include	"graphics.h"

t_msg		**cmd_quit(char **args, t_msg **msg, void *win_msg)
{
  (void)args;
  (void)win_msg;
  msg = send_msg(msg, 1, "/quit", "");
  return (msg);
}

t_msg		**cmd_channels(char **args, t_msg **msg, void *win_msg)
{
  (void)args;
  (void)win_msg;
  msg = send_msg(msg, 1, "/channels", "");
  return (msg);
}

t_msg		**cmd_follow(char **args, t_msg **msg, void *win_msg)
{
  (void)win_msg;
  if (!args[0])
    {
      print_msg(stderr, "Usage: /follow CHANNEL\n");
      return (msg);
    }
  msg = send_msg(msg, 1, "/follow", args[0]);
  return (msg);
}

t_msg		**cmd_msg_users_channel(char *str, t_msg **msg, void *win_msg)
{
  (void)win_msg;
  msg = send_msg(msg, 1, str, "");
  return (msg);
}
