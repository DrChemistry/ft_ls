/*
** my_put_nbr.c for my_put_nbr.c in /home/the.psychopath/delivery/CPool_Day03
** 
** Made by Alexandre Di.rosa
** Login   <the.psychopath@epitech.net>
** 
** Started on  Fri Oct  7 07:37:22 2016 Alexandre Di.rosa
** Last update Wed Oct 12 19:00:21 2016 Alexandre Di.rosa
*/

int my_put_nbr(int nb)
{
  if (nb == -2147483648)
    negmax();
  else
    {
      if (nb < 0)
	{
	  my_putchar('-');
	  nb = -nb;
	}
      if (nb >= 10)
	{
	  my_put_nbr(nb / 10);
	}
      my_putchar(nb % 10 + 48);
    }
}


int negmax ()
{
  my_putchar('-');
  my_putchar('2');
  my_putchar('1');
  my_putchar('4');
  my_putchar('7');
  my_putchar('4');
  my_putchar('8');
  my_putchar('3');
  my_putchar('6');
  my_putchar('4');
  my_putchar('8');
}
