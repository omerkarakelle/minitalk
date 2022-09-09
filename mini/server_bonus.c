/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okarakel <omerlutfu.k34@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:16:20 by okarakel          #+#    #+#             */
/*   Updated: 2022/03/09 13:53:46 by okarakel         ###   ########.fr       */
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

void	ft_receive(int sig, siginfo_t *info, void *content)
{
	static int				i;
	static pid_t			client_id = 0;
	static unsigned char	c;

	c = c << 1;
	(void)content;
	if (client_id == 0)
		client_id = info->si_pid;
	if (sig == SIGUSR1)
		c++;
	if (i == 7)
	{
		if (c == 0)
		{
			kill(client_id, SIGUSR1);
			client_id = 0;
			write(1, "\n", 1);
		}
		write(1, &c, 1);
		i = -1;
	}
	i++;
}

int	main(void)
{
	int					pid;
	struct sigaction	client;

	client.sa_sigaction = ft_receive;
	client.sa_flags = SA_SIGINFO;
	pid = getpid();
	if (pid == -1)
		return (0);
	ft_putnbr(pid);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &client, 0);
	sigaction(SIGUSR2, &client, 0);
	while (1)
		pause();
	return (0);
}
