/*
** my_ls.c for my_ls in /home/the.psychopath/delivery/PSU_2016_my_ls
** 
** Made by Alexandre Di.rosa
** Login   <the.psychopath@epitech.net>
** 
** Started on  Wed Nov 30 20:48:54 2016 Alexandre Di.rosa
** Last update Sun Dec  4 23:04:18 2016 Alexandre Di.rosa
*/

#include "my.h"
#include "my_ls.h"

int		main(int ac, char **av)
{
  my_ls(ac, av);
  return (0);
}

void	my_ls(int ac, char **av)
{
  char		**names;
  char		*flags;
  int		x;

  names = malloc(sizeof(char) * 10000);
  flags = malloc(sizeof(char) * 10000);
  names[0] = malloc(sizeof(char) * 10);
  get_the_flags(ac, av, flags);
  get_the_names(ac, av, names);
  alpha_sorter(names);
  sort_the_flags(flags, names);
  x = long_format(names, flags);
  if (x == 0)
    aff_tab_str(names);
  x = 0;
  while (flags[x])
    {
      if (flags[x] == 'R')
	recursive_flag(flags, names);
      ++x;
    }
}

void	aff_tab_str(char **names)
{
  int	x;

  x = 1;
  while (names[x])
    {
      aff_name(names[0], names[x]);
      ++x;
    }
}
