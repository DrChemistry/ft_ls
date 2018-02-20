/*
** my_str_isnum.c for my_str_isnum in /home/the.psychopath/delivery/CPool_Day06
** 
** Made by Alexandre Di.rosa
** Login   <the.psychopath@epitech.net>
** 
** Started on  Tue Oct 11 12:31:15 2016 Alexandre Di.rosa
** Last update Tue Oct 11 12:32:14 2016 Alexandre Di.rosa
*/

int     my_str_isnum(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
	i = i + 1;
      else
	return (0);
    }
  return (1);
}
