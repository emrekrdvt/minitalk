/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:26:50 by a          #+#    #+#             */
/*   Updated: 2022/06/13 14:27:26 by a         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	nb;

	sign = 1;
	i = 0;
	nb = 0;
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}	
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + str[i++] - 48;
		if (nb > 2147483648 && sign == -1)
			return (0);
		if (nb > 2147483647 && sign == 1)
			return (-1);
	}	
	return ((int)nb * sign);
}
