/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 13:39:24 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/04/10 13:39:25 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_LS_H
# define	FT_LS_H

# include "./libft/libft.h"

# define FAILURE -1
# define SUCCESS 0

typedef struct  s_data
{
          int           nb_links;
          char          *owner;
          char          *grp;
          int           size;
          long          time;
          char          *name;
          int           mode;
          struct s_data *last;
          struct s_data *next;
}               t_data;

int   flags_gestion(char *flags, char **av, int x);
int   get_dir(char **name, char *flags);
int   get_file(char **files, char *flags);
int   fill(struct s_data *data, char *file, char *file_dirent);
int   is_file(char *name);
int   is_dir(char *name);
void  aff_list(struct s_data *data, char *flags);
int   ft_ls(char **dires, char *flags);
char *get_path_file(char *name, char *repo, char *d_name);
int fill_data(struct s_data *data, char *name, char *flags, char *repo);
int print_files(char **files, char *flags);

#endif
