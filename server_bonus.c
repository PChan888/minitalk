/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 02:53:37 by kaichan           #+#    #+#             */
/*   Updated: 2026/05/28 03:24:33 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// void	ft_putnbr(int n)
// {
// 	char	c;

// 	if (n >= 10)
// 		ft_putnbr(n / 10);
// 	c = (n % 10) + '0';
// 	write(1, &c, 1);
// }
// used to count bits
// used to write character
// if(sig == SIGUSR1)
// 	c = c | (0 << bit); vunnecessary cause 0 is 0. and bit will just increment.
// modifies the c cahracter by bits then prints it later

void	handler(int sig, siginfo_t *info, void *context)
{
	static int				bit = 0;
	static unsigned char	c = 0;

	(void)context;
	if (sig == SIGUSR2)
		c = c | (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		bit = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}
// nothing is blocked you mask it with sigaddset(&sa.sa_mask, SIGUSR1);

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write(1, "PID: ", 5);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
