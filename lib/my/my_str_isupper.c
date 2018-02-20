/*
** my_str_isupper.c for my_str_isupper in /home/the.psychopath/delivery/CPool_Day06
** 
** Made by Alexandre Di.rosa
** Login   <the.psychopath@epitech.net>
** 
** Started on  Tue Oct 11 12:40:55 2016 Alexandre Di.rosa
** Last update Tue Oct 11 12:43:49 2016 Alexandre Di.rosa
*/

int     my_str_isupper(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
	{
	  i = i + 1;
	}
      else
	return (0);
    }
  return (1);
}
