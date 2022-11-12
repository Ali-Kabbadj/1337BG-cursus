
#include <unistd.h>

int ft_putpercent(void)
{
    write(1, "%", 1);
    return (1);
}