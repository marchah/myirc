/*
** my_str_to_word_tab.c for  in /home/l-huil_o//test/my_irc
** 
** Made by olivier l-huillier
** Login   <l-huil_o@epitech.net>
** 
** Started on  Mon Apr 16 17:14:58 2012 olivier l-huillier
** Last update Wed Apr 18 17:20:31 2012 hugo marchadier
*/

#include		<stdlib.h>
#include		<string.h>

#include		"defines.h"
#include		"fct_annexe.h"

static unsigned int	get_nb_words(char *s)
{
  unsigned int		i;
  unsigned int		nb_words;

  nb_words = 0;
  i = 0;
  while (s[i])
    {
      while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
	++i;
      if (s[i])
	++nb_words;
      while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
	++i;
    }
  return (nb_words);
}

static unsigned int	get_word_len(char *s)
{
  unsigned int		i;

  i = 0;
  while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
    ++i;
  return (i);
}

static char		*copy_next_word(char *s, unsigned int *pos)
{
  unsigned int		i;
  unsigned int		len;
  char			*word;

  i = *pos;
  while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
    ++i;
  len = get_word_len(&s[i]);
  word = xmalloc_client(sizeof(*word) * (len + 1));
  word[len] = '\0';
  strncpy(word, &s[i], len);
  *pos = i + len + 1;
  return (word);
}

char			**str_to_tab_client(char *s)
{
  unsigned int		nb_words;
  char			**tab;
  unsigned int		i;
  unsigned int		cursor;

  nb_words = get_nb_words(s);
  tab = xmalloc_client(sizeof(*tab) * (nb_words + 1));
  tab[nb_words] = NULL;
  i = 0;
  cursor = 0;
  while (i < nb_words)
    {
      tab[i] = copy_next_word(s, &cursor);
      ++i;
    }
  return (tab);
}

void			free_tab(char **t)
{
  unsigned int		i;

  i = 0;
  while (t[i])
    free(t[i++]);
  free(t);
}
