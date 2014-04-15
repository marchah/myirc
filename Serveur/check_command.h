/*
** check_command.h for check_command in /home/marcha_j//test/c/irc/proj
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Sun Apr  3 22:02:22 2005 hugo marchadier
** Last update Wed Apr  6 11:04:40 2005 hugo marchadier
*/

#ifndef CHECK_COMMAND_H_
# define CHECK_COMMAND_H_

typedef struct s_tab_server
{
  char          *str;
  void		(*fct)(t_msg***, t_channel***, char **, int);
}		t_tab_server;

void		check_command(char *buffer, t_msg ***msg,
			      t_channel ***channel, int id);

# endif /* CHECK_COMMAND_H_ */
