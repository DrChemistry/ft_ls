/*
** my_strcmp.c for my_strcmp in /home/the.psychopath/delivery/CPool_Day06
** 
** Made by Alexandre Di.rosa
** Login   <the.psychopath@epitech.net>
** 
** Started on  Mon Oct 10 21:13:45 2016 Alexandre Di.rosa
** Last update Tue Oct 11 13:21:24 2016 Alexandre Di.rosa
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	a;

  i = 0;
  while (s1[i] == s2[i])
    {
      i = i + 1;
      if (s1[i] == '\0' && s2[i] == '\0')
	return (0);
    }
  if (s1[i] > s2[i] || s1[i] < s2[i])
    {
      a = s1[i] - s2[i];
      return (a);
    }
}
