/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 21:35:23 by kaichan           #+#    #+#             */
/*   Updated: 2026/05/27 01:37:05 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Notes: need to remeber need type in PID(where) message should go.
// pid need to read and send or confirm
//
// message needs to be broken down
// pid validation to reduce weird crashes or errors

#include "minitalk.h"

volatile sig_atomic_t	g_receiver = 0;

void	client_handler(int sig)
{
	if (sig == SIGUSR1)
		g_receiver = 1;
}

void	send_chars(char c, int pid)
{
	unsigned int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_receiver = 0;
		if (((c >> bit) & 1) == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (g_receiver == 0)
			usleep(50);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	c;
	int		pid;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) == -1)
		return (1);
	i = 0;
	signal(SIGUSR1, client_handler);
	while (argv[2][i] != '\0')
	{
		c = argv[2][i];
		send_chars(c, pid);
		i++;
	}
	c = '\0';
	send_chars(c, pid);
	return (0);
}
