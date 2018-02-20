/*
** my_strncmp.c for my_strncmp in /home/the.psychopath/delivery/CPool_Day06
** 
** Made by Alexandre Di.rosa
** Login   <the.psychopath@epitech.net>
** 
** Started on  Mon Oct 10 21:41:02 2016 Alexandre Di.rosa
** Last update Wed Oct 12 20:50:41 2016 Alexandre Di.rosa
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int   i;
  int   a;

  i = 0;
  while (s1[i] == s2[i] && n != 0)
    {
      i = i + 1;
      n = n - 1;
      if (s1[i] == '\0' && s2[i] == '\0')
	return (0);
    }
  if (s1[i] > s2[i] || s1[i] < s2[i])
    {
      a = s1[i] - s2[i];
      return (a);
    }
}
