/*
** decapitalize.c for decapitalize in /home/the.psychopath/delivery/PSU_2016_my_ls
** 
** Made by Alexandre Di.rosa
** Login   <the.psychopath@epitech.net>
** 
** Started on  Sun Dec  4 22:44:04 2016 Alexandre Di.rosa
** Last update Sun Dec  4 22:44:05 2016 Alexandre Di.rosa
*/

#include "my.h"
#include "my_ls.h"

char	*my_decapitalize(char *str)
{
  int	x;

  x = 0;
  while (str[x])
    {
      if (str[x] >= 'A' || str[x] <= 'Z')
	str[x] = str[x] + 32;
      ++x;
    }
  return (str);
}
