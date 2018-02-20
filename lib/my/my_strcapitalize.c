/*
** my_strcapitalize.c for my_strcapitalize in /home/the.psychopath/delivery/CPool_Day06
** 
** Made by Alexandre Di.rosa
** Login   <the.psychopath@epitech.net>
** 
** Started on  Tue Oct 11 09:02:18 2016 Alexandre Di.rosa
** Last update Tue Oct 11 14:05:59 2016 Alexandre Di.rosa
*/

char    *my_strlowcase(char *str)
{
  int   i;

  i = 0;
  while(str[i] != '\0')
    {
      while (str[i] != '\0' && str[i] > 64 && str[i] < 91)
	{
	  str[i] = str[i] + 32;
	  i = i + 1;
	}
      i= i + 1;
    }
  return (str);
}

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  str = my_strlowcase(str);
  while (str[i] != '\0')
    {
      if (str[0] > 96 && str[0] < 123)
	{
	  str [0] = str[0] - 32;
	  i = i + 1;
	}
      else if (str[i] == 32 || str[i] == 43 || str[i] == 45)
	{
	  i = i + 1;
	  if (str[i] > 96 && str[i] < 123)
	    str[i] = str[i] - 32;
	}
      i = i + 1;
    }
}
