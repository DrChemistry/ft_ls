/*
** m_strstr.c for my_strstr in /home/the.psychopath/delivery/CPool_Day06
** 
** Made by Alexandre Di.rosa
** Login   <the.psychopath@epitech.net>
** 
** Started on  Mon Oct 10 20:13:44 2016 Alexandre Di.rosa
** Last update Tue Oct 11 16:23:12 2016 Alexandre Di.rosa
*/
#include<stdlib.h>

int	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	n;

  i = 0;
  while (str[i] != '\0')
    {
      n = 0;
      while (str[i] == to_find[n])
	{
	  n = n + 1;
	  i = i + 1;
	  if (to_find[n] == '\0')
	    {
	      i = i - n;
	      return (&str[i]);
	    }
	}
      i = i - n;
      if (to_find[n] == '\0')
	  return (&str[i]);
      i = i + 1;
    }
  return (NULL);
}
