/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aa <aa@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:14:34 by aa          #+#    #+#             */
/*   Updated: 2022/08/08 13:39:44 by aa         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <libft.h>

void	handler(int num)
{
	static int	i = 0;

	if (num == SIGUSR1)
		i++;
	else if (num == SIGUSR2)
		ft_printf("%d", i);
}

void	charsend(char *av, int pid, int i)
{
	int	c;

	c = -1;
	while (av[++c])
	{
		i = 9;
		while (--i > 0)
		{
			if (av[c] & 128)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			av[c] <<= 1;
		}
	}
	if (av[c] == 0)
	{
		i = 8;
		while (--i >= 0)
		{
			kill(pid, SIGUSR2);
			usleep(100);
		}
	}
}

int	main(int ac, char **av)
{
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	if (ac == 3)
	{	
		if (ft_atoi(av[1]) == -1 || ft_atoi(av[1]) == -9)
		{
			ft_printf ("Nice try xd\nPID gir");
			return (0);
		}
		else
			charsend(av[2], ft_atoi(av[1]), 0);
	}
	return (0);
}
