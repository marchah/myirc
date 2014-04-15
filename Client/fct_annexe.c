/*
** fct_annexe.c for fct_annexe in /home/marcha_j//test/c/irc/proj
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Sat Apr  2 23:19:44 2005 hugo marchadier
** Last update Sat Apr  2 23:34:07 2005 hugo marchadier
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<errno.h>

#include	"defines.h"
#include	"client.h"

void		*xmalloc_client(size_t size)
{
  void		*ptr;

  errno = 0;
  if ((ptr = malloc(size)) == NULL)
    {
      fprintf(stderr, "Error: malloc failed, %s.\n", strerror(errno));
      close_client();
      exit(EXIT_FAILURE);
    }
  return (ptr);
}

