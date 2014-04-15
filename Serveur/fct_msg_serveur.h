/*
** fct_msg_serveur.h for fct_msg_serveur in /home/marcha_j//test/c/irc/proj
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Sat Apr  2 20:18:40 2005 hugo marchadier
** Last update Thu Apr 19 17:47:34 2012 hugo marchadier
*/

#ifndef FCT_MSG_SERVEUR_H_
# define FCT_MSG_SERVEUR_H_

t_msg	*init_msg_serveur(int fd);
t_msg	**add_msg_serveur(t_msg **msg, int fd);
t_msg	**delete_msg_serveur(t_msg **msg, int pos);
void	user_quit(t_msg ***msg, t_channel ***channel, char **name, int id);
# endif /* FCT_MSG_SERVEUR_H_ */
