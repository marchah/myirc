/*
** cmd_client1.c for cmd client1 in /home/marcha_j//test/c/irc/proj/Client
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Tue Apr 17 17:01:03 2012 hugo marchadier
** Last update Fri Apr 20 18:27:59 2012 olivier l-huillier
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<string.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>

#include	<netdb.h>

#include	"defines.h"
#include	"xfct_client.h"
#include	"fct_msg_client.h"
#include	"fct_annexe.h"
#include	"cmd_client.h"
#include	"graphics.h"

t_msg		**cmd_msg(char **args, t_msg **msg, void *win_msg)
{
  int		i;

  if (!args[0] || !args[1])
    {
      print_msg(win_msg, "Usage: /msg NICKNAME MESSAGE\n");
      return (msg);
    }
  i = 1;
  msg = send_msg(msg, 1, "/msg", args[0]);
  while (args[i] != NULL)
    {
      msg = send_msg(msg, 1, args[i], "");
      i = i + 1;
    }
  return (msg);
}

t_msg		**cmd_list(char **args, t_msg **msg, void *win_msg)
{
  (void)win_msg;
  if (!args[0])
    msg = send_msg(msg, 1, "/list", "");
  else
    msg = send_msg(msg, 1, "/list", args[0]);
  return (msg);
}
