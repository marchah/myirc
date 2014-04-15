/*
** cmd_client.h for  in /home/l-huil_o//test/my_irc
** 
** Made by olivier l-huillier
** Login   <l-huil_o@epitech.net>
** 
** Started on  Tue Apr 17 16:29:00 2012 olivier l-huillier
** Last update Fri Apr 20 16:48:10 2012 olivier l-huillier
*/

#ifndef CMD_CLIENT_H_
#define CMD_CLIENT_H_

t_msg	**cmd_join(char **args, t_msg **msg, void *win_msg);
t_msg	**cmd_nick(char **args, t_msg **msg, void *win_msg);
t_msg	**cmd_part(char **args, t_msg **msg, void *win_msg);
t_msg	**cmd_users(char **args, t_msg **msg, void *win_msg);

t_msg	**cmd_msg(char **args, t_msg **msg, void *win_msg);
t_msg	**cmd_list(char **args, t_msg **msg, void *win_msg);

t_msg	**cmd_quit(char **args, t_msg **msg, void *win_msg);
t_msg	**cmd_channels(char **args, t_msg **msg, void *win_msg);
t_msg	**cmd_follow(char **args, t_msg **msg, void *win_msg);
t_msg	**cmd_msg_users_channel(char *str, t_msg **msg, void *win_msg);

# endif /* CMD_CLIENT_H_ */
