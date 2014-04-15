/*
** channel_bonus.h for channel_bonus in /home/marcha_j//svn_rendu/c/myirc-2015-2014s-marcha_j/Serveur
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Wed Apr  6 11:27:27 2005 hugo marchadier
** Last update Wed Apr  6 11:44:00 2005 hugo marchadier
*/

#ifndef CHANNEL_BONUS_H_
# define CHANNEL_BONUS_H_

void	list_channels(t_msg ***msg, t_channel ***channel,
		      char **name, int id);
void	follow_channel(t_msg ***msg, t_channel ***channel,
		       char **name, int id);

# endif /* CHANNEL_BONUS_H_ */
