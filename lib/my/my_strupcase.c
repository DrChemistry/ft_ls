/*
** my_strupcase.c for my_strupcase in /home/the.psychopath/delivery/CPool_Day06
** 
** Made by Alexandre Di.rosa
** Login   <the.psychopath@epitech.net>
** 
** Started on  Tue Oct 11 07:27:11 2016 Alexandre Di.rosa
** Last update Wed Oct 12 20:50:40 2016 Alexandre Di.rosa
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      while (str[i] != '\0' && str[i] > 96 && str[i] < 123)
	{
	  str[i] = str[i] - 32;
	  i = i + 1;
	}
      i = i + 1;
    }
  return (str);
}
