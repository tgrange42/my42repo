#include <sys/ioctl.h>
#include <stdio.h>
#include "Libft/libft.h"

int main (int argc, char **argv)
{
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    printf ("lines %d\n", w.ws_row);
    printf ("columns %d\n", w.ws_col);
    ft_print_char(argv[1][0], w.ws_col + 1);
    ft_putbegl("i\t|\n");
    ft_putendl("123456789");
    ft_putnbr(ft_strlen("\t"));
    return 0;
}
