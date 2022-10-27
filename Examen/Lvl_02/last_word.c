/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:47:57 by caguerre          #+#    #+#             */
/*   Updated: 2022/09/21 12:54:42 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	last_word(char *str)
{
	int j;
	int i;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == ' ' || str[i] == '\t')  && str[i + 1] >= 33 && str[i + 1] <= 127)
			j = i + 1;
		i++;
	}
	while (str[j] >= 33 && str[j] <= 127)
	{
		write(1, &str[j], 1);
		j++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}
/*
int is_space(char c)
{
	if(c == ' ')
		return (1);
	if(c == '\t')
		return(1);
	return(0);
}

int main(int argc, char **argv)
{
	int start;
	int i;
	
	start = 0;
	i = 0;
	if (argc == 1)
		while(argv[1][i])
		{
			if(i > 0 && !is_space(argv[1][i] && is_space(argv[1][i - 1])))
			{
				start = i;
			}
			i++;
		}
		while(argv[1][start])
		{
			if(!is_space(argv[1][start] && argv[1][start] != '\0'))
			{
				write(1, &argv[1][start], 1);
			}
			else
				break;
			start++;
		}
	write(1, "\n", 1);
}
*/
