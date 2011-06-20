/*
** graph_map.c for  in /home/seb/git/Zappy/server_zappy/src
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Mon Jun 13 18:51:14 2011 seb
** Last update Mon Jun 13 18:51:14 2011 seb
*/

#include "graph_map.h"

void handle_msz(t_fds *player)
{
  (void)player;
  /*
    On envoie msz X Y\n au client graphique
   */
}

void handle_bct(t_fds *player)
{
  (void)player;
  /*
    On envoie bct X Y q q q q q q q avec q le nombre de ressources
    (voir sujet pour l'ordre)
  */
}

void handle_mct(t_fds *player)
{
  (void)player;
  /*
    On envoie le contenu de toute les cases de la map
    => appeler handle_case_content pour toutes les cases
   */
}
