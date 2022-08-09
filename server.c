/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aa <aa@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:24:17 by aa          #+#    #+#             */
/*   Updated: 2022/08/02 17:18:09 by aa         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <libft.h>

void	ret(siginfo_t *info, int i)
{
	if (i == 0)
		kill(info->si_pid, SIGUSR2);
	else
	{
		kill(info->si_pid, SIGUSR1);
		write(1, &i, 1);
	}
}

void	signl(int sign, siginfo_t *info, void *context)
{
	static char	i = 0;
	static int	j = 0;

	(void) context;
	if (sign == SIGUSR1)
	{
		i <<= 1;
		i |= 1;
		j++;
	}
	else if (sign == SIGUSR2)
	{
		i <<= 1;
		j++;
	}
	if (j == 8)
	{
		ret(info, i);
		i = 0;
		j = 0;
	}
}

int	main(void)
{
	struct sigaction	s_sig;
	int					pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	s_sig.sa_sigaction = signl;
	s_sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sig, 0);
	sigaction(SIGUSR2, &s_sig, 0);
	while (1)
	{
	}
	return (0);
}
