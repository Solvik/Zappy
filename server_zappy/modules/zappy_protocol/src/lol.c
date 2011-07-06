static void	send_broadcast(int x1, int y1, int x2, int y2)
{
  int		new_x;
  int		new_y;
  float		hyp;
  float		adj;
  float		angle;
  int tr_x = 11 / 2 - x1;
  int tr_y = 11 / 2 - y1;
  int		modif;

  new_x = (x2 + tr_x - 5) % 11;
  new_y = (y2 + tr_y - 5) % 11;
  printf("emetteur_x = %d emetteur_y = %d\n", x1, y1);
  printf("player_x = %d player_y = %d new_x = %d new_y = %d\n", x2, y2, new_x, new_y);
  printf("translation x %d translation y %d\n", tr_x, tr_y);
  hyp = sqrt(pow(-new_x ,2) + pow(-new_y, 2));
  adj = new_x;
  printf("hyp = %f adj = %f\n", hyp, adj);
  angle = acos(adj / hyp);
  angle = (angle * 180) / 3.1415;
  angle = 90 - (int)angle;
  printf("angle = %f\n", angle);
  if (0 == new_x || 0 == new_y)
    {
      if (0 == new_y && new_x < 0)
	printf("p1\n");
      if (0 == new_y && new_x > 0)
	printf("p5\n");
      if (0 == new_x && new_y > 0)
	printf("p3\n");
      if (0 == new_x && new_y < 0)
	printf("p7\n");
    }
  else
    {
      if (new_x <= 0 && new_y >= 0)
	{
	  if (angle <= -25)
	    printf("3\n");
	  else if (angle > -25 && angle <= -65)
	    printf("2\n");
	  else
	    printf("1\n");
	}
      else if (new_x <= 0 && new_y <= 0)
	{
	  if (angle >= -25)
	    printf("1\n");
	  else if (angle < -25 && angle >= -65)
	    printf("8\n");
	  else
	    printf("7\n");
	}
      else if (new_x >= 0 && new_y >= 0)
	{
	  if (angle <= 25)
	    printf("3\n");
	  else if (angle > 25 && angle <= 65)
	    printf("4\n");
	  else
	    printf("5\n");
	}
      else
	{
	  if (angle <= 25)
	    printf("7\n");
	  else if (angle > 25 && angle <= 65)
	    printf("6\n");
	  else
	    printf("5\n");
	}
    }
}


int main(int ac, char **av)
{
  if (ac != 5)
    {
      printf("NON\n");
      exit(-1);
    }
  send_broadcast(atoi(av[1]), atoi(av[2]), atoi(av[3]), atoi(av[4]));
}
