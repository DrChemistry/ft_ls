/*
** my_strcat.c for my_strcat in /home/the.psychopath/delivery/day07
** 
** Made by Alexandre Di.rosa
** Login   <the.psychopath@epitech.net>
** 
** Started on  Wed Oct 12 08:59:13 2016 Alexandre Di.rosa
** Last update Wed Oct 12 09:27:18 2016 Alexandre Di.rosa
*/

char *my_strcat(char *dest, char *src)
{
  int i;
  int n;

  i = 0;
  n = 0;
  while (dest[i] != '\0')
    {
      i = i + 1;
    }
  while (src[n] != '\0')
    {
      dest[i] = src[n];
      i = i + 1;
      n = n + 1;
    }
  return (dest);
}
