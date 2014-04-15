/*
** graphics.h for  in /home/l-huil_o//test/my_irc/myirc-2015-2014s-marcha_j/Client
** 
** Made by olivier l-huillier
** Login   <l-huil_o@epitech.net>
** 
** Started on  Fri Apr 20 15:46:56 2012 olivier l-huillier
** Last update Fri Apr 20 17:37:52 2012 hugo marchadier
*/

#ifndef GRAPHICS_H_
# define GRAPHICS_H_

# include	<ncurses.h>

void		*init_ncurses();
void		end_ncurses(void *win_msg);
void		print_msg(void *win_msg, char *msg, ...);

#endif
