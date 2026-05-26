/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 21:14:04 by kaichan           #+#    #+#             */
/*   Updated: 2026/05/27 00:35:11 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

// 1. modern Unix features switch also to defend against tunnel vision
# define _DEFAULT_SOURCE
# ifndef _POSIX_C_SOURCE
#  define _POSIX_C_SOURCE 200809L
# endif

# include "Libft/libft.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void	send_chars(char c, int pid);
void	handler(int sig, siginfo_t *info, void *context);

#endif
