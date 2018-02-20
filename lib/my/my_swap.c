/*
** my_swap.c for my_swap in /home/the.psychopath/delivery/CPool_Day04
** 
** Made by Alexandre Di.rosa
** Login   <the.psychopath@epitech.net>
** 
** Started on  Thu Oct  6 20:35:40 2016 Alexandre Di.rosa
** Last update Fri Oct  7 13:35:55 2016 Alexandre Di.rosa
*/

int my_swap(int *a, int *b)
{
  int c;

  c = *a;
  *a = *b;
  *b = c;

  return (0);
}
