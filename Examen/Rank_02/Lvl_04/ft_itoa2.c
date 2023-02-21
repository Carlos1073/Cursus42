#include <stdlib.h>

int	ft_len_num(long n)
{
	int len = 0;

	while(n > 0)
	{
		n/= 10;
		len++;
	}
	return(len);
}

char	*ft_itoa(int nbr)
{
	char *res;
	long num = nbr;
	int len = 0;
	int neg = 0;
	
	if (num == 0)
		len = 1;
	else if(num < 0)
	{
		len++;
		num *= -1;
		neg = 1;
	}
	len += ft_len_num(num);
	res = (char*)malloc((len + 1) * sizeof(char));
	if(neg)
		res[0] = '-';
	if(num == 0)
		res[0] = '0';
	len-= 1;
	while(num > 0)
	{
		res[len] = (num % 10) + '0';
		num/= 10;
		len--;	
	}
	return(res);
}
