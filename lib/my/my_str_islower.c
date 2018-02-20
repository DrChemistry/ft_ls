/*
** my_str_islower.c for my_str_islower in /home/the.psychopath/delivery/CPool_Day06
** 
** Made by Alexandre Di.rosa
** Login   <the.psychopath@epitech.net>
** 
** Started on  Tue Oct 11 12:35:13 2016 Alexandre Di.rosa
** Last update Tue Oct 11 13:22:54 2016 Alexandre Di.rosa
*/

int     my_str_islower(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	{
	  i = i + 1;
	}
      else
	return (0);
    }
  return (1);
}
