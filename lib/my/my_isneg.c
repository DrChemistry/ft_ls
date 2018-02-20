/*
** my_isneg.c for my_isneg in /home/the.psychopath/delivery/CPool_Day03
** 
** Made by Alexandre Di.rosa
** Login   <the.psychopath@epitech.net>
** 
** Started on  Wed Oct  5 13:57:02 2016 Alexandre Di.rosa
** Last update Sun Dec  4 19:30:50 2016 Alexandre Di.rosa
*/

void	my_putchar(char c);

int	my_isneg(int n)
{
  int	negative;
  int	positive;

  negative = 78;
  positive = 80;
  if (n < 0)
    {
      my_putchar(negative);
    }
  else
    {
      my_putchar(positive);
    }
  return (0);
}
