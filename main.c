/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:13:57 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/05/29 12:14:00 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include "ft_ls.h"

void aff_list(struct s_data *data, char *flags)
{
  while (data->next)
  {
    printf("(%s) ", data->name);
    data = data->next;
  }
}

int print_files(char **files, char *flags)
{
  int x;

  x = 0;
  while (files[x])
    printf("files:%s\n", files[x++]);
  return (SUCCESS);
}

char *get_path_file(char *name, char *repo, char *d_name)
{
  char *file;

  if (name[ft_strlen(name) - 1] != '/')
  {
    if (!(file = ft_strjoin(ft_strjoin(name,repo), d_name)))
      return (NULL);
  }
  else
    if (!(file = ft_strjoin(name, d_name)))
      return (NULL);
  return (file);
}

int fill(struct s_data *data, char *file, char *file_dirent)
{
  struct passwd *owneruid;
  struct group  *grpuid;
  struct stat   file_stat;

  if (stat(file, &file_stat) == FAILURE)
    return (FAILURE);
  data->nb_links = file_stat.st_nlink;
  data->size = file_stat.st_size;
  if (!(owneruid = getpwuid(file_stat.st_uid)))
    return (FAILURE);
  if (!(grpuid = getgrgid(file_stat.st_gid)))
    return (FAILURE);
  data->owner = owneruid->pw_name;
  data->grp = grpuid->gr_name;
  data->time = file_stat.st_mtime;
  data->name = file_dirent;
  data->mode = file_stat.st_mode;
  return (SUCCESS);
}

int fill_data(struct s_data *data, char *name, char *flags, char *repo)
{
  DIR *dir;
  struct dirent *file_dirent;
  char *file;

  if (!(dir = opendir(name)))
    return (FAILURE);
  while ((file_dirent = readdir(dir)))
  {
    if (file_dirent->d_name[0] != '.'
        || (file_dirent->d_name[0] == '.'&& flags[ft_findchar(flags, 'a')] == 'a'))
    {
      if (!(file = get_path_file(name, repo, file_dirent->d_name)))
        return (FAILURE);
      if (fill(data, file, file_dirent->d_name) == FAILURE)
        return (FAILURE);
      if (!(data->next = malloc(sizeof(t_data))))
        return (FAILURE);
      data->next->last = data;
      data = data->next;
      free(file);
    }
  }
  return (SUCCESS);
}

int recursive_option(char *curr_dires, char *flags, struct s_data *data)
{
  char *dires[2];
  char *repo;

  dires[1] = NULL;
  repo = "/";
  while (data->next)
  {
    if (S_ISDIR(data->mode))
    {
      if (!(dires[0] = get_path_file(curr_dires, repo, data->name)))
        return (FAILURE);
      printf("dires: %s\n", dires[0]);
      if (ft_ls(dires, flags) == FAILURE)
        return (FAILURE);
      printf("awdawda\n");
    }
    data = data->next;
  }
  return (SUCCESS);
}

int ft_ls(char **dires, char *flags)
{
  int x;
  struct s_data *data;
  char *repo;

  x = 0;
  repo = "/";
  while (dires[x])
  {
    if (!(data = malloc(sizeof(t_data))))
      return (FAILURE);
    data->last = NULL;
    if (fill_data(data, dires[x], flags, repo) == FAILURE)
      return (FAILURE);
    printf("dires: %s\nlist_name: %s\n", dires[x], data->name);
    aff_list(data, flags);
    //sort_list();
    //print_list();
    //if (flags[ft_findchar(flags, 'R')] == 'R')
    //  if (recursive_option(dires[x], flags, data) == FAILURE)
      //  return (FAILURE);
    ++x;
    if (dires[x])
    {
     ft_putstr("\n");
     ft_putstr(dires[x]);
    }
  }
  return (SUCCESS);
}

int separate_file(char **name, char *flags, int size)
{
  char  **dires;
  char  **files;
  int   x;
  int   c;
  int   b;

  x = 0;
  if (!(dires = malloc(sizeof(char *) * size))
      || !(files = malloc(sizeof(char *) * size)))
    return (FAILURE);
  b = 0;
  c = 0;
  while (name[x])
    if (is_dir(name[x]) == SUCCESS)
      dires[b++] = name[x++];
    else if (is_file(name[x]) == SUCCESS)
      files[c++] = name[x++];
  files[c] = NULL;
  dires[b] = NULL;
  x = 0;
  while (files[x])
   printf("files: %s\n", files[x++]);
  x = 0;
  while (dires[x])
    printf("dires: %s\n", dires[x++]);
  if (print_files(files, flags) == FAILURE || ft_ls(dires, flags) == FAILURE)
    return (FAILURE);
  return (SUCCESS);
}

int main(int ac, char **av)
{
  int   x;
  int   b;
  char  flags[6];
  char  **files;

  x = 1;
  if ((x = flags_gestion(flags, av, x)) == FAILURE)
    return (FAILURE);
  b = 0;
  if (!(files = malloc(sizeof(char *) * ac)))
    return (FAILURE);
  while (av[x])
  {
    if (is_dir(av[x]) == SUCCESS || is_file(av[x]) == SUCCESS)
      files[b++] = av[x++];
    else
    {
      ft_putstr("ls: ");
      ft_putstr(av[x++]);
      ft_putstr(": No such file or directory\n");
    }
  }
  if (b == 0)
    files[b++] = "./";
  files[b] = NULL;
  //b = 0;
  //while (files[b])
    //printf("%s\n", files[b++]);
  return (separate_file(files, flags, b));
}
