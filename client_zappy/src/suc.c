#include	<stdlib.h>
#include	"visu_func.h"
#include	"client_zappy.h"

int		visu_suc(t_fds *pooler, t_visu *visu, t_cmd *cmd)
{
  (void)pooler;
  (void)visu;
  (void)cmd;
  printf("Unkown command\n");
  return (1);
}
