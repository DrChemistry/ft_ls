/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 09:49:57 by adi-rosa          #+#    #+#             */
/*   Updated: 2018/03/29 09:49:58 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void time_sort(struct s_data *data)
{
  struct s_data *tmp;

  while (data->next)
  {
    if (data->time < data->next->time)
    {
      tmp = data->next;
      tmp->last = data->last;
      data->next = tmp->next;
      data->last = tmp;
      tmp->next = data;
      if (data->next)
        data->next->last = data;
      if (tmp->last)
        tmp->last->next = tmp;
      while (data->last)
        data = data->last;
    }
    else
      data = data->next;
  }
}

void parse_sort(char *flags, struct s_data *data)
{
  int x;

  x = -1;
  while (flags[++x])
    if (flags[x] == 't')
      time_sort(data);
}
