/*
** fct_msg_client.h for fct_msg_client in /home/marcha_j//test/c/irc/proj
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Sat Apr  2 23:16:39 2005 hugo marchadier
** Last update Tue Apr 17 18:04:54 2012 hugo marchadier
*/

#ifndef	FCT_MSG_CLIENT_H_
# define FCT_MSG_CLIENT_H_

t_msg	**send_msg(t_msg **msg, int id, char *fct, char *str);
t_msg	*init_msg_client(int fd);
t_msg	**add_msg_client(t_msg **msg, int fd);

# endif /* FCT_MSG_CLIENT_H_ */
