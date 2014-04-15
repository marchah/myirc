/*
** exec_command.h for  in /home/l-huil_o//test/my_irc
** 
** Made by olivier l-huillier
** Login   <l-huil_o@epitech.net>
** 
** Started on  Tue Apr 17 16:34:25 2012 olivier l-huillier
** Last update Fri Apr 20 16:22:38 2012 hugo marchadier
*/

#ifndef EXEC_COMMAND_H_
#define EXEC_COMMAND_H_

typedef struct s_cmd_tab
{
  char		*str;
  t_msg		**(*fct)(char**, t_msg**, void*);
}		t_cmd_tab;

t_msg		**exec_command(char *cmd, t_msg **msg, void *win_msg);

#endif
