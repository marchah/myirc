/*
** check_command.c for check_command in /home/marcha_j//test/c/irc/proj
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Sun Apr  3 22:00:02 2005 hugo marchadier
** Last update Fri Apr 20 16:43:46 2012 hugo marchadier
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>

#include	"defines.h"
#include	"check_command.h"
#include	"str_to_tab.h"
#include	"fct_msg_serveur.h"
#include	"channel_bonus.h"

t_tab_server	fcts[] =
  {
    {"/join", join_channel},
    {"/nick", channel_nickname},
    {"/part", part_channel},
    {"/users", list_users_channel},
    {"/msg", private_msg_channel},
    {"/list", list},
    {"/quit", user_quit},
    {"/channels", list_channels},
    {"/follow", follow_channel},
    {NULL, NULL}
  };

void		check_command(char *buffer, t_msg ***msg,
			      t_channel ***channel, int id)
{
  char		**tab;
  int		i;

  tab = str_to_tab_serveur(buffer);
  if (tab != NULL && tab[0] != NULL)
    {
      i = 0;
      while (fcts[i].str && strcmp(tab[0], fcts[i].str) != 0)
	  ++i;
     if (fcts[i].fct)
	fcts[i].fct(msg, channel, &tab[1], id);
      else if (tab[0][0] != '/')
	channel_msg_all_users(msg, channel, buffer, id);
      else
	fprintf(stderr, "Error: unknown command!\n");
    }
  free_tab(tab);
}
