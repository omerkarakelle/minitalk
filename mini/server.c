/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okarakel <omerlutfu.k34@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:16:20 by okarakel          #+#    #+#             */
/*   Updated: 2022/03/05 19:42:53 by okarakel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	ft_putnbr(int n)
{
	char	c;

	if (n > 9)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	ft_receive(int sig)
{
	static int				i;
	static unsigned char	c;

	c = c << 1;
	if (sig == SIGUSR1)
		c++;
	if (i == 7)
	{
		if (c == 0)
			write(1, "\n", 1);
		write(1, &c, 1);
		i = -1;
	}
	i++;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	if (pid == -1)
		return (0);
	ft_putnbr(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, ft_receive);
	signal(SIGUSR2, ft_receive);
	while (1)
		pause();
	return (0);
}
