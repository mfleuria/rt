#include "libft.h"
/*
int     ft_putfnbr(float f)
{
  int   output;

  output = 0;
  if (f == -2147483648)
    {
      output = output + ft_putstr("-2147483648");
      return;
    }
  if (f < 0)
    {
      f = -f;
      ft_putchar('-');
      output = output + 1;
    }
  if (f > 9)
    output = output + ft_putnbr(f / 10);
  output = output + ft_putchar(f % 10 + 48);
  return (output);
}
*/
int     ft_putfnbr(float f)
{
    int     ret;
    int     intpart;
    int     i;

    ret = 0;
    i = 0;
    intpart = (int)f;
    ft_putnbr(intpart);
    ret = ft_strlen(ft_itoa(intpart));
    write(1, ".", 1);
    while (i++ < 7)
    {
        f *= 10;
        ft_putchar(48 + ((int)f % 10));
    }
    return (ret);
}