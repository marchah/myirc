/*
** client.h for client in /home/marcha_j//test/c/irc/proj/Client
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Mon Apr 16 18:19:49 2012 hugo marchadier
** Last update Fri Apr 20 17:11:51 2012 olivier l-huillier
*/

#ifndef	CLIENT_H_
# define CLIENT_H_

void		client_read(int fd_in, int fd_out, t_msg ***msg);
void		client_write(int fd, t_msg ***msg, void *win_msg);
void		init_client(int port, char *ip);
void		close_client();

extern int	g_client;

# endif /* CLIENT_H_ */
