/*
** graphics.c for  in /home/l-huil_o//test/my_irc/myirc-2015-2014s-marcha_j/Client
** 
** Made by olivier l-huillier
** Login   <l-huil_o@epitech.net>
** 
** Started on  Fri Apr 20 15:47:55 2012 olivier l-huillier
** Last update Wed Apr  6 22:10:02 2005 hugo marchadier
*/

#include	<stdarg.h>

#include	"graphics.h"
#include	"defines.h"

void		*init_ncurses()
{
  int		x;
  int		y;
  void		*win_msg;

  initscr();
  getmaxyx(stdscr, y, x);
  if ((win_msg = newwin(y - 2, x , 0, 0)) == NULL)
    return (NULL);
  scrollok(win_msg, TRUE);
  if (has_colors() != FALSE)
    start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_CYAN, COLOR_BLACK);
  init_pair(3, COLOR_GREEN, COLOR_BLACK);
  init_pair(4, COLOR_WHITE, COLOR_BLACK);
  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
  refresh();
  return (win_msg);
}

void		end_ncurses(void *win_msg)
{
  if (win_msg != NULL)
    delwin(win_msg);
  endwin();
}

static int	print_color(void *win_msg, char *msg, int color, int p)
{
  int		pos;

  pos = p;
  wattron(win_msg, color);
  while (msg[pos] != '\0' && msg[pos] != '\n' && msg[pos] != ']')
    {
      waddch(win_msg, msg[pos]);
      pos = pos + 1;
    }
  if (msg[pos] == ']')
    waddch(win_msg, msg[pos++]);
  if (msg[pos] == ':')
    waddch(win_msg, msg[pos++]);
  if (msg[pos] == '\n')
    waddch(win_msg, msg[pos++]);
  wattroff(win_msg, color);
  return (pos);
}

void		print_msg(void *win_msg, char *msg, ...)
{
  va_list	ap;
  int		pos;
  int		x;
  int		y;

  pos = 0;
  va_start(ap, msg);
  while (msg[pos] == '1' || msg[pos] == '2' || msg[pos] == '3')
    {
      if (msg[pos] == '1')
	pos = print_color(win_msg, msg, COLOR_PAIR(1), pos + 1);
      else if (msg[pos] == '2')
	pos = print_color(win_msg, msg, COLOR_PAIR(2), pos + 1);
      else if (msg[pos] == '3')
	pos = print_color(win_msg, msg, COLOR_PAIR(3), pos + 1);
    }
  vwprintw(win_msg, msg + pos, ap);
  va_end(ap);
  getmaxyx(stdscr, y, x);
  wmove(stdscr, y, 0);
  wrefresh(win_msg);
  refresh();
}
