/*
** fct_annexe.c for fct_annexe in /home/marcha_j//test/c/irc/proj
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Sat Apr  2 20:28:43 2005 hugo marchadier
** Last update Fri Apr 20 17:00:57 2012 hugo marchadier
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<errno.h>

#include	"defines.h"
#include	"serveur.h"

void		*xmalloc_serveur(size_t size)
{
  void		*ptr;

  errno = 0;
  if ((ptr = malloc(size)) == NULL)
    {
      fprintf(stderr, "Error: malloc failed, %s.\n", strerror(errno));
      close_serveur();
      exit(EXIT_FAILURE);
    }
  return (ptr);
}

int		strlen_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab != NULL && tab[i] != NULL)
    i = i + 1;
  return (i);
}

void		init_msg_buffer(t_msg ***msg, int pos)
{
  (*msg)[pos]->len = 0;
  free((*msg)[pos]->buffer);
  (*msg)[pos]->buffer = NULL;
}
