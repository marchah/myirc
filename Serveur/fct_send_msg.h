/*
** fct_send_msg.h for fct_send_msg in /home/marcha_j//svn_rendu/c/myirc-2015-2014s-marcha_j/Serveur
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Wed Apr  6 11:20:45 2005 hugo marchadier
** Last update Wed Apr  6 12:49:41 2005 hugo marchadier
*/

#ifndef FCT_SEND_MSG_SERVER_H_
# define FCT_SEND_MSG_SERVER_H_

# define CONNECT	"You connect to the channel."
# define NOT		"You not connect to a channel."
# define ALREADY	"You already connect to this channel."
# define UNKNOW		"Unknow user."

# define QUIT_C		"You quit the channel."
# define NOT_C		"Error: You not in a channel"
# define NOT_THIS_C	"Error: You not in this channel."

# define CHANGE_N	"You change your nickname."
# define ALREADY_N	"Error: this nickname is already used."

char	*add_msg(char *buffer, char *str, char sep);
char	*send_channel(char *str, char *name_channel, char sep);
char	*send_user(char *str, char *nick, char sep, eBool flag);
char	*send_serveur(char *str, char *msg, char sep);
void	send_all_users(t_msg ***msg, t_channel *channel, int id, char *str);

# endif /* FCT_SEND_MSG_SERVER_H_ */
