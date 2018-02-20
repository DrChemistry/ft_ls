/*
** my_str_isprintable.c for my_str_isprintable in /home/the.psychopath/delivery/CPool_Day06
** 
** Made by Alexandre Di.rosa
** Login   <the.psychopath@epitech.net>
** 
** Started on  Tue Oct 11 13:32:47 2016 Alexandre Di.rosa
** Last update Tue Oct 11 13:32:50 2016 Alexandre Di.rosa
*/

int     my_str_isprintable(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= ' ' && str[i] <= '126')
	{
	  i = i + 1;
	}
      else
	return (0);
    }
  return (1);
}
