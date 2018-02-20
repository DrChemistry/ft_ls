/*
** long_format.c for long_format in /home/the.psychopath/delivery/PSU_2016_my_ls
** 
** Made by Alexandre Di.rosa
** Login   <the.psychopath@epitech.net>
** 
** Started on  Sun Dec  4 23:03:19 2016 Alexandre Di.rosa
** Last update Sun Dec  4 23:04:09 2016 Alexandre Di.rosa
*/

#include "my.h"
#include "my_ls.h"

int     long_format(char **names, char *flags)
{
  int   x;
  int   b;

  x = 0;
  while (flags[x] != '\0')
    {
      if (flags[x] == 'l')
	{
	  ls_long_format(names);
	  return (1);
	}
      ++x;
    }
  return (0);
}

void            ls_long_format(char **names)
{
  int           x;
  struct stat   read;
  struct passwd *owneruid;
  struct group  *grpuid;

  x = 1;
  while (names[x])
    {
      stat(names[x], &read);
      owneruid = getpwuid(read.st_uid);
      grpuid = getgrgid(read.st_gid);
      if (S_ISDIR(read.st_mode))
	my_putchar('d');
      else
	my_putchar('-');
      proprio_right(names[x]);
      my_put_nbr(read.st_nlink);
      aff_uid(owneruid->pw_name, grpuid->gr_name);
      my_putchar(' ');
      my_put_nbr(read.st_size);
      aff_time(ctime(&(read.st_mtime)));
      aff_name(names[0], names[x]);
      ++x;
    }
}
