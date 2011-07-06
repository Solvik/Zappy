
#include	<stdlib.h>
#include	"visu_func.h"
#include	"client_zappy.h"

int		visu_smg(t_fds *pooler, t_visu *visu, t_cmd *cmd)
{
  (void)pooler;
  (void)visu;
  printf("Message from the server: %s\n", cmd->argv[1]);
  return (1);
}
