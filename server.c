/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servidor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:46:30 by eda-mata          #+#    #+#             */
/*   Updated: 2024/07/22 12:49:01 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr < 10)
	{
		c = nbr + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

void	sinal(int oct)
{
	static unsigned char	j;
	static int				i;

	if (oct == SIGUSR1)
		j = (j << 1) | (1 & 1);
	else
		j = (j << 1) | (0 & 0);
	i++;
	if (i == 8)
	{
		write(1, &j, 1);
		i = 0;
	}
}

void	processo(void)
{
	signal(SIGUSR1, &sinal);
	signal(SIGUSR2, &sinal);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	write(1, "servidor PID: ", 14);
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
	{
		processo();
	}
}
