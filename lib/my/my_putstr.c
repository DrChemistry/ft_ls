/*
** my_putstr.c for my_putstr in /home/the.psychopath/delivery/CPool_Day04
** 
** Made by Alexandre Di.rosa
** Login   <the.psychopath@epitech.net>
** 
** Started on  Thu Oct  6 18:49:39 2016 Alexandre Di.rosa
** Last update Fri Oct  7 13:36:07 2016 Alexandre Di.rosa
*/

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}
