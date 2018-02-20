/*
** my_strlowcase.c for my_strlowcase in /home/the.psychopath/delivery/CPool_Day06
** 
** Made by Alexandre Di.rosa
** Login   <the.psychopath@epitech.net>
** 
** Started on  Tue Oct 11 08:25:03 2016 Alexandre Di.rosa
** Last update Tue Oct 11 13:36:40 2016 Alexandre Di.rosa
*/

char    *my_strlowcase(char *str)
{
  int   i;

  i = 0;
  while(str[i] != '\0')
    {
      while (str[i] != '\0' && str[i] > 64 && str[i] < 91)
	{
	  str[i] = str[i] + 32;
	  i = i + 1;
	}
      i= i + 1;
    }
  return (str);
}
