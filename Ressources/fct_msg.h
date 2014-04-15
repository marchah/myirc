/*
** fct_msg.h for fct_msg in /home/marcha_j//test/c/irc/proj
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Sat Apr  2 20:22:34 2005 hugo marchadier
** Last update Tue Apr 17 18:04:44 2012 hugo marchadier
*/

#ifndef	FCT_MSG_H_
# define FCT_MSG_H_

int	msg_len(t_msg **msg);
int	find_id_msg(int fd, t_msg **msg);
void	cp_msg(t_msg *src, t_msg *dest);
void	delete_msg(t_msg **msg);

# endif /* FCT_MSG_H_ */
