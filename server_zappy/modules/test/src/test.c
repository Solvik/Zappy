/*
** test.c for  in /home/di-mar_j/git/Zappy/server_zappy
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Wed Jun 29 18:41:39 2011 julien di-marco
** Last update Wed Jun 29 18:41:39 2011 julien di-marco
*/

#include	<stdio.h>
#include	<string.h>
#include	<strings.h>
#include	<stdlib.h>

#include	"napi.h"

bool		test(fds client, char *cmd);
bool		call(fds client, char *cmd);

t_module	*get_module(void)
{
  t_module	*module;

  if (!(module = malloc(sizeof(*module) + sizeof(t_mod_func) * 5)))
    return (NULL);
  bzero(module, sizeof(*module) + sizeof(t_mod_func) * 5);
  module->name = strdup("test");
  module->delim = strdup("\r\n");
  module->port = -1;
  module->antiflood = 10;
  module->clients = NULL;
  add_command(module->functions, "test", test);
  add_command(module->functions, "callback", call);
  return (module);
}

bool		test(fds client, char *cmd)
{
  if (!scheduler_active(client))
    return (scheduler_relative(client, 4.2,
				 (bool (*)(fds, void*))test, strdup(cmd)));
  (void)client;
  printf("WORKING : [%s]\n", cmd);
  return (true);
}

bool		callback__(fds c, char *cmd, void *data)
{
  printf("Callback - (%d): [%s] - {%p}\n", callback_active(c), cmd, data);
  return ((cmd && strcmp(cmd, "1") == 0) ? true : false);
}

bool		call_s(fds c, char *cmd, void *data)
{
  printf("Callback set - (%d): [%s] - {%p}\n", callback_active(c), cmd, data);
  return ((cmd && strcmp(cmd, "1") == 0) ? true : false);
}

bool		call_o(fds c, char *cmd, void *data)
{
  printf("Callback overide - (%d): [%s] - {%p}\n", callback_active(c), cmd, data);
  return ((cmd && strcmp(cmd, "1") == 0) ? true : false);
}

bool		call(fds client, char *cmd)
{
  printf("Setting callback - Please enter your password. [%d]\n", callback_active(client));
  callback_set(client, callback__, (void*)0x42);
  if (cmd && strcmp(cmd, "callback set") == 0)
    printf("try setting callback: %d\n", callback_set(client, call_s, (void*)0x41));
  if (strcmp(cmd, "callback overide") == 0)
    printf("try overide callback: %d\n", callback_overide(client, call_o, (void*)0x1337));
  return (true);
}

bool		handshaking(fds client, char *cmd)
{
  if (!client->anounce)
    sends(client, "BIENVENU");
  if (cmd && (strcmp(cmd, "hello") == 0))
    return (true);
  return (false);
}

#if	defined(NOTSHARED)
__attribute__ ((constructor))
void	init_(void)
{
  t_module	*info;

  printf("Should really work !\n");
  if ((info = get_module()))
    {
      info->handshaking = handshaking;
      mod_register(info);
    }
}
#endif

bool		update(double tdt)
{
  printf("Supra delta time is: %f\n", tdt);
  return (true);
}

double		timer(void)
{
  return (1.42);
}
