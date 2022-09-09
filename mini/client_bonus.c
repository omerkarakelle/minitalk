/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okarakel <omerlutfu.k34@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:28:04 by okarakel          #+#    #+#             */
/*   Updated: 2022/03/09 13:54:03 by okarakel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void	final(int sig)
{
	if (sig == SIGUSR1)
		write(1, "Mesaj gonderildi.\n", 18);
}

int	ft_isdigit(int n)
{
	return (n >= '0' && n <= '9');
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	number;

	sign = 1;
	number = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		number = (number * 10) + (str[i] - 48) * sign;
		if (number > 2147483647)
			return (-1);
		if (number < -2147483648)
			return (0);
		i++;
	}
	return (number);
}

void	ft_sendbyte(unsigned char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c >= 128)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c << 1;
		i++;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;
	int		i;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	i = 0;
	signal(SIGUSR1, final);
	while (str[i])
		ft_sendbyte(str[i++], pid);
	ft_sendbyte(str[i], pid);
}
