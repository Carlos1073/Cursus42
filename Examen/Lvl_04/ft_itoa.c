/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:50:22 by caguerre          #+#    #+#             */
/*   Updated: 2022/09/28 14:57:58 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void    ft_itoa_build(long int nbr, int *steps, char **str)
{
    if (nbr < 10)
    {
        *str = (char*)malloc(sizeof(char) * (steps[0] + 2));
        (*str)[steps[0] + 1] = '\0';
        if (steps[1] == 1)
        {
            (*str)[steps[1]] = (nbr % 10) + '0';
            steps[1] += 1;
            return ;
        }
    }
    steps[0]++;
    ft_itoa_build(nbr / 10, steps, str);
    (*str)[steps[1]] = (nbr % 10) + '0';
    steps[1]++;
}

char    *ft_itoa(int nbr)
{
    char    *str;
    int     step_ind[2];

    step_ind[0] = 0;
    step_ind[1] = 0;
    str = NULL;
    if (nbr < 0)
    {
        step_ind[0] = 1;
        step_ind[1] = 1;
        ft_itoa_build((long int)(nbr * -1), &step_ind[0], &str);
    }
    else
        ft_itoa_build((long int)nbr, &step_ind[0], &str);
    return (str);
}