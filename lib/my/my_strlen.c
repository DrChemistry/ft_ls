/*
** my_strlen.c for my_strlen in /home/the.psychopath/delivery/CPool_Day04
** 
** Made by Alexandre Di.rosa
** Login   <the.psychopath@epitech.net>
** 
** Started on  Thu Oct  6 22:06:05 2016 Alexandre Di.rosa
** Last update Sat Oct 15 10:47:08 2016 Alexandre Di.rosa
*/

int	my_strlen(char *str)
{
  int	n;

  n = 0;
  while (str[n] != '\0')
  {
    n = n + 1;
  }
  return (n);
}
