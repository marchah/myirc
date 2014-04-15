/*
** exec_command.c for  in /home/l-huil_o//test/my_irc
** 
** Made by olivier l-huillier
** Login   <l-huil_o@epitech.net>
** 
** Started on  Tue Apr 17 16:33:43 2012 olivier l-huillier
** Last update Fri Apr 20 16:54:51 2012 olivier l-huillier
*/

#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	<ctype.h>

#include	"defines.h"
#include	"str_to_tab.h"
#include	"cmd_client.h"
#include	"exec_command.h"
#include	"xfct.h"
#include	"graphics.h"

t_cmd_tab	fcts[] = {
  {"/JOIN", cmd_join},
  {"/NICK", cmd_nick},
  {"/PART", cmd_part},
  {"/USERS", cmd_users},
  {"/MSG", cmd_msg},
  {"/LIST", cmd_list},
  {"/QUIT", cmd_quit},
  {"/CHANNELS", cmd_channels},
  {"/FOLLOW", cmd_follow},
  {NULL, NULL}
};

t_msg		**exec_command(char *cmd, t_msg **msg, void *win_msg)
{
  int		i;
  char		**tab;

  tab = str_to_tab_client(cmd);
  if (tab != NULL && tab[0] != NULL)
    {
      i = 0;
      while (fcts[i].str && strcmp(str_to_upper(tab[0]), fcts[i].str) != 0)
	++i;
      if (fcts[i].fct)
	msg = fcts[i].fct(&tab[1], msg, win_msg);
      else if (tab[0][0] != '/')
	msg = cmd_msg_users_channel(cmd, msg, win_msg);
      else
	print_msg(win_msg, "Error: unknown command!\n");
    }
  free_tab(tab);
  return (msg);
}
