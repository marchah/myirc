/*
** xlib.h for xlib in /home/marcha_j//test/c/ftp/tp
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Mon Apr  2 15:36:36 2012 hugo marchadier
** Last update Wed Apr 18 17:17:35 2012 hugo marchadier
*/

#ifndef	XFCT_H_
# define XFCT_H_

#include	<sys/select.h>

struct protoent	*xgetprotobyname(char *protocole);
int		xsocket(int domain, int type, int protocole);
int		xselect(int n, fd_set *readfds, fd_set *writefds);
char		*str_to_upper(char *str);

# endif /* XFCT_H_ */
