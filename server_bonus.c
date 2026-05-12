/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 00:02:10 by kaichan           #+#    #+#             */
/*   Updated: 2026/05/13 00:03:00 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void putchar(int n)
{
	char c;

	if(n >= 10)
		putchar(n/10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

void handler(int sig)
{
	static int bit = 0; //used to count bits
	static char c = 0; //used to write character
	
	// if(sig == SIGUSR1)
	// 	c = c | (0 << bit); unnecessary cause 0 is 0. and bit will just increment.
	if(sig == SIGUSR2)
		c = c | (1 << bit); //modifies the c cahracter by bits then prints it later
	
	bit++;

	if(bit == 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int main()
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask); // nothing is blocked you ass it with sigaddset(&sa.sa_mask, SIGUSR1);
	sa.sa_flags = 0;
	
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	
	write(1, "PID: ", 5);
	putchar(getpid());
	write(1, "\n", 1);

	while(1)
		pause();
	
	return(0);
}