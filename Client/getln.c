/*
** getln.c for  in /home/l-huil_o//test/my_irc
** 
** Made by olivier l-huillier
** Login   <l-huil_o@epitech.net>
** 
** Started on  Mon Apr 16 18:15:16 2012 olivier l-huillier
** Last update Wed Apr  6 21:44:17 2005 hugo marchadier
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<ncurses.h>

#include	"defines.h"

char		*getln(void *win_msg)
{
  char		*line;
  int		x;
  int		y;

  line = malloc(sizeof(line) * BUF_SIZE);
  getmaxyx(stdscr, y, x);
  mvgetnstr(y - 1, 0, line, BUF_SIZE - 1);
  while (x--)
    mvprintw(y - 1, x, " ");
  wattron(win_msg, COLOR_PAIR(5));
  waddstr(win_msg, "$>");
  wattroff(win_msg, COLOR_PAIR(5));
  wprintw(win_msg, "%s\n", line);
  getmaxyx(stdscr, y, x);
  wmove(stdscr, y, x);
  refresh();
  wrefresh(win_msg);
  return (line);
}
