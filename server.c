/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 17:15:09 by kaichan           #+#    #+#             */
/*   Updated: 2026/05/13 22:22:37 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}
// used to count bits
// used to write character
// if(sig == SIGUSR1)
// 	c = c | (0 << bit); vunnecessary cause 0 is 0. and bit will just increment.
// modifies the c cahracter by bits then prints it later

void	handler(int sig)
{
	static int				bit = 0;
	static unsigned char	c = 0;

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
}
// nothing is blocked you mask it with sigaddset(&sa.sa_mask, SIGUSR1);

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
