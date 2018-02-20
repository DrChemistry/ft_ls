/*
** my_ls.h for my_ls in /home/the.psychopath/delivery/PSU_2016_my_ls
** 
** Made by Alexandre Di.rosa
** Login   <the.psychopath@epitech.net>
** 
** Started on  Thu Dec  1 21:24:30 2016 Alexandre Di.rosa
** Last update Sun Dec  4 22:55:29 2016 Alexandre Di.rosa
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include <string.h>

void	get_the_flags(int ac, char **av, char *flags);
void	get_the_names(int ac, char **av, char **names);
void	aff_tab_str(char **names);
void	alpha_sorter(char **names);
void	ls_long_format(char **names);
int	long_format(char **names, char *flags);
void	aff_format(unsigned int i);
void	put_in_str(unsigned int y);
void	put_names(char **names);
void	proprio_right(char *name);
void	aff_time(char *time);
void	aff_uid(char *owner_name, char *grp_name);
void	time_sort(char **names);
void	sort_the_flags(char *flags, char **names);
void	reverse_names(char **names);
void	write_names(char *, char *, char *);
void	aff_name(char *, char *);
void	my_ls(int, char **);
void	recursive_flag(char *, char **);
char	*my_decapitalize(char *);
