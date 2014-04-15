/*
** cmd_client2.c for  in /home/l-huil_o//test/my_irc
** 
** Made by olivier l-huillier
** Login   <l-huil_o@epitech.net>
** 
** Started on  Tue Apr 17 16:31:19 2012 olivier l-huillier
** Last update Fri Apr 20 18:29:59 2012 olivier l-huillier
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>

#include	"defines.h"
#include	"fct_msg_client.h"
#include	"fct_annexe.h"
#include	"cmd_client.h"
#include	"graphics.h"

t_msg		**cmd_join(char **args, t_msg **msg, void *win_msg)
{
  char		*chan;

  if (!args[0])
    {
      print_msg(win_msg, "Usage: /join [#]CHANNEL\n");
      return (msg);
    }
  chan = args[0];
  if (args[0][0] == '#')
    chan = &args[0][1];
  if (strlen(chan) >= MAX_NAME - 1)
    {
      print_msg(win_msg, "Error: your channel's name is too long\n");
      return (msg);
    }
  msg = send_msg(msg, 1, "/join", chan);
  return (msg);
}

t_msg		**cmd_nick(char **args, t_msg **msg, void *win_msg)
{
  if (!args[0])
    {
      print_msg(win_msg, "Usage: /nick NICKNAME\n");
      return (msg);
    }
  if (strlen(args[0]) >= MAX_NAME - 1)
    {
      print_msg(win_msg, "Error: your nickname size is too big\n");
      return (msg);
    }
  msg = send_msg(msg, 1, "/nick", args[0]);
  return (msg);
}

t_msg		**cmd_part(char **args, t_msg **msg, void *win_msg)
{
  char		*chan;

  if (!args[0])
    {
      print_msg(win_msg, "Usage: /part [#]CHANNEL\n");
      return (msg);
    }
  chan = args[0];
  if (args[0][0] == '#')
    chan = &args[0][1];
  msg = send_msg(msg, 1, "/part", chan);
  return (msg);
}

t_msg		**cmd_users(char **args, t_msg **msg, void *win_msg)
{
  (void)args;
  (void)win_msg;
  msg = send_msg(msg, 1, "/users", "");
  return (msg);
}
