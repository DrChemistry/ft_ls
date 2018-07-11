/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:58:06 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/03/12 11:58:07 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include "ft_ls.h"
#include "./libft/libft.h"

int main(int ac, char **av)
{
  char  flags[6];
  char  directories[ac][1];
  int   x;

  if (ac > 1 && ((x = flags_gestion(flags, av, x)) == FAILURE))
    return (ERROR);
  while (ac > 1 && av[x])
  {
    if (is_directory(av[x]) == SUCCESS)
      ft_ls(av[x], flags);
    else
     return (ft_puterror("No such file or directory\n", ERROR));
    ++x;
  }
  return (SUCCESS);
}

void short_format(struct s_data *data, int rev)
{
  while (data)
  {
    ft_putstr(data->name);
    if (rev == -1 && data->last)
      ft_putchar(' ');
    else if (rev == 1 && data->next)
      ft_putchar(' ');
    data = rev == -1 ? data->last : data->next;
  }
  ft_putchar('\n');
}

struct s_sizes *get_all_the_sizes(struct s_data *data)
{
  struct s_sizes *length;

  if (!(length = malloc(sizeof(t_sizes))))
    return (NULL);
  length->size = 0;
  length->links = 0;
  length->char_owner = 0;
  length->char_grp = 0;
  data = ft_rewind(data, 1);
  while (data->next)
  {
    if (ft_strlen(data->owner) > length->char_owner)
     length->char_owner = ft_strlen(data->owner);
    if (ft_strlen(data->grp) > length->char_grp)
      length->char_grp = ft_strlen(data->grp);
    if (ft_strlen(ft_itoa(data->size)) > length->size)
      length->size = ft_strlen(ft_itoa(data->size));
    if (ft_strlen(ft_itoa(data->nb_links)) > length->links)
      length->links = ft_strlen(ft_itoa(data->nb_links));
    data = data->next;
  }
  return (length);
}

void aff_time(char *str)
{
  int x;
  int tmp;

  x = 0;
  tmp = 0;
  while (str[x] && str[x] != ' ')
   ++x;
  while (str[x] && tmp < 2)
  {
    ft_putchar(str[x++]);
    if (str[x] == ':')
      ++tmp;
  }
}

void long_format(struct s_data *data, int rev, t_sizes *sizes, char *flags)
{
  int tmp;

  data = ft_rewind(data, rev);
  while ((rev == 1 && data->next) || (rev == 0 && data->last))
  {
    if (S_ISDIR(data->mode))
      ft_putchar('d');
    else
      ft_putchar('-');
    ft_putchar((data->mode & S_IRUSR) ? ('r') : ('-'));
    ft_putchar((data->mode & S_IWUSR) ? ('w') : ('-'));
    ft_putchar((data->mode & S_IXUSR) ? ('x') : ('-'));
    ft_putchar((data->mode & S_IRGRP) ? ('r') : ('-'));
    ft_putchar((data->mode & S_IWGRP) ? ('w') : ('-'));
    ft_putchar((data->mode & S_IXGRP) ? ('x') : ('-'));
    ft_putchar((data->mode & S_IROTH) ? ('r') : ('-'));
    ft_putchar((data->mode & S_IWOTH) ? ('w') : ('-'));
    ft_putchar((data->mode & S_IXOTH) ? ('x') : ('-'));
    ft_putstr("  ");
    tmp = sizes->links - ft_strlen(ft_itoa(data->nb_links));
    while (tmp-- > 0)
    ft_putchar(' ');
    ft_putnbr(data->nb_links);
    ft_putchar(' ');
    ft_putstr(data->owner);
    tmp = sizes->char_owner - ft_strlen(data->owner);
    while (tmp-- > 0)
      ft_putchar(' ');
    ft_putstr("  ");
    ft_putstr(data->grp);
    tmp = sizes->char_grp - ft_strlen(data->grp);
    while (tmp-- > 0)
      ft_putchar(' ');
    ft_putstr("  ");
    tmp = sizes->size - ft_strlen(ft_itoa(data->size));
    while (tmp-- > 0)
      ft_putchar(' ');
    ft_putnbr(data->size);
    ft_putchar(' ');
    aff_time(ctime(&(data->time)));
    ft_putchar(' ');
    ft_putstr(data->name);
    data = rev == -1 ? data->last : data->next;
    ft_putchar('\n');
  }
}

void aff_list(struct s_data *data, char *flags)
{
  int             rev;
  int             format;
  struct s_sizes  *sizes;

  rev = 1;
  if (flags[ft_findchar(flags, 'r')] == 'r')
    rev = -1;
  data = ft_rewind(data, rev);
  format = flags[ft_findchar(flags, 'l')] == 'l' ? 1 : 0;
  if (!(sizes = get_all_the_sizes(data)))
    return ;
  data = ft_rewind(data, rev);
  if (format == 1)
    long_format(data, rev, sizes, flags);
  else
    short_format(data, rev);
}

int fill(struct s_data *data, struct stat stat_file, struct dirent *file)
{
  struct passwd *owneruid;
  struct group  *grpuid;

  data->nb_links = stat_file.st_nlink;
  data->size = stat_file.st_size;
  if (!(owneruid = getpwuid(stat_file.st_uid)))
    return (FAILURE);
  if (!(grpuid = getgrgid(stat_file.st_gid)))
    return (FAILURE);
  data->owner = owneruid->pw_name;
  data->grp = grpuid->gr_name;
  data->time = stat_file.st_mtime;
  data->name = file->d_name;
  data->mode = stat_file.st_mode;
  return (SUCCESS);
}

int ft_ls(char *name, char *flags)
{
  DIR           *dir;
  struct dirent *file;
  struct s_data *data;
  struct stat   stat_file;
  char          *tmp;

  if (!(dir = opendir(name)) || !(data = malloc(sizeof(t_data) * 1)))
   return (FAILURE);
  data->last = NULL;
  while ((file = readdir(dir)))
  {
      if (!(tmp = ft_strjoin(name, file->d_name)))
        return (ERROR);
      if ((stat(tmp, &stat_file)) == FAILURE)
        return (ft_puterror("STAT FAILURE\n", ERROR));
      if (fill(data, stat_file, file) == FAILURE)
        return (FAILURE);
      if (!(data->next = malloc(sizeof(t_data) * 1)))
        return (FAILURE);
      free(tmp);
      data->next->last = data;
      data = data->next;
  }
  data = data->last;
  free(data->next);
  data->next = NULL;
  parse_sort(flags, data);
  aff_list(data, flags);
  return (0);
}
