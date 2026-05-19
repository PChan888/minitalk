/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 00:02:52 by kaichan           #+#    #+#             */
/*   Updated: 2026/05/13 22:25:12 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Notes: need to remeber need type in PID(where) message should go.
// pid need to read and send or confirm
//
// message needs to be broken down

#include "minitalk.h"

void	send_chars(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (((c >> bit) & 1) == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
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
	i = 0;
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
