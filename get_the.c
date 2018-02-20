/*
** get_the.c for get_the in /home/the.psychopath/delivery/PSU_2016_my_ls
** 
** Made by Alexandre Di.rosa
** Login   <the.psychopath@epitech.net>
** 
** Started on  Wed Nov 30 20:49:23 2016 Alexandre Di.rosa
** Last update Fri Dec  2 22:30:02 2016 Alexandre Di.rosa
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include "my.h"
#include "my_ls.h"

void    get_the_flags(int ac, char **av, char *flags)
{
  int   x;
  int   b;
  int   c;

  b = 0;
  x = 0;
  while (b < ac)
    {
      if (av[b][0] == '-')
	{
	  c = 1;
	  while (av[b][c] != '\0')
	    {
	      flags[x] = av[b][c];
	      ++x;
	      ++c;
	    }
	}
      ++b;
    }
  flags[x] = '\0';
}

void            get_the_names(int ac, char **av, char **names)
{
  int           x;

  x = 1;
  names[0][0] = '\0';
  if (ac > 1)
    {
      while (x < ac)
	{
	  if (av[x][0] != '-')
	    names[0] = av[x];
	  ++x;
	}
    }
  if (names[0][0] == '\0')
    names[0] = "./\0";
  x = my_strlen(names[0]);
  put_names(names);
}

void	write_names(char *path, char *names, char *name)
{
  int	x;
  int	b;

  b = 0;
  while (path[b] != '\0')
    {
      names[b] = path[b];
      ++b;
    }
  x = b;
  b = 0;
  while (name[b])
    ++b;
  name[b] = '\0';
  b = 0;
  while (name[b] != '\0')
    {
      names[x] = name[b];
      ++b;
      ++x;
    }
}

void		put_names(char **names)
{
  int		x;
  DIR		*rep;
  struct dirent	*name;

  x = 1;
  rep = opendir(names[0]);
  while (name = readdir(rep))
    {
      if (name->d_name[0] != '.')
	{
	  names[x] = malloc(sizeof(char) * 100);
	  write_names(names[0], names[x], name->d_name);
	  ++x;
	}
    }
  names[x] = '\0';
}
