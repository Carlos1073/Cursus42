/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:50:22 by caguerre          #+#    #+#             */
/*   Updated: 2023/01/17 16:05:50 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_nbrlen(long long nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr)
	{
			nbr /= 10;
			len++;
	}
	return (len);
}

long long	ft_absval(long long n)
{
	if (n < 0)
		n = -n;
	return (n);
}

char	*ft_itoa(int nbr)
{
	char	*res;
	int		len;

	len = ft_nbrlen(nbr);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nbr < 0)
		res[0] = '-';
	else if (nbr == 0)
		res[0] = '0';
	while (nbr)
	{
		--len;
		res[len] = ft_absval(nbr % 10) + '0';
		nbr /= 10;
	}
	return (res);
}


// #include <unistd.h>
// #include <stdlib.h>

// void	ft_itoa_build(long int nbr, int *steps, char **str)
// {
// 	if (nbr < 10)
// 	{
// 		*str = (char *)malloc(sizeof(char) * (steps[0] + 2));
// 		(*str)[steps[0] + 1] = '\0';
// 		if (steps[1] == 1)
// 		{
// 			(*str)[steps[1]] = (nbr % 10) + '0';
// 			steps[1] += 1;
// 			return ;
// 		}
// 	}
// 	steps[0]++;
// 	ft_itoa_build(nbr / 10, steps, str);
// 	(*str)[steps[1]] = (nbr % 10) + '0';
// 	steps[1]++;
// }

// char	*ft_itoa(int nbr)
// {
// 	char	*str;
// 	int		step_ind[2];

// 	step_ind[0] = 0;
// 	step_ind[1] = 0;
// 	str = NULL;
// 	if (nbr < 0)
// 	{
// 		step_ind[0] = 1;
// 		step_ind[1] = 1;
// 		ft_itoa_build((long int)(nbr * -1), &step_ind[0], &str);
// 	}
// 	else
// 		ft_itoa_build((long int)nbr, &step_ind[0], &str);
// 	return (str);
// }
