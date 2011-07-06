#include	<stdlib.h>
#include	"visu_func.h"
#include	"client_zappy.h"

int		visu_sbp(t_fds *pooler, t_cmd *cmd, t_visu *visu)
{
  (void)pooler;
  (void)visu;
  (void)cmd;
  printf("Wrong parameter for the command\n");
  return (1);
}
