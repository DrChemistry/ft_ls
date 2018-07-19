/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 13:39:24 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/07/18 20:23:40 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <sys/stat.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define FAILURE -1
# define SUCCESS 0

typedef struct	s_data
{
	char			*owner;
	char			*grp;
	char			*name;
	struct stat		file_stat;
	struct s_data	*last;
	struct s_data	*next;
}				t_data;

typedef struct	s_sizes
{
	int	size;
	int	links;
	int	char_owner;
	int	char_grp;
	int	blocks;
}				t_sizes;

int				flags_gestion(char *flags, char **av, int x);
int				get_dir(char **name, char *flags);
int				get_file(char **files, char *flags);
int				fill(struct s_data *data, char *file, char *file_dirent);
int				is_file(char *name);
int				is_dir(char *name);
void			aff_list(struct s_data *data, char *flags, char *path, int b);
int				ft_ls(char **dires, char *flags, char **files);
char			*get_path_file(char *name, char *repo, char *d_name);
int				fill_data(t_data *data, char *name, char *flags, char *repo);
int				print_files(char **files, char *flags);
t_data			*parse_sort(char *flags, struct s_data *data);
void			aff_time(char *str);
void			aff_type(struct s_data *data);
void			free_data(t_data *data);

#endif
