/*
** get_connect.c for  in /home/l-huil_o//test/my_irc
** 
** Made by olivier l-huillier
** Login   <l-huil_o@epitech.net>
** 
** Started on  Tue Apr 17 18:48:57 2012 olivier l-huillier
** Last update Wed Apr  6 21:28:14 2005 hugo marchadier
*/

#include	<string.h>
#include	<stdlib.h>

#include	"defines.h"
#include	"getln.h"
#include	"str_to_tab.h"
#include	"xfct.h"
#include	"graphics.h"

static void	get_connect_params(char **port, char **machine,
				   char **tab, int *ok)
{
  *ok = 1;
  *machine = strdup(tab[1]);
  *port = (tab[2]) ? strdup(&tab[2][1]) : strdup(DEFAULT_PORT);
}

static eBool	free_mem(char *str, char **tab, eBool status)
{
  free_tab(tab);
  free(str);
  return (status);
}

eBool		get_connect(char **port, char **machine, void *win_msg)
{
  int		ok;
  char		*line;
  char		**tab;

  ok = 0;
  while (!ok)
    {
      line = getln(win_msg);
      tab = str_to_tab_client(line);
      if (tab[0] && strcmp(str_to_upper(tab[0]), "/SERVER") == 0)
	{
	  if (!tab[1] || (tab[2] && tab[2][0] != ':'))
	    print_msg(win_msg, "Usage: /server HOST [:PORT]\n");
	  else
	    get_connect_params(port, machine, tab, &ok);
	}
      else if (tab[0] && strcmp(str_to_upper(tab[0]), "/QUIT") == 0)
	return (free_mem(line, tab, E_FALSE));
      else if (tab[0])
	print_msg(win_msg, "Type /server HOST [:PORT] to connect to a server\n");
      free_mem(line, tab, E_TRUE);
    }
  return (E_TRUE);
}
