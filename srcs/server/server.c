/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:45:59 by synicole          #+#    #+#             */
/*   Updated: 2023/01/17 15:46:02 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"

static void	extended_action(char *c, int *received, int *client_pid, int *bit)
{
	ft_printf("%c", *c);
	if (*c == '\0')
	{
		*received = 0;
		*c = 0;
		if (kill(*client_pid, SIGUSR1) == -1)
			ft_printf("Error...\n");
		return ;
	}
	*bit = 0;
}

/**
 * TODO Understand
 * Handle a signal.
 *
 * @param int signal
 */
static void	ft_signal_handler(int signal, siginfo_t *info, void *context)
{
	static int	client_pid;
	static int	bit;
	static char	c;
	static int	received;
	static int	current_pid;

	(void) context;
	if (!client_pid)
		client_pid = info->si_pid;
	current_pid = info->si_pid;
	if (client_pid != current_pid)
	{
		client_pid = current_pid;
		bit = 0;
		c = 0;
		received = 0;
	}
	c |= (signal == SIGUSR2);
	received++;
	bit++;
	if (bit == 8)
		extended_action(&c, &received, &client_pid, &bit);
	c <<= 1;
	usleep(100);
	kill(client_pid, SIGUSR2);
}

/**
 * Listen signals SIGUSR1 & SIGUSR2.
 *
 * SIGUSR1 (30): Defines bit 0
 * SIGUSR2 (31): Defines bit 1
*/
static void	ft_start_server(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
}

/**
 * TODO Understand while
*/
int	main(void)
{
	ft_printf("PID: [%d]\n", getpid());
	ft_start_server();
	return (EXIT_FAILURE);
}
