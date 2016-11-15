#include <unistd.h>

void	ft_putnbr_base(int nb, char *base);

int	ft_isprint(int c)
{
	if (c > 31 && c < 256)
		return (1);
	return (0);
}

void	ft_putchar(char c)
{
	if (ft_isprint(c))
		write(1, &c, 1);
	else
	{
		ft_putchar('\\');
		ft_putnbr_base((int)c, "0123456789ABCDEF");
	}
}
