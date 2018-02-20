/*
** names_sorter.c for names_sorter in /home/the.psychopath/delivery/PSU_2016_my_ls
** 
** Made by Alexandre Di.rosa
** Login   <the.psychopath@epitech.net>
** 
** Started on  Wed Nov 30 20:51:21 2016 Alexandre Di.rosa
** Last update Sun Dec  4 22:55:17 2016 Alexandre Di.rosa
*/

#include "my.h"
#include "my_ls.h"

void    alpha_sorter(char **names)
{
  int           a;
  char          *pos;

  a = 0;
  while (names[a + 1])
    {
      if (my_strcmp(names[a], names[a + 1]) > 0)
	{
	  pos = names[a];
	  names[a] = names[a + 1];
	  names[a + 1] = pos;
	  a = 0;
	}
      else
	++a;
    }
}

void            time_sort(char **names)
{
  struct stat           read;
  int                   x;
  char                  *p;
  unsigned long int     y;
  unsigned long int     b;

  x = 1;
  while (names[x + 1])
    {
      stat(names[x], &read);
      y = read.st_mtime;
      stat(names[x + 1], &read);
      b = read.st_mtime;
      if (y < b)
	{
	  p = names[x];
	  names[x] = names[x + 1];
	  names[x + 1] = p;
	  x = 1;
	}
      else
	++x;
    }
}

void    reverse_names(char **names)
{
  int   x;
  int   b;
  char  *p;
  int   c;

  x = 1;
  b = 0;
  while (names[b])
    ++b;
  --b;
  while (x < b)
    {
      p = names[x];
      names[x] = names[b];
      names[b] = p;
      ++x;
      --b;
    }
}

void    sort_the_flags(char *flags, char **names)
{
  int   x;

  x = 0;
  while (flags[x] != '\0' && flags[x] != 't')
    ++x;
  if (flags[x] == 't')
    time_sort(names);
  x = 0;
  while (flags[x] != '\0' && flags[x] != 'r')
    ++x;
  if (flags[x] == 'r')
    reverse_names(names);
}
