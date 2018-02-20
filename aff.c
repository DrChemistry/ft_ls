/*
** aff.c for aff in /home/the.psychopath/delivery/PSU_2016_my_ls
** 
** Made by Alexandre Di.rosa
** Login   <the.psychopath@epitech.net>
** 
** Started on  Fri Dec  2 09:44:13 2016 Alexandre Di.rosa
** Last update Sun Dec  4 22:00:27 2016 Alexandre Di.rosa
*/

#include "my.h"
#include "my_ls.h"

void            proprio_right(char *name)
{
  struct stat   read;
  int   x;

  x = 1997;
  stat(name, &read);
  my_putchar((read.st_mode & S_IRUSR) ? ('r') : ('-'));
  my_putchar((read.st_mode & S_IWUSR) ? ('w') : ('-'));
  my_putchar((read.st_mode & S_IXUSR) ? ('x') : ('-'));
  my_putchar((read.st_mode & S_IRGRP) ? ('r') : ('-'));
  my_putchar((read.st_mode & S_IWGRP) ? ('w') : ('-'));
  my_putchar((read.st_mode & S_IXGRP) ? ('x') : ('-'));
  my_putchar((read.st_mode & S_IROTH) ? ('r') : ('-'));
  my_putchar((read.st_mode & S_IWOTH) ? ('w') : ('-'));
  my_putchar((read.st_mode & S_IXOTH) ? ('x') : ('-'));
  my_putchar(' ');
}

void    aff_time(char *time)
{
  int   i;
  int   x;

  i = my_strlen(time);
  --i;
  x = 0;
  time[i] = '\0';
  i = 0;
  my_putchar('\t');
  while (time[x] != '\0')
    {
      if (time[x] == ' ')
	++i;
      if (time[x] == ':')
	i = i + 100;
      if (i >= 1 && i < 200)
	my_putchar(time[x]);
      ++x;
    }
  my_putchar(' ');
}

void    aff_uid(char *owner_name, char *grp_name)
{
  my_putchar(' ');
  my_putstr(owner_name);
  my_putchar(' ');
  my_putstr(grp_name);
}

void	aff_name(char *path, char *name)
{
  int	x;
  int	b;

  x = 0;
  b = 0;
  while (path[b] != '\0')
    {
      ++b;
      ++x;
    }
  while (name[x])
    {
      my_putchar(name[x]);
      ++x;
    }
  my_putchar('\n');
}
