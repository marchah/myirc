/*
** channel.h for channel in /home/marcha_j//test/c/irc/proj
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Tue Apr 17 15:50:30 2012 hugo marchadier
** Last update Fri Apr 20 17:07:04 2012 hugo marchadier
*/

#ifndef CHANNEL_SERVEUR_H_
# define CHANNEL_SERVEUR_H_

# define UNUSED	-1

typedef	struct	s_channel
{
  char		name[MAX_NAME];
  char		id[MAX_FD];
}		t_channel;

t_channel	**add_new_channel(t_channel **channel,
				  char *name, int id);
void		delete_all_channel(t_channel **channel);
void		join_channel(t_msg ***msg, t_channel ***channel,
			     char **name, int id);
void		part_channel_follow(t_msg ***msg, t_channel **channel,
				    char **name, int id);
void		part_channel(t_msg ***msg, t_channel ***channel,
			     char **name, int id);
t_channel	**delete_channel_unused(t_channel **channel, int pos);
void		list_users_channel(t_msg ***msg, t_channel ***channel,
				   char **name, int id);
void		channel_nickname(t_msg ***msg, t_channel ***channel,
				 char **name, int id);
void		private_msg_channel(t_msg ***msg, t_channel ***channel,
				    char **name, int id);
void		list(t_msg ***msg, t_channel ***channel, char **name, int id);

void		channel_msg_all_users(t_msg ***msg, t_channel ***channel,
				      char *str, int id);

#endif /* CHANNEL_SERVEUR_H_ */
