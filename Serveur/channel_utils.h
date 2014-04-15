/*
** channel_utils.h for channel_utils in /home/marcha_j//test/c/irc/proj
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Sun Apr  3 22:44:35 2005 hugo marchadier
** Last update Wed Apr  6 11:17:04 2005 hugo marchadier
*/

#ifndef CHANNEL_UTILS_H_
# define CHANNEL_SERVEUR_H_

int		find_one_channel(t_channel **channel, char *name);
eBool		check_if_copy(t_channel *channel);
int		find_size_tab_channel(t_channel **channel);
int		channel_verif(t_msg **msg, char **name, int id, int size);
t_channel	*cpy_channel(t_channel *channel, char *name,
			     eBool init, int id);

# endif /* CHANNEL_SERVEUR_H_ */
