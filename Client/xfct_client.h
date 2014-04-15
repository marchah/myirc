/*
** xfct_client.h for xfct_client in /home/marcha_j//test/c/ftp/tp/Client
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Mon Apr  2 16:16:25 2012 hugo marchadier
** Last update Tue Apr  5 23:03:18 2005 hugo marchadier
*/

#ifndef XFCT_CLIENT_H_
# define XFCT_CLIENT_H_

void	xconnect(int port, in_addr_t machine);
char	*xread(int fd_in, t_msg **msg);

# endif /* XFCT_CLIENT_H_ */
