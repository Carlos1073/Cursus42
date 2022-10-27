#include <unistd.h>
#include <stdio.h>

void ft_write_num(int num)
{
    char    str[10] = "0123456789";

    if (num > 9)
        ft_write_num(num / 10);
    write(1, &str[num % 10], 1);
}

int main(void)
{
    int num;

    num = 1;
    while (num <= 100)
    {
        if ((num % 3 == 0) && (num % 5 == 0))
            write(1, "fizzbuzz", 8);
        else if (num % 3 == 0)
            write(1, "fizz", 4);
        else if (num % 5 == 0)
            write(1, "buzz", 4);
        else
            ft_write_num(num);
        num++;
        write(1, "\n", 1);
    }
}