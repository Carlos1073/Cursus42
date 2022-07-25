/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:50:44 by caguerre          #+#    #+#             */
/*   Updated: 2022/07/21 16:57:41 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int				len;
	unsigned char	i;
	char			res;

	len = 8;
	i = 1;
	while (len-- > 0)
	{
		res = ((octet >> len) & i) + '0';
		write(1, &res, 1);
	}
}

int     main(void)
{
        print_bits(0);
        write(1, "\n", 1);
        print_bits(1);
        write(1, "\n", 1);
        print_bits(52);
        write(1, "\n", 1);
        print_bits(200);
        write(1, "\n", 1);

}
