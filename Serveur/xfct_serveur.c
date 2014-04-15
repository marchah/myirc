/*
** xfct_serveur.c for xfct_serveur in /home/marcha_j//test/c/ftp/tp
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Mon Apr  2 15:39:32 2012 hugo marchadier
** Last update Sat Apr  2 22:39:55 2005 hugo marchadier
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<unistd.h>
#include		<string.h>
#include		<errno.h>

#include		<sys/types.h>
#include		<sys/socket.h>
#include		<arpa/inet.h>

#include		"defines.h"
#include		"serveur.h"

void			xbind(int sockfd, int port)
{
  struct sockaddr_in	sin;
  int			errno;

  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(sockfd, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
    {
      fprintf(stderr, "Error: bind failed, %s\n", strerror(errno));
      close(sockfd);
      exit(EXIT_FAILURE);
    }
}

void			xlisten(int sockfd)
{
  int			errno;

  errno = 0;
  if (listen(sockfd, SIZE_LISTEN) == -1)
    {
      fprintf(stderr, "Error: listen failed, %s.\n", strerror(errno));
      close(sockfd);
      exit(EXIT_FAILURE);
    }
}

int			xaccept(int sockfd)
{
  int			new_client;
  int			client_len;
  int			errno;
  struct sockaddr_in    sin_client;

  errno = 0;
  client_len = sizeof(sin_client);
  if ((new_client = accept(sockfd, (struct sockaddr *)&sin_client,
			   (socklen_t *)&client_len)) == -1)
    {
      fprintf(stderr, "Error: accept failed, %s.\n", strerror(errno));
      close_serveur();
      exit(EXIT_FAILURE);
    }
  printf("New client is connected %s\n", inet_ntoa(sin_client.sin_addr));
  return (new_client);
}
