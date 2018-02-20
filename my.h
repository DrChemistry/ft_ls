/*
** my.h for my in /home/the.psychopath/delivery/CPool_Day09/include
** 
** Made by Alexandre Di.rosa
** Login   <the.psychopath@epitech.net>
** 
** Started on  Fri Oct 14 10:12:44 2016 Alexandre Di.rosa
** Last update Tue Oct 25 08:41:20 2016 Alexandre Di.rosa
*/

int	my_swap(int *a, int *b);
char	*strupcase(char *str);
int	my_strncpy(char *dest, char *src, int n);
char	*my_strncat(char *dest, char *src, int nb);
int	my_strlen(char *str);
int	my_str_isprintable(char *str);
int	my_str_islower(char *str);
char	*my_strcpy(char *dest, char *src);
char	*my_strcat(char *dest, char *src);
int	my_square_root(int nb);
int	my_showstr(char *str);
char	my_revstr(char *str);
int	my_put_nbr(int nb);
int	negmax();
int	my_power_rec(int nb, int power);
int	my_isneg(int n);
int	my_find_prime_sup(int nb);
int	my_getnbr(char *str);
int	my_is_prime(int nombre);
void	my_putchar(char c);
int	my_putstr(char *str);
int	my_showmen(char *str, int size);
void	my_sort_int_tab(int *tab, int size);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_strcmp(char *s1, char *s2);
int	my_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_isupper(char *str);
char	*my_strlowcase(char *str);
int	my_strncmp(char *s1, char *s2, int n);
int	*my_strstr(char *str, char *to_find);
int	my_strlenb(char *str);
char	ascii(char *str);
char	add2(int detention, int lenb, char *result);
char	add(char *result, char **av, int leni, int lena);
char	cal1(char *result, char **av, int leni, int lena);
char	cal2(char *result, char **av, int leni, int lena);
char	print(char *result, int lenb);
char	sub(char *result, char **av, int leni, int lena);
char	sub1(char *result, char **av, int leni, int lena);
char	sub2(char *result, char **av, int leni, int lena);
