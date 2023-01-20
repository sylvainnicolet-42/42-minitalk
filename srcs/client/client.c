/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:45:45 by synicole          #+#    #+#             */
/*   Updated: 2023/01/17 15:45:49 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"

/**
 * TODO
*/
static void	char_to_bin(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & 128)
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_printf("Error...\n");
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_printf("Error...\n");
		}
		c <<= 1;
		bit++;
		pause();
		usleep(100);
	}
}

/**
 * Send message.
 * Transform each char from string to binary.
 *
 * @param char *str
 * @param int pid
 *
 * @return void
*/
static void	ft_send_message(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
		char_to_bin(str[i++], pid);
	char_to_bin('\0', pid);
}

/**
 * Handle a signal.
 *
 * @param int signal
 * @param siginfo_t *info
 * @param void *context
 *
 * @return void
*/
static void	ft_signal_handler(int signal, siginfo_t *info, void *context)
{
	int	client_pid;

	(void) signal;
	(void) context;
	client_pid = info->si_pid;
	ft_printf("PID: [%d]\n", client_pid);
	ft_print_success("Server signal successfully received ✅ !");
}

/**
 * Listen signals SIGUSR1 & SIGUSR2.
 *
 * @param void
 *
 * @return void
*/
static void	ft_start_server(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

/**
 * 1. Check if there is 3 arguments.
 * 2. Convert PID to int.
 * 3. Start server to receive signal from server
 * 4. Send message to desired process
 * 5. Wait a reply from server
 *
 * @param int argc
 * @param char **argv
 *
 * @return int
*/
int	main(int argc, char **argv)
{
	int	server_pid;

	if (argc == 3)
	{
		ft_start_server();
		server_pid = ft_atoi(argv[1]);
		ft_send_message(argv[2], server_pid);
		if (!sleep(10))
			ft_print_error("Server signal was not received ❌ !");
	}
	else
		ft_print_error("Usage : ./client [pid] [message]");
	return (EXIT_FAILURE);
}
