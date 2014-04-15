/*
** xfct_serveur.h for xfct_serveur in /home/marcha_j//test/c/ftp/tp
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Mon Apr  2 15:40:30 2012 hugo marchadier
** Last update Mon Apr 16 17:25:47 2012 hugo marchadier
*/

#ifndef XFCT_SERVEUR_H_
# define XFCT_SERVEUR_H_

void	xbind(int sockfd, int port);
void	xlisten(int sockfd);
int	xaccept(int sockfd);

# endif /* XFCT_SERVEUR_H_ */
