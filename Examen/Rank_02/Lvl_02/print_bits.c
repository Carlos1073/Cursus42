/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:50:44 by caguerre          #+#    #+#             */
/*   Updated: 2022/09/21 15:08:08 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	i;

	i = 128;
	while (i > 0)
	{
		if (i & octet)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i >>= 1;
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
