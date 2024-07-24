/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cliente.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:02:19 by eda-mata          #+#    #+#             */
/*   Updated: 2024/07/22 13:06:15 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char	*str)
{
	int	i;
	int	valor;

	valor = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		valor = (valor * 10) + str[i] - '0';
		i++;
	}
	return (valor);
}

void	printbits(int sinal, unsigned char oct)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (oct & (1 << i))
			kill(sinal, SIGUSR1);
		else
			kill(sinal, SIGUSR2);
		usleep(10);
		i--;
	}
}

void	printstr(int sinal, char **str)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	while (str[i] != (void *)0)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			printbits(sinal, str[i][j]);
			j++;
		}
		i++;
	}
	printbits(sinal, '\n');
}

int	main(int argc, char **argv)
{
	int	sinal;

	if (argc == 3)
	{
		sinal = ft_atoi(argv[1]);
		printstr(sinal, argv);
	}
	write(1, "\n", 1);
}
