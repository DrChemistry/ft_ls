/*
** recursive.c for recursive in /home/the.psychopath/delivery/PSU_2016_my_ls
** 
** Made by Alexandre Di.rosa
** Login   <the.psychopath@epitech.net>
** 
** Started on  Sun Dec  4 22:59:33 2016 Alexandre Di.rosa
** Last update Sun Dec  4 23:00:13 2016 Alexandre Di.rosa
*/

#include "my.h"
#include "my_ls.h"

void    recur2(char *name, char **names, char *flags)
{

}

void            recursive_flag(char *flags, char **names)
{
  int           x;
  struct stat   read;

  x = 1;
  while (names[x])
    {
      stat(names[x], &read);
      if (S_ISDIR(read.st_mode))
	{
	  my_putchar('\n');
	  my_putstr(names[x]);
	  my_putstr(":\n");
	  recur2(names[x], names, flags);
	}
      ++x;
    }
}
